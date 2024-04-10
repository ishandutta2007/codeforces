#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> x(n), y(n);
        
        bool yes = false;
        for (int i = 0; i < n; ++i) {
            std::cin >> x[i] >> y[i];
        }
        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]) > k) {
                    ok = false;
                }
            }
            if (ok) {
                yes = true;
            }
        }
        if (yes) {
            std::cout << 1 << "\n";
        } else {
            std::cout << - 1 << "\n";
        }
    }
    
    return 0;
}