#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 105;
int n, a[N], dp[N][3];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++)
        for (int j =0; j < 3; j++)
            dp[i][j] = INF;
    dp[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            dp[i][2] = min(dp[i][2], dp[i - 1][j] + 1);
        if (a[i] == 1 || a[i] == 3) {
            dp[i][1] = min(dp[i][1], dp[i - 1][2]);
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
        }
        if (a[i] == 2 || a[i] == 3) {
            dp[i][0] = min(dp[i][0], dp[i - 1][2]);
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
    }
    int ans = INF;
    for (int i = 0; i < 3; i++) ans = min(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}