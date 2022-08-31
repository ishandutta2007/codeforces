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
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            --a[i];
        }
        std::vector<int> d(2 * k);
        for (int i = 0; i < n / 2; ++i) {
            int x = a[i] + a[n - i - 1];
            int l = x - std::max(a[i], a[n - i - 1]);
            int r = x + k - std::min(a[i], a[n - i - 1]);
            d[0] += 2;
            --d[l];
            --d[x];
            ++d[x + 1];
            ++d[r];
        }
        for (int i = 1; i < 2 * k; ++i)
            d[i] += d[i - 1];
        std::cout << *std::min_element(d.begin(), d.end() - 1) << "\n";
    }
    return 0;
}