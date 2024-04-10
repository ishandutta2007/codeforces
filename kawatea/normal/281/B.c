#include <stdio.h>

long long f(long long x)
{
    if (x < 0) return -x;
    
    return x;
}

int main()
{
    int x, y, n, p = -1, q, i;
    
    scanf("%d %d %d", &x, &y, &n);
    
    for (i = 1; i <= n; i++) {
        int z = (long long)x * i / y;
        
        if (p == -1 || f((long long)q * x - (long long)p * y) * i * y > f((long long)i * x - (long long)z * y) * q * y) {
            p = z;
            q = i;
        }
        
        z++;
        
        if (f((long long)q * x - (long long)p * y) * i * y > f((long long)i * x - (long long)z * y) * q * y) {
            p = z;
            q = i;
        }
    }
    
    printf("%d/%d\n", p, q);
    
    return 0;
}