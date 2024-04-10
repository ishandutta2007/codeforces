#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> f(n, (1 << 30) - 1);
    
    std::vector<std::vector<std::array<int, 2>>> adj(n);
    
    for (int i = 0; i < q; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        f[a] &= c;
        f[b] &= c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (auto [j, x] : adj[i]) {
            t |= x & ~f[j];
            if (j == i) {
                t = x;
            }
        }
        f[i] = t;
        std::cout << f[i] << " \n"[i == n - 1];
    }
    
    return 0;
}