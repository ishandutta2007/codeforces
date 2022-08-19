#include <bits/stdc++.h>
using i64 = long long;
constexpr int P = 998244353;
int power(int a, int b) {
    int res = 1;
    for (; b > 0; b /= 2, a = i64(a) * a % P) {
        if (b % 2 == 1) {
            res = i64(res) * a % P;
        }
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<i64> x(1);
    std::cin >> x[0];
    for (int i = 0; i < n; i++) {
        int d;
        std::cin >> d;
        if (d != 0) {
            x.push_back(x.back() + d);
        }
    }
    i64 ans = 0;
    n = x.size();
    std::vector<int> fac(n + 1), invfac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = i64(fac[i - 1]) * i % P;
    }
    for (int i = 0; i <= n; i++) {
        invfac[i] = power(fac[i], P - 2);
    }
    std::vector<i64> len(n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            len[i] = std::max(len[i], x[j] - x[i] + 1);
        }
        ans = std::max(ans, len[i]);
    }
    if (ans == 1) {
        std::cout << "1 " << (x[0] - x[n - 1] + 1) % P << "\n";
        return 0;
    }
    auto solve = [&](std::vector<i64> x) {
        int n = x.size();
        std::vector<bool> type(n);
        std::vector<std::tuple<i64, int, bool>> events;
        events.emplace_back(x[0], 0, true);
        events.emplace_back(x[0] + 1, 0, false);
        for (int i = 1; i < n; i++) {
            if (x[i - 1] < x[i]) {
                type[i] = true;
                events.emplace_back(x[i - 1] + 1, i, true);
                events.emplace_back(x[i] + 1, i, false);
            } else {
                events.emplace_back(x[i], i, true);
                events.emplace_back(x[i - 1], i, false);
            }
        }
        std::sort(events.begin(), events.end());
        i64 last = x[0] + 1;
        std::vector<bool> able(n);
        std::vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if (x[i] == x[0]) {
                dp[i] = 1;
            }
        }
        for (auto [v, i, t] : events) {
            v = std::min(std::max(x[0] + 1, v), x[0] + ans);
            i64 times = v - last;
            if (times == 0) {
                able[i] = t;
                continue;
            }
            times--;
            std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
            for (int i = 0; i <= n; i++) {
                f[i][0] = 1;
                for (int j = 1; j <= n; j++) {
                    f[i][j] = i64(f[i][j - 1]) * (times % P - i + j + P) % P;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                if (!able[i]) {
                    dp[i] = 0;
                    continue;
                }
                int newdp = 0;
                for (int j = 0; j <= i; j++) {
                    int a = 0, b = 0;
                    for (int k = j; k <= i; k++) {
                        if (able[k]) {
                            if (type[k]) {
                                b++;
                            } else {
                                a++;
                                if (k == i) {
                                    a--;
                                }
                                if (k == j) {
                                    a--;
                                }
                            }
                        }
                    }
                    int coef = 0;
                    for (int k = 0; k <= a && k <= times; k++) {
                        coef = (coef + i64(fac[a]) * invfac[k] % P * invfac[a - k] % P * (b == 0 ? i64(k == times) : i64(f[k][b - 1]) * invfac[b - 1] % P)) % P;
                    }
                    newdp = (newdp + i64(dp[j]) * coef) % P;
                }
                dp[i] = newdp;
            }
            last = v;
            able[i] = t;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + dp[i]) % P;
        }
        return res;
    };
    int ways = 0;
    int last = -1;
    i64 val = 1e18;
    for (int i = 0; i < n; i++) {
        if (len[i] == ans && x[i] < val) {
            if (last != -1) {
                ways = (ways + solve(std::vector<i64>(x.begin() + last, x.begin() + i))) % P;
            }
            last = i;
            val = x[i];
        }
    }
    ways = (ways + solve(std::vector<i64>(x.begin() + last, x.begin() + n))) % P;
    std::cout << ans << " " << ways << "\n";
    return 0;
}