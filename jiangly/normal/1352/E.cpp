#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::vector<int> sum(n + 1);
        std::vector<bool> special(n + 1);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::partial_sum(a.begin(), a.end(), sum.begin() + 1);
        for (int i = 0; i < n; ++i)
            for (int j = i + 2; j <= n; ++j)
                if (sum[j] - sum[i] <= n)
                    special[sum[j] - sum[i]] = true;
        int ans = 0;
        for (auto i : a)
            ans += special[i];
        std::cout << ans << "\n";
    }
    return 0;
}