#include <stdio.h>

int main()
{
    int k, b, n, t, i;
    long long x = 1;
    
    scanf("%d %d %d %d", &k, &b, &n, &t);
    
    for (i = 0; i < n; i++) {
        if (k * x + b > t) break;
        
        x = k * x + b;
    }
    
    printf("%d\n", n - i);
    
    return 0;
}