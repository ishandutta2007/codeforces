#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    
    i64 x = 1LL * a * d;
    i64 y = 1LL * b * c;
    
    if (x == y) {
        std::cout << 0 << "\n";
    } else if ((y && x % y == 0) || (x && y % x == 0)) {
        std::cout << 1 << "\n";
    } else {
        std::cout << 2 << "\n";
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