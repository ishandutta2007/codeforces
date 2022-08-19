#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    x--;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        p[x] = i;
    }
    
    int v = 0;
    for (int i = 1; i < n; i++) {
        if (adj[i].size() > adj[v].size()) {
            v = i;
        }
    }
    
    if (int(adj[v].size()) != n - 1 || std::is_sorted(p.begin(), p.end())) {
        std::cout << "Alice\n";
        return;
    }
    
    int j = std::find(p.begin(), p.end(), v) - p.begin();
    if (j != v && (x == v || x == j)) {
        std::cout << "Bob\n";
        return;
    }
    
    int u = 0;
    if (v == x) {
        u ^= 1;
    }
    if (n & 1) {
        u ^= 1;
    }
    
    std::vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        for (int j = i; !vis[j]; j = p[j]) {
            vis[j] = true;
        }
        u ^= 1;
    }
    
    if (u == 0) {
        std::cout << "Alice\n";
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (p[i] != i && i != x && p[i] != x) {
            std::swap(p[p[i]], p[i]);
            break;
        }
    }
    
    if (std::is_sorted(p.begin(), p.end())) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
    }
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