#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::cout << n - 1 + m - 1 + std::min(std::min(1, n - 1) + m - 1, std::min(1, m - 1) + n - 1) << "\n";
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