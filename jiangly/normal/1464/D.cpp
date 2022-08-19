#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>
#include <tuple>
#include <queue>
#include <complex>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <functional>

using i64 = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

constexpr int P = 1000000007;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        --p[i];
    }
    int cnt[3] {};
    bool g = false;
    int ans = n;
    std::vector<bool> vis(n);
    int circ = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        int len = 0;
        for (int j = i; !vis[j]; j = p[j]) {
            vis[j] = true;
            ++len;
        }
        ++cnt[len % 3];
        if (len % 3 == 1 && len >= 4) {
            g = true;
        }
        ++circ;
    }
    int days = 1;
    if (n % 3 == 0) {
        for (int i = 0; i < n / 3; ++i) {
            days = 3ll * days % P;
        }
        int t = std::min(cnt[1], cnt[2]) + 2 * std::abs(cnt[1] - cnt[2]) / 3;
        ans = t + n / 3 - (circ - t);
    } else if (n % 3 == 1) {
        days = 4;
        for (int i = 0; i < n / 3 - 1; ++i) {
            days = 3ll * days % P;
        }
        if (g) {
            int t = std::min(cnt[1] - 1, cnt[2]) + 2 * std::abs(cnt[1] - 1 - cnt[2]) / 3;
            ans = std::min(ans, t + n / 3 - (circ - t));
        }
        if (cnt[1] > 0 && cnt[0] > 0) {
            int t = 1 + std::min(cnt[1] - 1, cnt[2]) + 2 * std::abs(cnt[1] - 1 - cnt[2]) / 3;
            ans = std::min(ans, t + n / 3 - (circ - t));
        }
        if (cnt[2] >= 2) {
            int t = 1 + std::min(cnt[1], cnt[2] - 2) + 2 * std::abs(cnt[1] - (cnt[2] - 2)) / 3;
            ans = std::min(ans, t + n / 3 - (circ - t));
        }
        if (cnt[1] >= 4) {
            int t = 2 + std::min(cnt[1] - 3, cnt[2]) + 2 * std::abs(cnt[1] - 3 - cnt[2]) / 3;
            ans = std::min(ans, t + n / 3 + 1 - (circ - t));
        }
        if (cnt[1] >= 2 && cnt[2] > 0) {
            int t = 1 + std::min(cnt[1] - 2, cnt[2] - 1) + 2 * std::abs(cnt[1] - 2 - (cnt[2] - 1)) / 3;
            ans = std::min(ans, t + n / 3 + 1 - (circ - t));
        }
        if (cnt[2] >= 2) {
            int t = std::min(cnt[1], cnt[2] - 2) + 2 * std::abs(cnt[1] - (cnt[2] - 2)) / 3;
            ans = std::min(ans, t + n / 3 + 1 - (circ - t));
        }
    } else {
        days = 2;
        for (int i = 0; i < n / 3; ++i) {
            days = 3ll * days % P;
        }
        if (cnt[2] > 0) {
            int t = std::min(cnt[1], cnt[2] - 1) + 2 * std::abs(cnt[1] - (cnt[2] - 1)) / 3;
            ans = std::min(ans, t + n / 3 + 1 - (circ - t));
        }
        if (cnt[1] >= 2) {
            int t = 1 + std::min(cnt[1] - 2, cnt[2]) + 2 * std::abs(cnt[1] - 2 - cnt[2]) / 3;
            ans = std::min(ans, t + n / 3 + 1 - (circ - t));
        }
    }
    std::cout << days << " " << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}