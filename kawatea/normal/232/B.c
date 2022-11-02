#include <stdio.h>

long long pow(long long x, long long y, long long z)
{
    long long p = 1;
    
    while (y) {
        if (y & 1) p = p * x % z;
        
        x = x * x % z;
        y >>= 1;
    }
    
    return p;
}

int max(int a, int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

long long c[101][101];
long long a[101];
long long dp[101][10001];

int main()
{
    int n, k, mod = 1000000007, i, j, l;
    long long m;
    
    scanf("%d %I64d %d", &n, &m, &k);
    
    for (i = 0; i <= 100; i++) {
        c[i][0] = c[i][i] = 1;
        
        for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    
    for (i = 0; i <= n; i++) a[i] = pow(c[n][i], m / n, mod);
    
    dp[0][0] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = max(0, k - (n - i) * n); j <= i * n && j <= k; j++) {
            if (dp[i][j] == 0) continue;
            
            for (l = 0; l <= n && j + l <= k; l++) {
                long long x = a[l];
                
                if (m % n > i) x = x * c[n][l] % mod;
                
                dp[i + 1][j + l] = (dp[i + 1][j + l] + dp[i][j] * x % mod) % mod;
            }
        }
    }
    
    printf("%I64d\n", dp[n][k]);
    
    return 0;
}