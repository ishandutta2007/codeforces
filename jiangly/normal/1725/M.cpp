#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<std::array<int, 2>>> adj0(n), adj1(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj0[u].push_back({v, w});
        adj1[v].push_back({u, w});
    }
    
    std::vector<i64> f(n, -1);
    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> h;
    h.emplace(0, 0);
    
    while (!h.empty()) {
        auto [d, x] = h.top();
        h.pop();
        
        if (f[x] != -1) {
            continue;
        }
        
        f[x] = d;
        for (auto [y, v] : adj0[x]) {
            h.emplace(d + v, y);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (f[i] != -1) {
            h.emplace(f[i], i);
        }
    }
    
    f.assign(n, -1);
    
    while (!h.empty()) {
        auto [d, x] = h.top();
        h.pop();
        
        if (f[x] != -1) {
            continue;
        }
        
        f[x] = d;
        for (auto [y, v] : adj1[x]) {
            h.emplace(d + v, y);
        }
    }
    
    for (int i = 1; i < n; i++) {
        std::cout << f[i] << " \n"[i == n - 1];
    }
    
    return 0;
}