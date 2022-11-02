#include <bits/stdc++.h>

int n, m, k;

std::vector<std::vector<int>> a, dp;

std::deque<int> que;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> k;
    a.assign(n, std::vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }
    }
    dp.assign(n, std::vector<int>(m - k + 1));
    for (int i = 0; i <= m - k; ++i)
        dp[0][i] = a[0][i + k] - a[0][i];
    for (int i = 1; i < n; ++i) {
        int max = 0;
        que.clear();
        for (int j = 0; j <= m - k; ++j) {
            if (j >= k)
                max = std::max(max, dp[i - 1][j - k] + a[i][j] - a[i][j - k]);
            while (!que.empty() && dp[i - 1][que.back()] - a[i][que.back()] <= dp[i - 1][j] - a[i][j])
                que.pop_back();
            que.push_back(j);
            if (que.front() <= j - k)
                que.pop_front();
            dp[i][j] = std::max(max, dp[i - 1][que.front()] - a[i][que.front()] + a[i][j]);
        }
        max = 0;
        que.clear();
        for (int j = m - k; j >= 0; --j) {
            if (j + k <= m - k)
                max = std::max(max, dp[i - 1][j + k] + a[i][j + 2 * k] - a[i][j + k]);
            while (!que.empty() && dp[i - 1][que.back() - k] + a[i][que.back()] <= dp[i - 1][j] + a[i][j + k])
                que.pop_back();
            que.push_back(j + k);
            if (que.front() >= j + 2 * k)
                que.pop_front();
            dp[i][j] = std::max(dp[i][j], std::max(max, dp[i - 1][que.front() - k] + a[i][que.front()] - a[i][j + k]));
        }
        for (int j = 0; j <= m - k; ++j)
            dp[i][j] += a[i][j + k] - a[i][j];
    }
    std::cout << *std::max_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";
    return 0;
}