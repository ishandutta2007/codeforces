#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> parent(n), dep(n);
    std::vector<bool> vis(n);
    parent[0] = -1;
    
    std::function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v : adj[u]) {
            if (vis[v]) {
                continue;
            }
            dep[v] = dep[u] + 1;
            parent[v] = u;
            dfs(v);
        }
    };
    dfs(0);
    
    int q;
    std::cin >> q;
    
    std::vector<int> deg(n), a(q), b(q);
    for (int i = 0; i < q; i++) {
        std::cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        deg[a[i]]++;
        deg[b[i]]++;
    }
    
    int cnt = std::count_if(deg.begin(), deg.end(), [&](int x) { return x % 2 == 1; });
    if (cnt > 0) {
        std::cout << "NO\n";
        std::cout << cnt / 2 << "\n";
        return;
    }
    
    std::cout << "YES\n";
    for (int i = 0; i < q; i++) {
        std::vector<int> l, r;
        int u = a[i], v = b[i];
        while (u != v) {
            if (dep[u] > dep[v]) {
                l.push_back(u);
                u = parent[u];
            } else {
                r.push_back(v);
                v = parent[v];
            }
        }
        l.push_back(u);
        l.insert(l.end(), r.rbegin(), r.rend());
        std::cout << l.size() << "\n";
        for (int j = 0; j < int(l.size()); j++) {
            std::cout << l[j] + 1 << " \n"[j == int(l.size()) - 1];
        }
    }
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}