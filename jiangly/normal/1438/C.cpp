#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int a;
                std::cin >> a;
                std::cout << a + (a % 2 != (i + j) % 2) << " \n"[j == m];
            }
        }
    }
    
    return 0;
}