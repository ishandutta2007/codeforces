#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::array<int, 3>> p(m);
    for (int i = 0; i < m; i++) {
        int x, w;
        std::cin >> x >> w;
        p[i] = {w, x, i};
    }
    
    std::sort(p.begin(), p.end());
    
    std::sort(p.begin(), p.begin() + 2 * n , [&](auto a, auto b) { return a[1] < b[1]; });
    
    i64 ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        ans += p[i][0];
    }
    
    std::cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << p[i][2] + 1 << " " << p[2 * n - i - 1][2] + 1 << "\n";
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