#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int dp[1<<8][1005];
int n, a[1005], s[8][1005];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]); a[i]--;
        for (int j = 0; j < 8; j++) s[j][i] = s[j][i - 1];
        s[a[i]][i]++;
    }
    int l = 0, r = n;
    int ans = 0;
    while (l < r) {
        int mid = (l + r)>>1;
        for (int i = 0; i < (1<<8); i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = -INF;
        dp[0][0] = 0;
        for (int i = 0; i < (1<<8); i++) {
            for (int j = 0; j <= n; j++) {
                if (dp[i][j] == -INF) continue;
                for (int k = 0; k < 8; k++) {
                    if (i>>k&1) continue;
                    for (int f = 0; f < 2; f++) {
                        int v = lower_bound(s[k] + j, s[k] + 1 + n, s[k][j] + mid + f) - s[k];
                        if (v == n + 1) continue;
                        dp[i^(1<<k)][v] = max(dp[i^(1<<k)][v], dp[i][j] + mid + f);
                    }
                }
            }
        }
        int Max = -INF;
        for (int j = 1; j <= n; j++) Max = max(Max, dp[(1<<8) - 1][j]);
        if (Max != -INF) {
            l = mid + 1;
            ans = max(ans, Max);
        }
        else r = mid;
    }
    printf("%d\n", ans);
    return 0;
}