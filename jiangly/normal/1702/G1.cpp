#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> dep(n), parent(n), in(n), out(n);
    parent[0] = -1;
    
    int cnt = 0;
    std::function<void(int)> dfs = [&](int u) -> void {
        in[u] = cnt++;
        if (u != 0) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        for (auto v : adj[u]) {
            dep[v] = dep[u] + 1;
            parent[v] = u;
            dfs(v);
        }
        out[u] = cnt;
    };
    dfs(0);
    
    auto isAncester = [&](int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    };
    
    auto directChild = [&](int u, int v) {
        return *std::prev(std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }));
    };
    
    int q;
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        int k;
        std::cin >> k;
        
        std::vector<int> a(k);
        for (int j = 0; j < k; j++) {
            std::cin >> a[j];
            a[j]--;
        }
        
        std::sort(a.begin(), a.end(), [&](int x, int y) {
            return dep[x] < dep[y];
        });
        
        int h1 = a[0], t1 = a[0], h2 = -1, t2 = -1;
        bool ok = true;
        for (int j = 1; j < k; j++) {
            int x = a[j];
            if (isAncester(t1, x)) {
                t1 = x;
            } else if (h2 == -1) {
                h2 = t2 = x;
            } else if (isAncester(t2, x)) {
                t2 = x;
            } else {
                ok = false;
            }
        }
        
        if (h2 != -1 && isAncester(h1, h2) && directChild(h1, h2) == directChild(h1, t1)) {
            ok = false;
        }
        
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;
}