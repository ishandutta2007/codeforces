#include <bits/stdc++.h>

const long long INF = 1e18;

int n, m;

long long k;

std::string s;

std::vector<std::vector<int>> lcp;
std::vector<std::vector<long long>> dp;
std::vector<std::pair<int, int>> sub;

long long solve(int l, int r) {
    dp.assign(2, std::vector<long long>(n + 1));
    int cur = 0;
    dp[cur][n] = 1;
    for (int i = 1; i <= m; ++i) {
        cur ^= 1;
        for (int j = n - 1; j >= 0; --j) {
            dp[cur ^ 1][j] = std::min(INF, dp[cur ^ 1][j] + dp[cur ^ 1][j + 1]);
        }
        std::fill(dp[cur].begin(), dp[cur].end(), 0);
        for (int j = n - i; j >= 0; --j) {
            int len = std::min(r - l, lcp[j][l]);
            if ((len < n - j ? s[j + len] : -1) <
                (len < r - l ? s[l + len] : -1)) {
                continue;
            }
            dp[cur][j] = dp[cur ^ 1][j + len + (len < r - l)];
        }
    }
    return dp[cur][0];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> k;
    std::cin >> s;
    lcp.assign(n + 1, std::vector<int>(n + 1));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            lcp[i][j] = s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0;
        }
    }
    sub.reserve(n * (n + 1) / 2);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) sub.emplace_back(i, j);
    }
    std::sort(sub.begin(), sub.end(), [&](const auto &lhs, const auto &rhs) {
        int lenl = lhs.second - lhs.first, lenr = rhs.second - rhs.first;
        int l = std::min(lcp[lhs.first][rhs.first], std::min(lenl, lenr));
        return (l < lenl ? s[lhs.first + l] : -1) <
               (l < lenr ? s[rhs.first + l] : -1);
    });
    int l = 0, r = sub.size() - 1;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (solve(sub[m].first, sub[m].second) >= k) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    std::cout << s.substr(sub[l].first, sub[l].second - sub[l].first) << "\n";
    return 0;
}