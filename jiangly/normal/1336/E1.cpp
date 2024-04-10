#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
constexpr int P = 998244353, INV2 = (P + 1) / 2;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    int rank = 0;
    std::vector<long long> t(m);
    for (int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;
        for (int j = m - 1; j >= 0; --j) {
            if (a >> j & 1) {
                if (t[j] == 0) {
                    ++rank;
                    t[j] = a;
                    break;
                }
                a ^= t[j];
            }
        }
    }
    std::vector<int> ans(m + 1), cnt(m + 1);
    std::vector<long long> p;
    for (int i = m - 1; i >= 0; --i)
        for (int j = i - 1; j >= 0; --j)
            if (t[i] >> j & 1)
                t[i] ^= t[j];
    std::function<void(int, long long)> dfs = [&](int i, long long v) {
        if (i == int(p.size())) {
            ++cnt[__builtin_popcountll(v)];
            return;
        }
        dfs(i + 1, v);
        dfs(i + 1, v ^ p[i]);
    };
    if (rank <= m / 2) {
        for (int i = 0; i < m; ++i)
            if (t[i] > 0)
                p.push_back(t[i]);
        dfs(0, 0);
        ans = cnt;
    } else {
        for (int i = 0; i < m; ++i) {
            if (t[i] == 0) {
                long long res = 1ll << i;
                for (int j = 0; j < m; ++j)
                    if (t[j] >> i & 1)
                        res |= 1ll << j;
                p.push_back(res);
            }
        }
        dfs(0, 0);
        for (int c = 0; c <= m; ++c) {
            std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(m + 1));
            dp[0][0] = 1;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j <= i; ++j) {
                    dp[i + 1][j + 1] += i < c ? -dp[i][j] : dp[i][j];
                    dp[i + 1][j] += dp[i][j];
                }
            }
            for (int i = 0; i <= m; ++i) {
                int res = (dp[m][i] % P + P) % P;
                ans[i] = (ans[i] + 1ll * res * cnt[c]) % P;
            }
        }
        int temp = 1;
        for (int i = 0; i < m - rank; ++i)
            temp = 1ll * temp * INV2 % P;
        for (int i = 0; i <= m; ++i)
            ans[i] = 1ll * ans[i] * temp % P;
    }
    int temp = 1;
    for (int i = 0; i < n - rank; ++i)
        temp = 2 * temp % P;
    for (int i = 0; i <= m; ++i)
        ans[i] = 1ll * ans[i] * temp % P;
    for (int i = 0; i <= m; ++i)
        std::cout << ans[i] << " \n"[i == m];
    return 0;
}