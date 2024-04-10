#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int x, y;
    std::cin >> x >> y;
    
    if (x > y) {
        std::cout << x + y << "\n";
    } else {
        int n = (x + y) / 2;
        n += (y - n) / x * x;
        std::cout << n << "\n";
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