#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, x, y, d;
    std::cin >> n >> m >> x >> y >> d;
    
    if ((y - d <= 1 || x + d >= n) && (y + d >= m || x - d <= 1)) {
        std::cout << "-1\n";
    } else {
        std::cout << n + m - 2 << "\n";
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