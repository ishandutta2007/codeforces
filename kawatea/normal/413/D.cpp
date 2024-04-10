#include <cstdio>

using namespace std;

int a[2000];
int b[2000];
long long c[2000];
long long dp[2001][1 << 11];

int main()
{
    int n, k, m = 1000000007, i, j;
    long long ans = 0;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = n - 2; i >= 0; i--) {
        if (a[i + 1] == 0) b[i]++;
        
        b[i] += b[i + 1];
    }
    
    c[0] = 1;
    
    for (i = 1; i < 2000; i++) c[i] = c[i - 1] * 2 % m;
    
    dp[0][0] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < (1 << k); j++) {
            if (dp[i][j] == 0) continue;
            
            if (a[i] == 0 || a[i] == 2) {
                if (j + 2 >= (1 << k)) {
                    ans = (ans + dp[i][j] * c[b[i]] % m) % m;
                } else {
                    dp[i + 1][j + 2] += dp[i][j];
                    if (dp[i + 1][j + 2] >= m) dp[i + 1][j + 2] -= m;
                }
            }
            
            if (a[i] == 0 || a[i] == 4) {
                if (j & 2) {
                    dp[i + 1][4] += dp[i][j];
                    if (dp[i + 1][4] >= m) dp[i + 1][4] -= m;
                } else if (j + 4 >= (1 << k)) {
                    ans = (ans + dp[i][j] * c[b[i]] % m) % m;
                } else {
                    dp[i + 1][j + 4] += dp[i][j];
                    if (dp[i + 1][j + 4] >= m) dp[i + 1][j + 4] -= m;
                }
            }
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}