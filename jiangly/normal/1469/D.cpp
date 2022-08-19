#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> ans;
        while (n > 2) {
            int s = std::ceil(std::sqrt(n));
            for (int i = s + 1; i < n; ++i) {
                ans.emplace_back(i, i + 1);
            }
            ans.emplace_back(n, s);
            ans.emplace_back(n, s);
            n = s;
        }
        std::cout << ans.size() << "\n";
        for (auto [x, y] : ans) {
            std::cout << x << " " << y << "\n";
        }
    }
    return 0;
}