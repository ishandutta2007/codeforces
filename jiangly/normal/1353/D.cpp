#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::set<std::pair<int, int>> s;
        s.emplace(-n, 0);
        std::vector<int> a(n);
        int cnt = 0;
        while (!s.empty()) {
            auto [r, l] = *s.begin();
            s.erase(s.begin());
            r = l - r - 1;
            int m = (l + r) / 2;
            a[m] = ++cnt;
            if (m > l)
                s.emplace(l - m, l);
            if (r > m)
                s.emplace(m - r, m + 1);
        }
        for (int i = 0; i < n; ++i)
            std::cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}