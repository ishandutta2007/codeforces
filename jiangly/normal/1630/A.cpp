#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    if (k == 0) {
        for (int i = 0; i < n / 2; i++) {
            std::cout << i << " " << n - i - 1 << "\n";
        }
    } else if (k < n - 1) {
        std::cout << k << " " << n - 1 << "\n";
        std::cout << n - 1 - k << " " << "0\n";
        for (int i = 1; i < n / 2; i++) {
            if (i != k && i != n - k - 1) {
                std::cout << i << " " << n - i - 1 << "\n";
            }
        }
    } else if (n == 4) {
        std::cout << "-1\n";
    } else {
        std::cout << n - 2 << " " << n - 1 << "\n";
        std::cout << "1 " << 3 << "\n";
        std::cout << n - 4 << " " << "0\n";
        for (int i = 2; i < n / 2; i++) {
            if (i != 3) {
                std::cout << i << " " << n - i - 1 << "\n";
            }
        }
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