#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    int x[n], y[m];
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> y[i];
    }
    
    int cx[n] = {}, cy[m] = {};
    i64 res = 0;
    
    std::vector<std::pair<int, int>> vx, vy;
    
    for (int i = 0; i < k; i++) {
        int a, b;
        std::cin >> a >> b;
        
        bool fx = std::binary_search(x, x + n, a);
        bool fy = std::binary_search(y, y + m, b);
        
        if (fx && fy) {
            continue;
        }
        if (fx) {
            int u = std::lower_bound(y, y + m, b) - y - 1;
            cy[u]++;
            vx.emplace_back(a, u);
        } else {
            int u = std::lower_bound(x, x + n, a) - x - 1;
            cx[u]++;
            vy.emplace_back(b, u);
        }
    }
    for (int i = 0; i < n; i++) {
        res += 1LL * cx[i] * (cx[i] - 1) / 2;
    }
    for (int i = 0; i < m; i++) {
        res += 1LL * cy[i] * (cy[i] - 1) / 2;
    }
    for (auto p : {vx, vy}) {
        std::sort(p.begin(), p.end());
        for (int l = 0, r; l < int(p.size()); l = r) {
            for (r = l; r < int(p.size()) && p[l] == p[r]; r++)
                ;
            res -= 1LL * (r - l) * (r - l - 1) / 2;
        }
    }
    std::cout << res << "\n";
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