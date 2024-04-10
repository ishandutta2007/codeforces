#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int64_t ans = 1e18;
    for (int c = 1; std::pow(c, n - 1) < n * 3e9; ++c) {
        int64_t cost = 0, v = 1;
        for (int i = 0; i < n; ++i, v *= c)
            cost += std::abs(v - a[i]);
        ans = std::min(ans, cost);
    }
    std::cout << ans << "\n";
    return 0;
}