#include <cstdio>
#include <algorithm>

using namespace std;

int m = 1000000007;
int a[1000];
int dp[501][20001];
int sum[2][20001];

int dfs(int x, int y)
{
    int z, ans = 0, i, j, k;
    
    if (y <= x + 1) return 0;
    
    z = (x + y) / 2;
    
    for (i = 0; i <= 20000; i++) sum[0][i] = sum[1][i] = 0;
    
    for (i = 0; i <= z - x; i++) {
        for (j = 0; j <= 20000; j++) {
            dp[i][j] = 0;
        }
    }
    
    dp[0][10000] = 1;
    
    for (i = z - 1, j = 0; i >= x; i--, j++) {
        for (k = 0; k <= 20000; k++) {
            if (dp[j][k] > 0) {
                dp[j + 1][k + a[i]] += dp[j][k];
                if (dp[j + 1][k + a[i]] >= m) dp[j + 1][k + a[i]] -= m;
                dp[j + 1][k - a[i]] += dp[j][k];
                if (dp[j + 1][k - a[i]] >= m) dp[j + 1][k - a[i]] -= m;
            }
        }
    }
    
    for (i = 1; i <= z - x; i++) {
        for (j = 0; j <= 20000; j++) {
            sum[0][j] += dp[i][j];
            if (sum[0][j] >= m) sum[0][j] -= m;
        }
    }
    
    for (i = 0; i <= y - z; i++) {
        for (j = 0; j <= 20000; j++) {
            dp[i][j] = 0;
        }
    }
    
    dp[0][10000] = 1;
    
    for (i = z, j = 0; i < y; i++, j++) {
        for (k = 0; k <= 20000; k++) {
            if (dp[j][k] > 0) {
                dp[j + 1][k + a[i]] += dp[j][k];
                if (dp[j + 1][k + a[i]] >= m) dp[j + 1][k + a[i]] -= m;
                dp[j + 1][k - a[i]] += dp[j][k];
                if (dp[j + 1][k - a[i]] >= m) dp[j + 1][k - a[i]] -= m;
            }
        }
    }
    
    for (i = 1; i <= y - z; i++) {
        for (j = 0; j <= 20000; j++) {
            sum[1][j] += dp[i][j];
            if (sum[1][j] >= m) sum[1][j] -= m;
        }
    }
    
    for (i = 0; i <= 20000; i++) {
        ans += (long long)sum[0][i] * sum[1][20000 - i] % m;
        if (ans >= m) ans -= m;
    }
    
    ans += dfs(x, z);
    if (ans >= m) ans -= m;
    ans += dfs(z, y);
    if (ans >= m) ans -= m;
    
    return ans;
}

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    printf("%d\n", dfs(0, n));
    
    return 0;
}