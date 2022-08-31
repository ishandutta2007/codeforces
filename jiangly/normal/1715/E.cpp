#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<std::vector<std::array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    std::vector<i64> dis(n, inf);
    dis[0] = 0;
    
    auto dijkstra = [&]() {
        std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> h;
        for (int i = 0; i < n; i++) {
            h.emplace(dis[i], i);
        }
        while (!h.empty()) {
            auto [d, x] = h.top();
            h.pop();
            if (d > dis[x]) {
                continue;
            }
            for (auto [y, w] : adj[x]) {
                if (d + w < dis[y]) {
                    dis[y] = d + w;
                    h.emplace(dis[y], y);
                }
            }
        }
    };
    
    dijkstra();
    for (int i = 0; i < k; i++) {
        std::vector<i64> f(n, inf);
        
        std::function<void(int, int, int, int)> solve = [&](int l, int r, int L, int R) {
            if (l > r) {
                return;
            }
            int m = (l + r) / 2;
            int k = -1;
            i64 v = inf;
            for (int i = L; i <= R; i++) {
                i64 x = dis[i] + 1LL * (i - m) * (i - m);
                if (x < v) {
                    v = x;
                    k = i;
                }
            }
            f[m] = v;
            solve(l, m - 1, L, k);
            solve(m + 1, r, k, R);
        };
        solve(0, n - 1, 0, n - 1);
        
        std::swap(f, dis);
        dijkstra();
    }
    for (int i = 0; i < n; i++) {
        std::cout << dis[i] << " \n"[i == n - 1];
    }
    
    return 0;
}