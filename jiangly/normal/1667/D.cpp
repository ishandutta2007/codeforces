#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> deg(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u] ^= 1;
        deg[v] ^= 1;
    }
    
    bool good = true;
    
    std::vector<int> parent(n, -1);
    std::vector dp(n, std::vector<bool>(2));
    auto dfs1 = [&](auto dfs1, int u) -> void {
        int cnt[2] {}, cnt2 = 0;
        for (auto v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            dfs1(dfs1, v);
            if (dp[v][0] && dp[v][1]) {
                cnt2++;
            } else if (dp[v][0]) {
                cnt[0]++;
            } else {
                cnt[1]++;
            }
        }
        for (int i = 0; i < 2; i++) {
            if (u) {
                cnt[i ^ deg[u] ^ deg[parent[u]]]++;
            }
            if (cnt[0] + cnt2 >= cnt[1] && cnt[1] + cnt2 >= cnt[0] - 1) {
                dp[u][i] = true;
            }
            if (u) {
                cnt[i ^ deg[u] ^ deg[parent[u]]]--;
            }
        }
        if (!dp[u][0] && !dp[u][1]) {
            good = false;
        }
    };
    dfs1(dfs1, 0);
    
    if (!good) {
        std::cout << "NO\n";
        return;
    }
    
    std::cout << "YES\n";
    auto dfs2 = [&](auto dfs2, int u, int t) -> void {
        std::vector<int> a[2];
        if (u) {
            a[t ^ deg[u] ^ deg[parent[u]]].push_back(u);
        }
        std::vector<int> b;
        for (auto v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            if (dp[v][0] && dp[v][1]) {
                b.push_back(v);
            } else if (dp[v][0]) {
                a[0].push_back(v);
            } else {
                a[1].push_back(v);
            }
        }
        for (auto x : b) {
            if (a[0].size() <= a[1].size()) {
                a[0].push_back(x);
            } else {
                a[1].push_back(x);
            }
        }
        for (int i = 0; i < int(a[0].size()); i++) {
            if (a[0][i] == u) {
                std::cout << u + 1 << " " << parent[u] + 1 << "\n";
            } else {
                dfs2(dfs2, a[0][i], 0);
            }
            if (i < int(a[1].size())) {
                if (a[1][i] == u) {
                    std::cout << u + 1 << " " << parent[u] + 1 << "\n";
                } else {
                    dfs2(dfs2, a[1][i], 1);
                }
            }
        }
    };
    dfs2(dfs2, 0, 0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}