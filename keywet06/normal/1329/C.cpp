#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int h, g;
        std::cin >> h >> g;
        int n = (1 << h) - 1;
        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        long long ans = 0;
        std::vector<int> f(1 << g);
        std::vector<bool> good(n + 1);
        std::function<std::vector<int>(int, int)> solve = [&](int p, int dep) {
            if (dep == h - 1) return std::vector{p};
            auto left = solve(2 * p, dep + 1);
            auto right = solve(2 * p + 1, dep + 1);
            std::vector<int> v(left.size() + right.size());
            std::merge(left.begin(), left.end(), right.begin(), right.end(),
                       v.begin(), [&](int i, int j) { return a[i] < a[j]; });
            v.push_back(p);
            if (dep < g) {
                int lim = dep < g - 1 ? std::max(f[2 * p], f[2 * p + 1]) : 0;
                auto it = v.begin();
                while (a[*it] < lim) ++it;
                f[p] = a[*it];
                ans += f[p];
                good[*it] = true;
                v.erase(v.begin(), it + 1);
            }
            return v;
        };
        solve(1, 0);
        std::cout << ans << "\n";
        for (int i = (1 << h) - 1; i > 0; --i) {
            if (!good[i]) std::cout << i << " ";
        }
        std::cout << "\n";
    }
    return 0;
}