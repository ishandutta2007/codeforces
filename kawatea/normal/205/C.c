#include <stdio.h>

long long calc(long long x)
{
    int n = 0, c = 0, i, j;
    long long p = x, sum = 0, tmp;
    
    while (p) {
        c = p % 10;
        p /= 10;
        
        n++;
    }
    
    if (n <= 1) return x;
    
    for (i = 0; i < n - 1; i++) {
        tmp = 9;
        
        for (j = 0; j < i - 1; j++) tmp *= 10;
        
        sum += tmp;
    }
    
    for (i = 1; i < c; i++) {
        tmp = 1;
        
        for (j = 0; j < n - 2; j++) tmp *= 10;
        
        sum += tmp;
    }
    
    tmp = 1;
    
    for (i = 0; i < n - 1; i++) tmp *= 10;
    
    x %= tmp;
    
    sum += x / 10;
    
    if (x % 10 >= c) sum++;
    
    return sum;
}

int main()
{
    long long l, r;
    
    scanf("%I64d %I64d", &l, &r);
    
    printf("%I64d\n", calc(r) - calc(l - 1));
    
    return 0;
}