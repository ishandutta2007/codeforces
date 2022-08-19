#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    int ans = 1E9;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    if (m % 2 == 0) {
        ans = 0;
    }
    std::vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        deg[u]++;
        deg[v]++;
        ans = std::min(ans, a[u] + a[v]);
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] % 2) {
            ans = std::min(ans, a[i]);
        }
    }
    std::cout << ans << "\n";
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