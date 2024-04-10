#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int xl = 0, xr = 0, yl = 0, yr = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        
        if (x == 0) {
            yl = std::min(yl, y);
            yr = std::max(yr, y);
        }
        
        if (y == 0) {
            xl = std::min(xl, x);
            xr = std::max(xr, x);
        }
    }
    
    std::cout << 2 * (xr - xl + yr - yl) << "\n";
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