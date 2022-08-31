#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    if (k == 1) {
        std::cout << "YES\n";
        for (int i = 0; i < n; i++) {
            std::cout << i + 1 << "\n";
        }
    } else if (n % 2 == 0) {
        std::cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                std::cout << j * n + i + 1 << " \n"[j == k - 1];
            }
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