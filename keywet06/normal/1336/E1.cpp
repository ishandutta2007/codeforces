#include <bits/stdc++.h>

const int P = 998244353;

int Pow(int Base, int Exp) {
    int Ret = 1;
    while (Exp > 0) {
        if (Exp % 2 == 1) Ret = 1LL * Ret * Base % P;
        Base = 1LL * Base * Base % P, Exp /= 2;
    }
    return Ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    int cnt = 0;
    std::vector<long long> t(m);
    for (int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;
        for (int j = m - 1; j >= 0; --j) {
            if (a >> j & 1) {
                if (t[j] == 0) {
                    ++cnt, t[j] = a;
                    break;
                }
                a ^= t[j];
            }
        }
    }
    std::vector<int> ans(m + 1);
    for (int i = m - 1; i >= 0; --i)
        for (int j = i - 1; j >= 0; --j)
            if (t[i] >> j & 1) t[i] ^= t[j];
    std::vector<long long> g(m);
    for (int i = 0; i < m; ++i)
        if (t[i] > 0)
            for (int j = 0; j < m; ++j)
                if (t[j] == 0) g[i] = (g[i] << 1) | (t[i] >> j & 1);
    if (cnt <= 25) {
        std::function<void(int, long long)> dfs = [&](int i, long long v) {
            if (i == m) {
                ++ans[__builtin_popcountll(v)];
                return;
            }
            if (t[i] == 0) {
                dfs(i + 1, v);
            } else {
                dfs(i + 1, v);
                dfs(i + 1, v ^ t[i]);
            }
        };
        dfs(0, 0);
    } else {
        std::vector<std::vector<int>> dp(cnt + 1,
                                         std::vector<int>(1 << (m - cnt)));
        dp[0][0] = 1;
        int a = 0;
        for (int i = 0; i < m; ++i) {
            if (t[i] == 0) continue;
            for (int j = a; j >= 0; --j) {
                for (int v = 0; v < (1 << (m - cnt)); ++v) {
                    dp[j + 1][v ^ g[i]] = (dp[j + 1][v ^ g[i]] + dp[j][v]) % P;
                }
            }
            ++a;
        }
        for (int v = 0; v < (1 << (m - cnt)); ++v) {
            int b = __builtin_popcountll(v);
            for (int i = 0; i <= cnt; ++i) {
                ans[i + b] = (ans[i + b] + dp[i][v]) % P;
            }
        }
    }
    int Ret = Pow(2, n - cnt);
    for (int i = 0; i <= m; ++i) ans[i] = 1ll * ans[i] * Ret % P;
    for (int i = 0; i <= m; ++i) std::cout << ans[i] << " \n"[i == m];
    return 0;
}