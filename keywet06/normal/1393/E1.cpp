#include <bits/stdc++.h>

const int P = 1000000007;

int norm(int x) {
    if (x < P) {
        return x;
    } else {
        return x - P;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    std::vector<std::vector<int>> p(n), dp(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        int m = s[i].length();
        p[i].resize(m + 1);
        dp[i].resize(m + 1);
        std::iota(p[i].begin(), p[i].end(), -1);
        std::vector<int> lcp(m);
        for (int j = m - 2; j >= 0; --j)
            lcp[j] = (s[i][j] == s[i][j + 1]) ? 1 + lcp[j + 1] : 0;
        std::sort(p[i].begin(), p[i].end(), [&](int x, int y) {
            if (x == -1) {
                return y + 1 + lcp[y] < m &&
                       s[i][y + lcp[y]] < s[i][y + 1 + lcp[y]];
            } else if (y == -1) {
                return x + 1 + lcp[x] == m ||
                       s[i][x + 1 + lcp[x]] < s[i][x + lcp[x]];
            } else if (x < y) {
                return x + lcp[x] < y &&
                       s[i][x + 1 + lcp[x]] < s[i][x + lcp[x]];
            } else {
                return y + lcp[y] < x &&
                       s[i][y + lcp[y]] < s[i][y + 1 + lcp[y]];
            }
        });
    }
    for (int i = 0; i < n; ++i) {
        int m = s[i].length();
        if (i == 0) {
            for (int j = 0; j <= m; ++j) dp[i][j] = 1;
            continue;
        }
        int xm = s[i - 1].length();
        s[i - 1] += char(0);
        s[i] += char(1);
        int res = 0;
        int mx = std::max(xm, m) + 1;
        int mn = std::min(xm, m) + 1;
        std::vector<int> lcp(mx + 1), lcps(mx + 1), lcpt(mx + 1);
        for (int j = mn - 1; j >= 0; --j)
            lcp[j] = (s[i - 1][j] == s[i][j]) ? 1 + lcp[j + 1] : 0;
        for (int j = std::min(xm, m - 1); j >= 0; --j)
            lcps[j] = (s[i - 1][j] == s[i][j + 1]) ? 1 + lcps[j + 1] : 0;
        for (int j = std::min(xm - 1, m); j >= 0; --j)
            lcpt[j] = (s[i - 1][j + 1] == s[i][j]) ? 1 + lcpt[j + 1] : 0;
        auto cmp = [&](int x, int y) {
            if (x == -1 && y == -1) {
                return s[i - 1] < s[i];
            } else if (x == y) {
                return lcp[0] < x ? s[i - 1][lcp[0]] < s[i][lcp[0]]
                                  : s[i - 1][x + 1 + lcp[x + 1]] <
                                        s[i][x + 1 + lcp[x + 1]];
            } else if (x == -1) {
                return lcp[0] < y
                           ? s[i - 1][lcp[0]] < s[i][lcp[0]]
                           : s[i - 1][y + lcps[y]] < s[i][y + 1 + lcps[y]];
            } else if (y == -1) {
                return lcp[0] < x
                           ? s[i - 1][lcp[0]] < s[i][lcp[0]]
                           : s[i - 1][x + 1 + lcpt[x]] < s[i][x + lcpt[x]];
            } else if (x < y) {
                return lcp[0] < x ? s[i - 1][lcp[0]] < s[i][lcp[0]]
                       : x + lcpt[x] < y
                           ? s[i - 1][x + 1 + lcpt[x]] < s[i][x + lcpt[x]]
                           : s[i - 1][y + 1 + lcp[y + 1]] <
                                 s[i][y + 1 + lcp[y + 1]];
            } else {
                return lcp[0] < y ? s[i - 1][lcp[0]] < s[i][lcp[0]]
                       : y + lcps[y] < x
                           ? s[i - 1][y + lcps[y]] < s[i][y + 1 + lcps[y]]
                           : s[i - 1][x + 1 + lcp[x + 1]] <
                                 s[i][x + 1 + lcp[x + 1]];
            }
        };
        for (int j = 0, k = 0; j <= m; ++j) {
            while (k <= xm && cmp(p[i - 1][k], p[i][j]))
                res = norm(res + dp[i - 1][k++]);
            dp[i][j] = res;
        }
        s[i - 1].pop_back();
        s[i].pop_back();
    }
    int ans = std::accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0ll) % P;
    std::cout << ans << "\n";
    return 0;
}