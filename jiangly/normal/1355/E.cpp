#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, a, r, m;
    std::cin >> n >> a >> r >> m;
    m = std::min(m, a + r);
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];
    auto get = [&](int x) {
        long long s1 = 0, s2 = 0;
        for (int i = 0; i < n; ++i) {
            if (h[i] < x) {
                s1 += x - h[i];
            } else {
                s2 += h[i] - x;
            }
        }
        if (s1 < s2) {
            return s1 * m + (s2 - s1) * r;
        } else {
            return s2 * m + (s1 - s2) * a;
        }
    };
    #define r whatever
    int l = 0, r = 1e9;
    while (r - l > 3) {
        int m = (l + r) / 2;
        if (get(m) < get(m + 1)) {
            r = m + 1;
        } else {
            l = m;
        }
    }
    long long ans = 1e18;
    for (int i = l; i <= r; ++i)
        ans = std::min(ans, get(i));
    std::cout << ans << "\n";
    return 0;
}