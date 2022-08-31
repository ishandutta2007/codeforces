#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int l, r;
    std::cin >> l >> r;
    
    std::cout << std::min(r - l, (r - 1) / 2) << "\n";
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