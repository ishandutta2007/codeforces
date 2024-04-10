#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<long long> cnt(60);
        for (int i = 0; i < n; ++i) {
            long long a;
            std::cin >> a;
            int t = 0;
            while (a > 0) {
                cnt[t] += a % k;
                a /= k;
                ++t;
            }
        }
        bool ok = true;
        for (int i = 0; i < 60; ++i)
            if (cnt[i] > 1)
                ok = false;
        std::cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}