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
        std::vector<long long> a(n), b(n);
        long long res = 0, m = std::numeric_limits<long long>::max();
        for (int i = 0; i < n; ++i)
            std::cin >> a[i] >> b[i];
        for (int i = 0; i < n; ++i) {
            res += std::max(0ll, a[(i + 1) % n] - b[i]);
            m = std::min(m, a[(i + 1) % n] - std::max(0ll, a[(i + 1) % n] - b[i]));
        }
        std::cout << res + m << "\n";
    }
    return 0;
}