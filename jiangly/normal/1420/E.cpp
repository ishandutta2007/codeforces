#include <bits/stdc++.h>

constexpr int N = 80;

// dp[][number of swaps][number of trailing '0's][number of '1's]

int dp[2][N * (N - 1) / 2 + 1][N + 1][N + 1];

void chkmin(int &a, int b) {
    a = std::min(a, b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    int m = n * (n - 1) / 2;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    
    std::vector<int> ones;
    for (int i = 0; i < n; ++i)
        if (a[i] == 1)
            ones.push_back(i);
    
    std::memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0][0] = 0;
    
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur ^= 1;
        std::memset(dp[cur], 0x3f, sizeof(dp[cur]));
        for (int s = 0; s <= m; ++s) {
            for (int t = 0; t <= i; ++t) {
                for (int c = 0; c <= i && c <= int(ones.size()); ++c) {
                    if (dp[!cur][s][t][c] == 0x3f3f3f3f)
                        continue;
                    chkmin(dp[cur][s][t + 1][c], dp[!cur][s][t][c]);
                    if (c < int(ones.size()))
                        chkmin(dp[cur][s + std::abs(i - ones[c])][0][c + 1], dp[!cur][s][t][c] + t * (t - 1) / 2);
                }
            }
        }
    }
    std::vector<int> ans(m + 1, std::numeric_limits<int>::max());
    for (int s = 0; s <= m; ++s)
        for (int t = 0; t <= n; ++t)
            ans[s] = std::min(ans[s], dp[cur][s][t][ones.size()] + t * (t - 1) / 2);
    for (int i = 1; i <= m; ++i)
        ans[i] = std::min(ans[i], ans[i - 1]);
    int total = n - ones.size();
    total = total * (total - 1) / 2;
    for (int i = 0; i <= m; ++i)
        std::cout << total - ans[i] << " \n"[i == m];
    return 0;
}