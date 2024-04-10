#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[5001][5001];
long long sum[5001];

int main()
{
    int n, a, b, k, m = 1000000007, ans = 0, i, j;
    
    scanf("%d %d %d %d", &n, &a, &b, &k);
    
    a--;
    b--;
    
    dp[0][a] = 1;
    
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            int x;
            
            if (dp[i][j] == 0) continue;
            
            x = abs(j - b) - 1;
            
            if (x == 0) continue;
            
            sum[max(0, j - x)] += dp[i][j];
            if (j + x + 1 < n) sum[j + x + 1] -= dp[i][j];
            dp[i + 1][j] -= dp[i][j];
        }
        
        for (j = 1; j < n; j++) sum[j] += sum[j - 1];
        
        for (j = 0; j < n; j++) {
            dp[i + 1][j] += sum[j];
            dp[i + 1][j] %= m;
            if (dp[i + 1][j] < 0) dp[i + 1][j] += m;
            sum[j] = 0;
        }
    }
    
    for (i = 0; i < n; i++) {
        ans += dp[k][i];
        if (ans >= m) ans -= m;
    }
    
    printf("%d\n", ans);
    
    return 0;
}