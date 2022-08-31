#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b;
    std::cin >> a >> b;
    
    if (a == b) {
        std::cout << (a > 0) << "\n";
    } else if ((a + b) % 2 != 0) {
        std::cout << "-1\n";
    } else {
        std::cout << "2\n";
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