#include <stdio.h>

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n, k, x = 1, i, j;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            if (j > 0) putchar(' ');
            
            printf("%d", min(x + j + 1, n));
        }
        
        puts("");
        
        x *= 2;
    }
    
    return 0;
}