#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 a, b, x;
    std::cin >> a >> b >> x;
    
    while (b) {
        if (x <= a && x % b == a % b) {
            std::cout << "YES\n";
            return;
        }
        a %= b;
        std::swap(a, b);
    }
    std::cout << "NO\n";
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