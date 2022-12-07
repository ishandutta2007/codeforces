#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;

int n;
double g[N][N];
double dp[1<<N][N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &g[i][j]);
        }
    }
    dp[1][0] = 1.0;
    for (int i = 2; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) {
            if (i&(1<<j))
            for (int k = 0; k < n; k++) {
                if (i&(1<<k) && k != j)
                    dp[i][j] = max(dp[i][j], dp[i^(1<<k)][j] * g[j][k] + dp[i^(1<<j)][k] * g[k][j]);
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[(1<<n) - 1][i]);
    printf("%.12f\n", ans);
    return 0;
}