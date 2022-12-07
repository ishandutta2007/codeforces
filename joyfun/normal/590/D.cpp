#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 155;
const int INF = 0x3f3f3f3f;

int n, k, s, q[N];

int dp[2][N][N * N / 2];

int main() {
    scanf("%d%d%d", &n, &k, &s);
    for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
    if (s >= n * (n - 1) / 2) {
        sort(q + 1, q + 1 + n);
        int sum = 0;
        for (int i = 1; i <= k; i++) sum += q[i];
        printf("%d\n", sum);
        return 0;
    }
    int now = 0, pre = 1;
    for (int j = 0; j <= k; j++) {
        for (int x = 0; x <= s; x++) {
            dp[now][j][x] = INF;
        }
    }
    dp[now][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        swap(now, pre);
        for (int j = 0; j <= k; j++) {
            for (int x = 0; x <= s; x++) {
                dp[now][j][x] = INF;
            }
        }
        for (int j = 0; j < i; j++) {
            for (int x = 0; x <= s; x++) {
                if (x + (i - j - 1) <= s) dp[now][j + 1][x + (i - j - 1)] = min(dp[now][j + 1][x + (i - j - 1)], dp[pre][j][x] + q[i]);
                dp[now][j][x] = min(dp[now][j][x], dp[pre][j][x]);
            }
        }
        /*for (int j = 0; j <= i; j++) {
            for (int x = 0; x <= s; x++) {
                printf("%d %d %d %d\n", i, j, x, dp[now][j][x]);
            }
        }*/
    }
    int ans = INF;
    for (int i = 0; i <= s; i++) {
        ans = min(ans, dp[now][k][i]);
    }
    printf("%d\n", ans);
    return 0;
}