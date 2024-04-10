#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> t(n), h(n);
    for (int i = 0; i < n; ++i)
        std::cin >> t[i];
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<std::vector<int64_t>> dp(n, std::vector<int64_t>(2));
    std::function<void(int, int)> dfs = [&](int u, int p) {
        bool up = (u == 0) || h[p] >= h[u];
        bool down = (u == 0) || h[p] <= h[u];
        int64_t tot = 0;
        std::vector<int64_t> g;
        for (auto v : e[u]) {
            if (v == p)
                continue;
            dfs(v, u);
            tot += dp[v][0];
            g.push_back(dp[v][1] - dp[v][0]);
        }
        if (g.empty()) {
            if (up) {
                dp[u][0] = 0;
            } else {
                dp[u][0] = 1e12;
            }
            if (down) {
                dp[u][1] = 0;
            } else {
                dp[u][1] = 1e12;
            }
            return;
        }
        dp[u][0] = dp[u][1] = 1e12;
        std::sort(g.begin(), g.end());
        if (up) {
            int64_t res = tot;
            dp[u][0] = std::min(dp[u][0], res + 1ll * t[u] * (int(g.size()) - 1 + !u));
            for (int i = 0; i < int(g.size()); ++i) {
                res += g[i];
                dp[u][0] = std::min(dp[u][0], res + 1ll * t[u] * std::max(int(g.size()) - 1 + !u - i - 1, i + 1));
            }
        }
        if (down) {
            int64_t res = tot;
            dp[u][1] = std::min(dp[u][1], res + 1ll * t[u] * int(g.size()));
            for (int i = 0; i < int(g.size()); ++i) {
                res += g[i];
                dp[u][1] = std::min(dp[u][1], res + 1ll * t[u] * std::max(int(g.size()) - i - 1, i + !u));
            }
        }
    };
    dfs(0, -1);
    int64_t ans = std::min(dp[0][0], dp[0][1]);
    for (int i = 1; i < n; ++i)
        ans += t[i];
    std::cout << ans << "\n";
    return 0;
}