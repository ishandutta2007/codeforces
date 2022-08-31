#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            m -= a;
        }
        std::cout << (m == 0 ? "YES" : "NO") << "\n";
    }
    
    return 0;
}