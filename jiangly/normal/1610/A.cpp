#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::cout << 2 - (n == 1) - (m == 1) << '\n';
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