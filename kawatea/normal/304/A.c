#include <stdio.h>
#include <math.h>

int main()
{
    int n, sum = 0, i, j;
    
    scanf("%d", &n);
    
    for (i = 1; i * i * 2 <= n * n; i++) {
        for (j = i; j <= n && i * i + j * j <= n * n; j++) {
            int c = i * i + j * j;
            int x = sqrt(c);
            
            if (x * x == c) sum++;
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}