#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    
    if (2 * b - a > 0 && (2 * b - a) % c == 0) {
        std::cout << "YES\n";
    } else if (2 * b - c > 0 && (2 * b - c) % a == 0) {
        std::cout << "YES\n";
    } else if ((a + c) % (2 * b) == 0) {
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