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
        long long l, r;
        std::cin >> n >> l >> r;
        --l;
        std::vector<long long> pre(n + 1);
        for (int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + 2 * (n - i - 1);
        for (long long i = l; i < r; ++i) {
            int a = std::upper_bound(pre.begin(), pre.end(), i) - pre.begin() - 1;
            int res;
            if (a == n) {
                res = 0;
            } else {
                auto j = i - pre[a];
                res = j % 2 == 0 ? a : a + (j + 1) / 2;
            }
            std::cout << res + 1 << " \n"[i == r - 1];
        }
    }
    return 0;
}