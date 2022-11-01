// write in C...
#include <stdio.h>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

int main() {
    int n;
    scanf("%d", &n);
    if (n&1) printf("-1\n");
    else {
        int i, j, k;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++)
                    if ((i ^ (j/2) ^ (k/2)) & 1)
                        printf("w");
                    else
                        printf("b");
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}