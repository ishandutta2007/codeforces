#include <stdio.h>

int main()
{
    int n, k, i;
    
    scanf("%d %d", &n, &k);
    
    if (k >= n * (n - 1) / 2) {
        puts("no solution");
    } else {
        for (i = 0; i < n; i++) printf("0 %d\n", i);
    }
    
    return 0;
}