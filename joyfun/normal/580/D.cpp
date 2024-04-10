#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;
const int INF = 0x3f3f3f3f;

int n, m, k;
int a[N], g[N][N];
long long dp[1<<N][N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    while (k--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--; v--;
        g[u][v] = w;
    }
    long long ans = 0;
    for (int i = 0; i < (1<<n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -INF;
    for (int i = 0; i < n; i++)
        dp[1<<i][i] = a[i];
    for (int i = 1; i < (1<<n); i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) if(i&(1<<j)) cnt++;
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) {
                for (int k = 0; k < n; k++) {
                    if (i&(1<<k)) {
                        dp[i][j] = max(dp[i][j], dp[i^(1<<j)][k] + g[k][j] + a[j]);
                    }
                }
           //     printf("%d %d %d\n", i, j, dp[i][j]);
                if (cnt <= m) ans = max(ans, dp[i][j]);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}