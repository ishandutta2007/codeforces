#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

const int mxn = 5005;

int n, K, X;
int a[mxn];
i64 dp[mxn][mxn];
int que[mxn][mxn], ql[mxn], qr[mxn];

int main() {
    scanf("%d %d %d", &n, &K, &X);
    rep(i, n) scanf("%d", &a[i]);
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    rep(i, n) {
        for (int j = 0; j <= X; ++ j) {
            while (ql[j] < qr[j] && dp[que[j][qr[j] - 1]][j] < dp[i][j]) -- qr[j];
            que[j][qr[j] ++] = i;
            while (ql[j] < qr[j] && que[j][ql[j]] < i - K + 1) ++ ql[j];
        }
        for (int j = 1; j <= X; ++ j) {
            dp[i + 1][j] = dp[que[j - 1][ql[j - 1]]][j - 1] + a[i];
        }
    }
    i64 ans = -(1LL << 60);
    for (int i = n - K + 1; i <= n; ++ i) ans = std::max(ans, dp[i][X]);
    if (ans < 0) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}