#include <stdio.h>

long long mod_pow(long long x, long long y, long long m)
{
    long long z = 1;
    
    while (y) {
        if (y & 1) z = z * x % m;
        
        x = x * x % m;
        y >>= 1;
    }
    
    return z;
}

int main()
{
    int n, m, k, x, mod = 1000000009;
    
    scanf("%d %d %d", &n, &m, &k);
    
    x = m - n / k * (k - 1) - n % k;
    
    if (x <= 0) {
        printf("%d\n", m);
    } else {
        long long ans = mod_pow(2, x, mod);
        
        ans = (ans - 1 + mod) % mod;
        ans = ans * 2 % mod * k % mod;
        
        ans = (ans + m - x * k) % mod;
        
        printf("%d\n", (int)ans);
    }
    
    return 0;
}