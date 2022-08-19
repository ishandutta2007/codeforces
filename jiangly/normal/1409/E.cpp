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
        for (int i = 0; i < n; ++i)
            std::cin >> x[i];
        for (int i = 0; i < n; ++i)
            std::cin >> y[i];
        std::sort(x.begin(), x.end());
        std::vector<int> r(n), mx(n + 1);
        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && x[j] <= x[i] + k)
                ++j;
            r[i] = j;
        }
        for (int i = n - 1; i >= 0; --i)
            mx[i] = std::max(mx[i + 1], r[i] - i);
        for (int i = 0; i < n; ++i)
            ans = std::max(ans, r[i] - i + mx[r[i]]);
        std::cout << ans << "\n";
    }
    return 0;
}