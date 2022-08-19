#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
constexpr long long MIN = std::numeric_limits<long long>::min();
int n, p, k;
std::vector<int> a, perm, id;
std::vector<std::vector<int>> s;
std::vector<std::vector<long long>> suf, pre;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> p >> k;
    a.resize(n);
    s.assign(n, std::vector<int>(p));
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j)
            std::cin >> s[i][j];
    perm.resize(n);
    std::iota(perm.begin(), perm.end(), 0);
    std::sort(perm.begin(), perm.end(), [&](int i, int j) {
        return a[i] > a[j];
    });
    suf.assign(n + 1, std::vector<long long>(1 << p, MIN));
    suf[n][0] = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int t = 0; t < (1 << p); ++t) {
            suf[i][t] = suf[i + 1][t];
            for (int j = 0; j < p; ++j)
                if ((t >> j & 1) && suf[i + 1][t ^ 1 << j] != MIN)
                    suf[i][t] = std::max(suf[i][t], suf[i + 1][t ^ 1 << j] + s[perm[i]][j]);
        }
    }
    pre.assign(n + 1, std::vector<long long>(1 << p, MIN));
    pre[0][0] = 0;
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[perm[i]];
        for (int t = 0; t < (1 << p); ++t) {
            pre[i + 1][t] = pre[i][t];
            for (int j = 0; j < p; ++j)
                if ((t >> j & 1) && pre[i][t ^ 1 << j] != MIN)
                    pre[i + 1][t] = std::max(pre[i + 1][t], pre[i][t ^ 1 << j] + s[perm[i]][j] - a[perm[i]]);
            if (i + 1 == k + __builtin_popcount(t))
                ans = std::max(ans, pre[i + 1][t] + suf[i + 1][((1 << p) - 1) ^ t] + sum);
        }
    }
    std::cout << ans << "\n";
    return 0;
}