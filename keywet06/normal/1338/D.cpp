#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(2));
    int ans = 0;
    std::function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v : e[u]) {
            if (v == p) continue;
            dfs(v, u);
            ans = std::max(ans, dp[u][1] + dp[v][0] + 1);
            ans = std::max(ans, dp[u][0] + int(e[u].size()) - 2 +
                                    std::max(dp[v][0], dp[v][1]));
            dp[u][1] = std::max(dp[u][1], dp[v][0]);
            dp[u][0] = std::max(dp[u][0], std::max(dp[v][0], dp[v][1]));
        }
        ++dp[u][1];
        dp[u][0] += e[u].size() - 2;
        ans = std::max(ans, dp[u][1]);
    };
    dfs(0, -1);
    std::cout << ans << "\n";
    return 0;
}