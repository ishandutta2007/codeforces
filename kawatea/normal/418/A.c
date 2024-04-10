#include <stdio.h>

int main()
{
    int n, k, i, j;
    
    scanf("%d %d", &n, &k);
    
    if (k * 2 >= n) {
        puts("-1");
        
        return 0;
    }
    
    printf("%d\n", n * k);
    
    for (i = 0; i < n; i++) {
        for (j = 1; j <= k; j++) {
            int x = i + 1;
            int y = (i + j) % n + 1;
            
            printf("%d %d\n", x, y);
        }
    }
    
    return 0;
}