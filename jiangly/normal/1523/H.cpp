#include <bits/stdc++.h>
constexpr int K = 30;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n), t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        t[i] = std::min(n - 1, a[i] + i);
    }
    int lg = std::__lg(n);
    std::vector dp(lg + 1, std::vector(n, std::vector<int>(K + 1)));
    std::vector<int> stk;
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && t[stk.back()] < t[i]) {
            stk.pop_back();
        }
        stk.push_back(i);
        auto it = std::partition_point(stk.begin(), stk.end(), [&](int j) {
            return j > t[i];
        });
        for (int k = 0; k <= K; k++) {
            if (it != stk.begin() && *(it - 1) <= t[i] + k) {
                it--;
            }
            dp[0][i][k] = *it;
        }
    }
    auto cmpt = [&](int i, int j) {
        return t[i] < t[j];
    };
    for (int j = 0; j < lg; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= K; k++) {
                dp[j + 1][i][k] = i;
                for (int l = 0; l <= k; l++) {
                    dp[j + 1][i][k] = std::max(dp[j + 1][i][k], dp[j][dp[j][i][l]][k - l], cmpt);
                }
            }
        }
    }
    while (q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        l--;
        r--;
        if (l == r) {
            std::cout << "0\n";
            continue;
        }
        if (t[l] + k >= r) {
            std::cout << "1\n";
            continue;
        }
        std::vector<int> f(k + 1, l);
        int ans = 2;
        for (int i = lg; i >= 0; i--) {
            std::vector<int> g(k + 1, l);
            for (int j = 0; j <= k; j++) {
                for (int l = 0; l <= j; l++) {
                    g[j] = std::max(g[j], dp[i][f[l]][j - l], cmpt);
                }
            }
            int v = 0;
            for (int j = 0; j <= k; j++) {
                v = std::max(v, t[g[j]] + k - j);
            }
            if (v >= r) {
                continue;
            }
            ans += 1 << i;
            f = std::move(g);
        }
        std::cout << ans << "\n";
    }
    return 0;
}