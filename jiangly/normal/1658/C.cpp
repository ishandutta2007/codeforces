#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    
    auto it = std::find(c.begin(), c.end(), 1);
    if (it == c.end()) {
        std::cout << "NO\n";
        return;
    }
    std::rotate(c.begin(), it, c.end());
    
    for (int i = 1; i < n; i++) {
        if (c[i] > c[i - 1] + 1 || c[i] == 1) {
            std::cout << "NO\n";
            return;
        }
    }
    
    std::cout << "YES\n";
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