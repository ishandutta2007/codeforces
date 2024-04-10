#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    for (int k = 0; k < n; k++) {
        std::cout << std::string(k, '(') + std::string(k, ')') +
                    std::string(n - k, '(') + std::string(n - k, ')') << "\n";
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