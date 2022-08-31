#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::function<bool(int, int, bool)> dfs = [&](int u, int x, bool nz) {
        if (u == n) {
            return x == 0 && nz;
        }
        return dfs(u + 1, x - a[u], true) || dfs(u + 1, x, nz) || dfs(u + 1, x + a[u], true);
    };
    
    if (dfs(0, 0, false)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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