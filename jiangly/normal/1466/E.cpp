#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int P = 1000000007;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<i64> x(n);
        int cnt[60] {};
        for (int i = 0; i < n; i++) {
            std::cin >> x[i];
            for (int j = 0; j < 60; ++j) {
                cnt[j] += x[i] >> j & 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = 0, b = 0;
            for (int j = 0; j < 60; ++j) {
                if (x[i] >> j & 1) {
                    a = (a + (1ll << j) % P * cnt[j]) % P;
                    b = (b + (1ll << j) % P * n) % P;
                } else {
                    b = (b + (1ll << j) % P * cnt[j]) % P;
                }
            }
            ans = (ans + i64(a) * b) % P;
        }
        std::cout << ans << "\n";
    }
    return 0;
}