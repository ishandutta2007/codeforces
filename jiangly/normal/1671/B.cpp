#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    
    for (auto s : { x[0] - 2, x[0] - 1, x[0] }) {
        int v = s;
        
        bool able = true;
        
        for (int i = 0; i < n; i++) {
            v++;
            if (std::abs(x[i] - v) > 1) {
                able = false;
                break;
            }
        }
        
        if (able) {
            std::cout << "YES\n";
            return;
        }
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