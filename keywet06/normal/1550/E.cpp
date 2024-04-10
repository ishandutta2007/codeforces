#include <bits/stdc++.h>

int n, k;
std::string s;

bool check(int d) {
    std::vector<int> lst(k, n);
    std::vector<std::vector<int>> pos(n + 1, std::vector<int>(k, n + 1));
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != '?') lst[s[i] - 'a'] = i;
        int cur = n;
        for (int j = 0; j < k; ++j) {
            pos[i][j] = (i + d <= cur ? i + d : pos[i + 1][j]);
            cur = std::min(cur, lst[j]);
        }
        cur = n;
        for (int j = k - 1; j >= 0; --j) {
            if (i + d > cur) pos[i][j] = pos[i + 1][j];
            cur = std::min(cur, lst[j]);
        }
    }
    std::vector<int> dp(1 << k, n + 1);
    dp[0] = 0;
    for (int d = 0; d < 1 << k; ++d) {
        if (dp[d] < n + 1) {
            for (int i = 0; i < k; ++i) {
                if (!((d >> i) & 1)) {
                    dp[d | (1 << i)] =
                        std::min(dp[d | (1 << i)], pos[dp[d]][i]);
                }
            }
        }
    }
    return dp[(1 << k) - 1] <= n;
}

int main() {
    std::cin >> n >> k;
    std::cin >> s;
    int l = 1, r = n;
    int res = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            res = m, l = m + 1;
        } else {
            r = m - 1;
        }
    }
    std::cout << res << std::endl;
    return 0;
}