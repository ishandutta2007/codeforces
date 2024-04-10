#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, P;
    std::cin >> n >> P;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> ans(n);
    std::vector dp(n, std::vector<int>(n)), g(n, std::vector<int>(n));
    std::function<void(int, int)> dfs = [&](int u, int p) {
        for (int i = 1; i < n; i++) {
            dp[u][i] = 1;
        }
        if (p != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), p));
        }
        for (auto v : adj[u]) {
            dfs(v, u);
            for (int i = 1; i < n; i++) {
                dp[u][i] = 1LL * dp[u][i] * g[v][i] % P;
            }
        }
        
        if (u > 0) {
            int d = adj[u].size();
            std::vector pre(d, std::vector<int>(n, 1)), suf(pre);
            for (int i = 1; i < d; i++) {
                for (int j = 1; j < n; j++) {
                    pre[i][j] = 1LL * pre[i - 1][j] * g[adj[u][i - 1]][j] % P;
                }
            }
            for (int i = d - 2; i >= 0; i--) {
                for (int j = 1; j < n; j++) {
                    suf[i][j] = 1LL * suf[i + 1][j] * g[adj[u][i + 1]][j] % P;
                }
            }
            for (int i = 0; i < d; i++) {
                int sum = 0;
                for (int j = 1; j < n; j++) {
                    dp[u][j] = (dp[u][j] + 1LL * sum * dp[adj[u][i]][j]) % P;
                    sum = (sum + 1LL * pre[i][j] * suf[i][j]) % P;
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            g[u][i] = (g[u][i - 1] + dp[u][i]) % P;
        }
    };
    dfs(0, -1);
    
    std::vector binom(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % P;
        }
    }
    
    ans = dp[0];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < i; j++) {
            ans[i] = (ans[i] + 1LL * (P - binom[i][j]) * ans[j]) % P;
        }
    }
    for (int i = 1; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}