#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::vector<int> x(a), y(b), z(c);
        for (int i = 0; i < a; ++i)
            std::cin >> x[i];
        for (int i = 0; i < b; ++i)
            std::cin >> y[i];
        for (int i = 0; i < c; ++i)
            std::cin >> z[i];
        std::sort(x.begin(), x.end());
        std::sort(y.begin(), y.end());
        std::sort(z.begin(), z.end());
        long long ans = std::numeric_limits<long long>::max();
        auto f = [](long long x, long long y, long long z) {
            return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
        };
        auto solve = [&](auto a, auto b, auto c) {
            int i = 0, j = 0;
            for (auto y : b) {
                while (i < int(a.size()) && a[i] <= y)
                    ++i;
                while (j < int(c.size()) && c[j] < y)
                    ++j;
                if (i > 0 && j < int(c.size()))
                    ans = std::min(ans, f(a[i - 1], y, c[j]));
            }
        };
        solve(x, y, z);
        solve(x, z, y);
        solve(y, x, z);
        solve(y, z, x);
        solve(z, x, y);
        solve(z, y, x);
        std::cout << ans << "\n";
    }
    return 0;
}