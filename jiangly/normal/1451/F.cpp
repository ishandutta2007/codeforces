#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> b(n + m - 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x;
                std::cin >> x;
                b[i + j] ^= x;
            }
        }
        if (std::count(b.begin(), b.end(), 0) == n + m - 1) {
            std::cout << "Jeel\n";
        } else {
            std::cout << "Ashish\n";
        }
    }
    
    return 0;
}