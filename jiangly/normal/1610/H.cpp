#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> adj(n);
    std::vector<int> parent(n, -1);
    for (int i = 1; i < n; i++) {
        std::cin >> parent[i];
        parent[i]--;
        adj[parent[i]].push_back(i);
    }
    
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
        if (parent[x] == y || parent[y] == x) {
            std::cout << "-1\n";
            return 0;
        }
    }
    
    std::vector<int> dp(n), in(n, -1), out(n), sum(n);
    
    int clk = 0;
    std::function<void(int)> dfs1 = [&](int u) {
        in[u] = clk++;
        for (auto v : adj[u]) {
            dfs1(v);
            sum[u] += dp[v];
        }
        out[u] = clk;
        dp[u] = sum[u];
        
        if (u != 0) {
            for (auto x : e[parent[u]]) {
                if (in[u] <= in[x] && in[x] < out[u]) {
                    dp[u] = std::max(dp[u], 1 + dp[x]);
                }
            }
        }
    };
    dfs1(0);
    
    std::vector<int> up(n), f(n);
    std::function<void(int)> dfs2 = [&](int u) {
        for (auto v : adj[u]) {
            up[v] = sum[u] + up[u] - dp[v];
        }
        for (auto v : adj[u]) {
            f[u] = v;
            for (auto x : e[v]) {
                if (in[v] <= in[x] && in[x] < out[v]) {
                    continue;
                } else if (in[x] <= in[u] && in[u] < out[x]) {
                    up[v] = std::max(up[v], 1 + up[f[x]]);
                } else {
                    up[v] = std::max(up[v], 1 + dp[x]);
                }
            }
            dfs2(v);
        }
    };
    dfs2(0);
    
    int res = n;
    for (int i = 0; i < n; i++) {
        res = std::min(res, 1 + sum[i] + up[i]);
    }
    std::cout << res << '\n';
    
    return 0;
}