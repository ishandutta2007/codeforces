#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 205;
const int M = 1005;
const int MOD = 1000000007;

int n, m, a[N];
int dp[2][N][M];

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int now = 0, pre = 1;
    dp[now][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        swap(now, pre);
        memset(dp[now], 0, sizeof(dp[now]));
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= m; k++) {
                int kk = (a[i] - a[i - 1]) * j + k;
                if (kk > m) continue;
                add(dp[now][j][kk], 1LL * dp[pre][j][k] * (j + 1) % MOD);
                if (j + 1 <= n) add(dp[now][j + 1][kk], dp[pre][j][k]);
                if (j) add(dp[now][j - 1][kk], 1LL * dp[pre][j][k] * j % MOD);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) add(ans, dp[now][0][i]);
    printf("%d\n", ans);
    return 0;
}