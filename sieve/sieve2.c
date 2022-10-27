#include <gigatron/libc.h>
#include <gigatron/sys.h>
#include <stdlib.h>
#include <string.h>
#define TIMER 0
#define MODE 4

/** This is a more substantial modification of the sieve program.
    Besides the sieve1 modifications, sieve2 uses memset to clear the flag array
    and the sieve loop has been moved into its own leaf function. **/

#define true 1
#define false 0
#define size 8190
#define sizepl 8191

char flags[sizepl];

int sieve() {
    int i, prime, k, count;
    count=0 ; 
    for (i = 0; i != size; i++) { 
        if (flags[i]) {
            prime = i + i + 3; 
            k = prime + i; 
            while (size - k >= 0) { 
                flags[k] = false; 
                k += prime; 
            }
            count = count + 1;
        }
    }
    return count;
}

int main() {
    int iter, count;
    #if TIMER
    unsigned int ticks = 0;
    #endif
    printf("10 iterations\n\n");
#ifdef MODE
# if MODE == 4
    videoTop_v5 = 238;
# else
    SYS_SetMode(MODE);
# endif
#endif
    #if TIMER
    frameCount = 0;
    #endif
    for (iter = 1; iter <= 10; iter ++) {
        memset(flags, 1, sizepl);
        count = sieve();
        #if TIMER
        ticks += frameCount;
        frameCount = 0;
        #endif
    }
#ifdef MODE
# if MODE == 4
    videoTop_v5 = 0;
# else
    SYS_SetMode(-1);
# endif
#endif
    printf("%d primes\n", count);
    #if TIMER
    printf("%d %d/60 seconds\n", ticks/60, ticks%60);
    #endif
    return 0;
}


/* Local Variables: */
/* mode: c */
/* c-basic-offset: 4 */
/* indent-tabs-mode: () */
/* End: */
