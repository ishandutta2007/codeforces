#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int r, b, d;
    std::cin >> r >> b >> d;
    
    if (r <= 1LL * (d + 1) * b && b <= 1LL * (d + 1) * r) {
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