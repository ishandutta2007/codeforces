#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        int sum = std::accumulate(a.begin(), a.end(), 0);
        if (sum % n != 0) {
            std::cout << -1 << "\n";
            continue;
        }
        std::vector<std::tuple<int, int, int>> ans;
        int need = sum / n;
        for (int i = 1; i < n; ++i) {
            int x = (-a[i] % (i + 1) + i + 1) % (i + 1);
            ans.emplace_back(0, i, x);
            ans.emplace_back(i, 0, (a[i] + x) / (i + 1));
        }
        for (int i = 1; i < n; ++i) ans.emplace_back(0, i, need);
        std::cout << ans.size() << "\n";
        for (auto [i, j, x] : ans) std::cout << i + 1 << " " << j + 1 << " " << x << "\n";
    }
    return 0;
}