#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<long long> t(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> t[i];
    std::reverse(t.begin() + 1, t.end());
    std::vector<std::pair<int, int>> intervals;
    for (int i = n; i >= 1; --i) {
        if (t[i] == 0)
            continue;
        if (!intervals.empty() && t[intervals.back().second] >= t[i]) {
            intervals.back().first = i;
        } else {
            intervals.emplace_back(i, i);
        }
    }
    std::reverse(intervals.begin(), intervals.end());
    // for (auto [l, r] : intervals) {
    //     std::cout << "[" << l << ", " << r << "]\n";
    // }
    if (intervals.empty()) {
        std::cout << std::string(n, '0') << std::endl;
        return 0;
    }
    auto checkSum = [&](long long x, int l, int r) {
        int kl = 0, kr = r - l + 1;
        while (kl < kr) {
            int m = (kl + kr) / 2;
            long long vr = 1ll * (r + (r - m + 1)) * m / 2;
            if (vr >= x) {
                kr = m;
            } else {
                kl = m + 1;
            }
        }
        long long vl = 1ll * (l + (l + kl - 1)) * kl / 2;
        long long vr = 1ll * (r + (r - kl + 1)) * kl / 2;
        return vl <= x && x <= vr ? kl : -1;
    };
    int m = intervals.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(2, -1));
    std::vector<std::vector<int>> trans(m + 1, std::vector<int>(2, -1));
    dp[m][1] = n + 1;
    for (int i = m - 1; i > 0; --i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (dp[i + 1][k] == -1)
                    continue;
                if (t[intervals[i].first] != t[intervals[i].second] && j == 0)
                    continue;
                long long tb1 = i + 1 == m ? 0 : t[intervals[i + 1].first] - 1 + k;
                for (int l = intervals[i].first - (j == 0); l > intervals[i - 1].second && l > dp[i][j]; --l) {
                    if (j == 1 && l < intervals[i].first)
                        break;
                    long long tb = t[intervals[i].first] - 1 + j;
                    if (checkSum(tb - tb1 - l, intervals[i].second + 1, dp[i + 1][k] - 1) >= 0) {
                        dp[i][j] = l;
                        trans[i][j] = k;
                        break;
                    }
                }
            }
        }
    }
    long long min = 1e18, max = -1e18;
    for (int i = intervals[0].first; i <= intervals[0].second; ++i) {
        if (t[i] == 0)
            continue;
        if (t[i] < min)
            min = t[i];
        if (t[i] > max)
            max = t[i];
    }
    int cmax = std::count(t.begin() + intervals[0].first, t.begin() + intervals[0].second + 1, max);
    std::string ans(n + 1, '0');
    auto construct = [&](long long x, int l, int r) {
        int k = checkSum(x, l, r);
        std::vector<int> y(k);
        for (int i = 0; i < k; ++i)
            y[i] = l + i;
        x -= std::accumulate(y.begin(), y.end(), 0ll);
        for (int i = k - 1; i >= 0; --i) {
            auto t = std::min(1ll * r - l - k + 1, x);
            x -= t;
            y[i] += t;
        }
        for (auto i : y)
            ans[i] = '1';
    };
    for (int k = 0; k < 2; ++k) {
        if (dp[1][k] == -1)
            continue;
        long long tb1 = 1 == m ? 0 : t[intervals[1].first] - 1 + k;
        for (int i = 0; i <= intervals[0].second; ++i) {
            if (min != max && t[i] != min)
                continue;
            if (t[i] == max && cmax > 1)
                continue;
            long long tb = t[i] == 0 ? max - 1 : t[i];
            if (checkSum(tb - tb1 - i, intervals[0].second + 1, dp[1][k] - 1) >= 0) {
                ans[i] = '1';
                construct(tb - tb1 - i, intervals[0].second + 1, dp[1][k] - 1);
                int x = k;
                for (int i = 1; i < m; ++i) {
                    ans[dp[i][x]] = '1';
                    long long tb = t[intervals[i].first] - 1 + x;
                    long long tb1 = i + 1 == m ? 0 : t[intervals[i + 1].first] - 1 + trans[i][x];
                    construct(tb - tb1 - dp[i][x], intervals[i].second + 1, dp[i + 1][trans[i][x]] - 1);
                    x = trans[i][x];
                }
                ans.erase(ans.begin());
                std::reverse(ans.begin(), ans.end());
                std::cout << ans << std::endl;
                return 0;
            }
        }
    }
    return 0;
}