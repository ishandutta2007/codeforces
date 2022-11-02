#include <bits/stdc++.h>

const int P = 998244353;

int power(int a, int b) {
    int res = 1;
    for (; b > 0; b /= 2, a = int64_t(a) * a % P) {
        if (b % 2 == 1) {
            res = int64_t(res) * a % P;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::vector<int> fac(n + 1), invFac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = int64_t(fac[i - 1]) * i % P;
    }
    invFac[n] = power(fac[n], P - 2);
    for (int i = n; i > 0; --i) {
        invFac[i - 1] = int64_t(invFac[i]) * i % P;
    }
    int cnt[3][2]{};
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'w') {
            ++cnt[0][i % 2];
        } else if (s[i] == 'b') {
            ++cnt[1][i % 2];
        } else {
            ++cnt[2][i % 2];
        }
    }
    auto binom = [&](int n, int m) -> int {
        if (n < m || m < 0 || n < 0) {
            return 0;
        }
        return int64_t(fac[n]) * invFac[m] % P * invFac[n - m] % P;
    };
    auto calc = [&]() {
        int ans = 0;
        for (int t = 0; t < 2; ++t) {
            int a[2][2]{};
            for (int i = n; i > 0; --i) {
                for (int j = 0; j < 2; ++j) {
                    a[i % 2][j] =
                        (a[i % 2][j] + binom(cnt[2][j], i - cnt[t][j])) % P;
                }
                for (int j = 0; j < 2; ++j) {
                    ans = (ans + int64_t(a[j][0]) * a[j][1]) % P;
                }
            }
        }
        ans = int64_t(ans) * power((P + 1) / 2, cnt[2][0] + cnt[2][1] - 1) % P;
        ans = (n / 2 - ans + P) % P;
        ans = int64_t(ans) * (P + 1) / 2 % P;
        return ans;
    };
    std::cout << calc() << "\n";
    return 0;
}