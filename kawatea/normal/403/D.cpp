#include <cstdio>

using namespace std;

long long inv[1001];
long long fact[1001];
long long invfact[1001];
long long sum[1001][1001];

int main()
{
    int t, m = 1000000007, i, j;
    
    inv[1] = 1;
    for (i = 2; i <= 1000; i++) inv[i] = inv[m % i] * (m - m / i) % m;
    
    fact[0] = invfact[0] = 1;
    for (i = 1; i <= 1000; i++) fact[i] = fact[i - 1] * i % m;
    for (i = 1; i <= 1000; i++) invfact[i] = invfact[i - 1] * inv[i] % m;
    
    sum[1][0] = 1;
    
    for (i = 1; i <= 1000; i++) {
        for (j = 0; j <= 1000; j++) {
            if (sum[i][j] == 0) continue;
            
            if (i + j <= 1000) sum[i][i + j] = (sum[i][i + j] + sum[i][j]) % m;
            if (i < 1000) sum[i + 1][j] = (sum[i + 1][j] + sum[i][j]) % m;
        }
    }
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, k, x;
        long long ans = 0;
        
        scanf("%d %d", &n, &k);
        
        x = n - (k * (k - 1) / 2 + (k - 1)) - 1;
        
        if (x < 0) {
            puts("0");
        } else {
            for (j = 0; j <= x; j++) {
                ans = (ans + sum[k][j] * fact[k + x - j] % m * invfact[x - j] % m) % m;
            }
            
            printf("%I64d\n", ans);
        }
    }
    
    return 0;
}