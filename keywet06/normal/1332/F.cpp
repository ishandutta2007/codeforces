#include <bits/stdc++.h>

const int P = 998244353;

int n;

std::vector<std::vector<int>> e;
std::vector<std::vector<unsigned long long>> dp;

void dfs(int u, int p) {
    dp[u][2] = 1;
    for (int v : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] =
            ((dp[u][0] + dp[u][2]) * (dp[v][0] + dp[v][1] + 2 * dp[v][2]) +
             dp[u][0] * (dp[v][0] + dp[v][1] + dp[v][2])) %
            P;
        dp[u][1] = ((dp[u][1] + dp[u][2]) * (dp[v][0] + dp[v][2]) +
                    dp[u][1] * (dp[v][0] + dp[v][1] + dp[v][2])) %
                   P;
        dp[u][2] = dp[u][2] * (dp[v][0] + dp[v][1] + dp[v][2]) % P;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    e.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dp.assign(n, std::vector<unsigned long long>(3));
    dfs(0, -1);
    int ans = (dp[0][0] + dp[0][1] + dp[0][2] + P - 1) % P;
    std::cout << ans << "\n";
    return 0;
}