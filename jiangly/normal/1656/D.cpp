#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n;
    std::cin >> n;
    
    i64 k = 1;
    while (n % 2 == 0) {
        n /= 2;
        k *= 2;
    }
    
    if (n == 1) {
        std::cout << "-1\n";
    } else {
        std::cout << std::min(n, 2 * k) << "\n";
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