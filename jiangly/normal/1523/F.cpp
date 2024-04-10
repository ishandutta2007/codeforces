#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int inf = 1e9 + 1;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> xa(n), ya(n);
    for (int i = 0; i < n; i++) {
        std::cin >> xa[i] >> ya[i];
    }
    std::vector<std::tuple<int, int, int>> b(m);
    for (int i = 0; i < m; i++) {
        int t, x, y;
        std::cin >> x >> y >> t;
        b[i] = {t, x, y};
    }
    std::sort(b.begin(), b.end());
    std::vector<int> xb(m), yb(m), t(m);
    for (int i = 0; i < m; i++) {
        std::tie(t[i], xb[i], yb[i]) = b[i];
    }
    std::vector disb(m, std::vector<int>(1 << n, inf));
    std::vector disa(n, std::vector<int>(1 << n, inf));
    for (int i = 0; i < m; i++) {
        for (int mask = 1; mask < (1 << n); mask++) {
            int u = __builtin_ctz(mask);
            disb[i][mask] = std::min(disb[i][mask ^ (1 << u)], std::abs(xa[u] - xb[i]) + std::abs(ya[u] - yb[i]));
        }
    }
    for (int i = 0; i < n; i++) {
        for (int mask = 1; mask < (1 << n); mask++) {
            int u = __builtin_ctz(mask);
            disa[i][mask] = std::min(disa[i][mask ^ (1 << u)], std::abs(xa[u] - xa[i]) + std::abs(ya[u] - ya[i]));
        }
    }
    std::vector f(1 << n, std::vector<int>(m + 1, -1));
    f[0][0] = 0;
    std::vector dp(1 << n, std::vector<int>(m, -1));
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (mask == 0) {
            for (int i = 0; i < m; i++) {
                dp[0][i] = std::max(dp[0][i], 1);
                ans = std::max(ans, dp[0][i]);
            }
        }
        if ((mask & (mask - 1)) == 0) {
            f[mask][0] = 0;
        }
        for (int j = 0; j <= m; j++) {
            if (f[mask][j] == -1) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                if (~mask >> i & 1) {
                    int v = mask | 1 << i;
                    if (f[v][j] == -1 || f[v][j] > f[mask][j] + disa[i][mask]) {
                        f[v][j] = f[mask][j] + disa[i][mask];
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int j = i;
            while (j >= 0 && (f[mask][j] == -1 || f[mask][j] + disb[i][mask] > t[i])) {
                j--;
            }
            if (j >= 0) {
                dp[mask][i] = std::max(dp[mask][i], j + 1);
            }
            ans = std::max(ans, dp[mask][i]);
            if (dp[mask][i] == -1) {
                continue;
            }
            int x = dp[mask][i];
            for (int j = i + 1; j < m; j++) {
                if (t[i] + std::min(std::abs(xb[i] - xb[j]) + std::abs(yb[i] - yb[j]), disb[j][mask]) <= t[j]) {
                    dp[mask][j] = std::max(dp[mask][j], x + 1);
                }
            }
            for (int j = 0; j < n; j++) {
                if (~mask >> j & 1) {
                    int v = mask | 1 << j;
                    if (f[v][x] == -1 || f[v][x] > t[i] + std::min(disb[i][1 << j], disa[j][mask])) {
                        f[v][x] = t[i] + std::min(disb[i][1 << j], disa[j][mask]);
                    }
                }
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}