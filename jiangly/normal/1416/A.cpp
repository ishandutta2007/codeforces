#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> p(n, -1), k(n);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            --x;
            k[x] = std::max(k[x], i - p[x]);
            p[x] = i;
        }
        for (int i = 0; i < n; ++i) k[i] = std::max(k[i], n - p[i]);
        std::vector<int> ans(n + 1, -1);
        for (int x = 0, i = n; x < n; ++x)
            while (i >= k[x]) ans[i--] = x + 1;
        for (int i = 1; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
    }
    return 0;
}