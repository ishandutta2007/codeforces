#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int cnt = 1;
        for (int i = 0; i < n - 1; ++i) if (a[i] != a[i + 1]) ++cnt;
        if (k == 1) {
            if (cnt == 1) std::cout << 1 << "\n";
            else std::cout << -1 << "\n";
        } else {
            std::cout << std::max(1, (cnt - 1 + k - 2) / (k - 1)) << "\n";
        }
    }
    return 0;
}