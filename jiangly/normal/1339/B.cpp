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
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::sort(a.begin(), a.end());
        int m = n / 2;
        std::vector<int> b{a[m]};
        for (int i = 1; i <= m; ++i) {
            b.push_back(a[m - i]);
            if (m + i < n)
                b.push_back(a[m + i]);
        }
        for (int i = 0; i < n; ++i)
            std::cout << b[i] << " \n"[i == n - 1];
    }
    return 0;
}