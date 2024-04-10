#include <cstdio>

using namespace std;

int a[5000][2];
double b[5000];
double d[101][5001];
double sum[101][5001];
double dp[5001][5001];

int main()
{
    int n, t, i, j, k;
    double ans = 0;
    
    scanf("%d %d", &n, &t);
    
    for (i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    
    for (i = 0; i < n; i++) b[i] = a[i][0] / 100.0;
    
    for (i = 0; i <= 100; i++) {
        d[i][0] = 1;
        
        for (j = 1; j <= 5000; j++) {
            d[i][j] = d[i][j - 1] * (100 - i) / 100.0;
            sum[i][j] = sum[i][j - 1] + d[i][j - 1] * i / 100.0;
        }
    }
    
    dp[0][0] = 1;
    
    for (i = 0; i < n; i++) {
        if (a[i][0] == 100 || a[i][1] == 1) {
            for (j = 0; j < t; j++) {
                dp[i + 1][j + 1] = dp[i][j];
                ans += dp[i][j];
            }
            
            continue;
        }
        
        for (j = 0; j < t; j++) {
            if (dp[i][j] < 1e-10) continue;
            
            dp[i + 1][j + 1] += dp[i][j] * b[i];
            
            if (j + a[i][1] <= t) dp[i + 1][j + a[i][1]] += dp[i][j] * d[a[i][0]][a[i][1]];
            if (j + a[i][1] < t) dp[i + 1][j + a[i][1] + 1] -= dp[i][j] * (1 - sum[a[i][0]][a[i][1]]);
            
            if (j + a[i][1] <= t) {
                ans += dp[i][j];
            } else {
                ans += dp[i][j] * (1 - d[a[i][0]][t - j]);
            }
        }
        
        for (j = 1; j <= t; j++) dp[i + 1][j] += dp[i + 1][j - 1] * (1 - b[i]);
    }
    
    printf("%lf\n", ans);
    
    return 0;
}