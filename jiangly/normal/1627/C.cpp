#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    
    std::vector<int> ans(n - 1);
    
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 2) {
            std::cout << "-1\n";
            return;
        }
    }
    
    int x = 0;
    while (adj[x].size() == 2) {
        x++;
    }
    
    ans[adj[x][0].second] = 2;
    int y = adj[x][0].first;
    
    int cur = 2;
    while (adj[y].size() == 2) {
        int t = x == adj[y][0].first;
        cur = 5 - cur;
        ans[adj[y][t].second] = cur;
        x = adj[y][t].first;
        std::swap(x, y);
    }
    
    for (int i = 0; i < n - 1; i++) {
        std::cout << ans[i] << " \n"[i == n - 2];
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