#include <cstdio>
#include <algorithm>

using namespace std;

char s[3000][3001];
int dp[3000][3000][2];

int main()
{
    int n, m, mod = 1000000007, i, j, k;
    long long ans;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    if (s[0][1] != '#') dp[0][1][0] = 1;
    if (s[1][0] != '#') dp[1][0][1] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < 2; k++) {
                if (dp[i][j][k] > 0) {
                    if (i + 1 < n && s[i + 1][j] != '#') dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % mod;
                    if (j + 1 < m && s[i][j + 1] != '#') dp[i][j + 1][k] = (dp[i][j + 1][k] + dp[i][j][k]) % mod;
                }
            }
        }
    }
    
    ans = ((long long)dp[n - 2][m - 1][0] * dp[n - 1][m - 2][1] - (long long)dp[n - 1][m - 2][0] * dp[n - 2][m - 1][1]) % mod;
    
    if (ans < 0) ans += mod;
    
    printf("%d\n", (int)ans);
    
    return 0;
}