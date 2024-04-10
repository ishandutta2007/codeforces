#include <bits/stdc++.h>

const int N = 5100;
const long long INF = 1e16;

int n, s, t, tot;
int a[N], b[N], c[N], d[N], x[N];

long long dp[N][N];

long long solve() {
    int tot = 0;
    long long ans = INF;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j)
            if (dp[i - 1][j] <= INF) {
                if (i == s) {
                    int S = j, T = tot + S;
                    if (T) dp[i][S] = std::min(dp[i][S], dp[i - 1][j] + x[i] + c[i]);
                    dp[i][S + 1] = std::min(dp[i][S + 1], dp[i - 1][j] - x[i] + d[i]);
                } else if (i == t) {
                    int S = j, T = tot + S;
                    if (S) dp[i][S - 1] = std::min(dp[i][S - 1], dp[i - 1][j] + x[i] + a[i]);
                    dp[i][S] = std::min(dp[i][S], dp[i - 1][j] - x[i] + b[i]);
                } else {
                    int S = j, T = tot + S;
                    if (S) dp[i][S] = std::min(dp[i][S], dp[i - 1][j] + a[i] + d[i]);
                    if (T) dp[i][S] = std::min(dp[i][S], dp[i - 1][j] + b[i] + c[i]);
                    if (T && S) dp[i][S - 1] = std::min(dp[i][S - 1], dp[i - 1][j] + x[i] * 2 + a[i] + c[i]);
                    dp[i][S + 1] = std::min(dp[i][S + 1], dp[i - 1][j] - x[i] * 2 + b[i] + d[i]);
                }
            }
        if (i == s) --tot;
        if (i == t) ++tot;
        if (i != n && tot == 0) dp[i][0] = INF + 1e9;
    }
    return dp[n][0];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> s >> t;
    for (int i = 1; i <= n; ++i) std::cin >> x[i];
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) std::cin >> b[i];
    for (int i = 1; i <= n; ++i) std::cin >> c[i];
    for (int i = 1; i <= n; ++i) std::cin >> d[i];
    std::cout << solve() << std::endl;
    return 0;
}