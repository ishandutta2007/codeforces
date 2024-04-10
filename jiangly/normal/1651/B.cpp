#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    if (n <= 19) {
        std::cout << "YES\n";
        int p = 1;
        for (int i = 0; i < n; i++) {
            std::cout << p << " \n"[i == n - 1];
            p *= 3;
        }
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