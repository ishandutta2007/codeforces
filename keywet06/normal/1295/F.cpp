#include <bits/stdc++.h>

const int P = 998244353;

int Pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = 1LL * res * a % P;
        a = 1LL * a * a % P, b >>= 1;
    }
    return res;
}

int n;

std::vector<int> l, r, v, inv, dp;
std::vector<std::vector<int>> c;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    l.resize(n);
    r.resize(n);
    v.reserve(2 * n);
    inv.resize(n + 1);
    for (int i = 1; i <= n; ++i) inv[i] = Pow(i, P - 2);
    int total = 1;
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i] >> r[i];
        ++r[i];
        v.push_back(l[i]);
        v.push_back(r[i]);
        total = 1LL * total * (r[i] - l[i]) % P;
    }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; ++i) {
        l[i] = std::lower_bound(v.begin(), v.end(), l[i]) - v.begin();
        r[i] = std::lower_bound(v.begin(), v.end(), r[i]) - v.begin();
    }
    c.assign(v.size() - 1, std::vector<int>(n + 1));
    for (int i = 0; i < int(v.size()) - 1; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            c[i][j] =
                1LL * c[i][j - 1] * (j - 1 + v[i + 1] - v[i]) % P * inv[j] % P;
        }
    }
    dp.resize(n + 1);
    dp[0] = 1;
    for (int i = int(v.size()) - 1; i >= 0; --i) {
        for (int a = n - 1; a >= 0; --a) {
            for (int b = a; b < n; ++b) {
                if (i < l[b] || i >= r[b]) break;
                dp[b + 1] = (dp[b + 1] + 1LL * dp[a] * c[i][b - a + 1]) % P;
            }
        }
    }
    std::cout << 1LL * dp[n] * Pow(total, P - 2) % P << "\n";
    return 0;
}