#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int n = 2 * std::abs(a - b);
    if (a > n || b > n || c > n) {
        std::cout << "-1\n";
        return;
    }
    std::cout << (n / 2 + c - 1) % n + 1 << "\n";
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