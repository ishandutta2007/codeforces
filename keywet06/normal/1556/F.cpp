#include <bits/stdc++.h>

const int P = 1000000007;

using int64 = long long;

int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}

template <class _Tp>
_Tp power(_Tp a, int b) {
    _Tp res = 1;
    for (; b; b >>= 1, a *= a) {
        if (b & 1) res *= a;
    }
    return res;
}

struct modint {
    int x;
    modint(int x = 0) : x(norm(x)) {}
    int val() const { return x; }
    modint operator-() const { return modint(norm(P - x)); }
    modint inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    modint &operator*=(const modint &rhs) {
        x = int64(x) * rhs.x % P;
        return *this;
    }
    modint &operator+=(const modint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    modint &operator-=(const modint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    modint &operator/=(const modint &rhs) { return *this *= rhs.inv(); }
    friend modint operator*(const modint &lhs, const modint &rhs) {
        modint res = lhs;
        res *= rhs;
        return res;
    }
    friend modint operator+(const modint &lhs, const modint &rhs) {
        modint res = lhs;
        res += rhs;
        return res;
    }
    friend modint operator-(const modint &lhs, const modint &rhs) {
        modint res = lhs;
        res -= rhs;
        return res;
    }
    friend modint operator/(const modint &lhs, const modint &rhs) {
        modint res = lhs;
        res /= rhs;
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    modint f[1 << n][n];
    modint g[1 << n];
    for (int s = 0; s < (1 << n); ++s) {
        modint v = 1;
        for (int i = 0; i < n; ++i) {
            if (s >> i & 1) v *= a[i];
        }
        f[s][0] = 1;
        for (int i = 1; i < n; ++i) f[s][i] = f[s][i - 1] * v;
        g[s] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((s >> i & 1) && (s >> j & 1)) g[s] *= a[i] + a[j];
            }
        }
    }
    modint dp[1 << n];
    for (int s = 1; s < (1 << n); ++s) {
        dp[s] = g[s];
        for (int t = (s - 1) & s; t > 0; t = (t - 1) & s) {
            dp[s] -= dp[t] * g[t] * g[s ^ t] * f[t][__builtin_popcount(s ^ t)];
        }
        dp[s] /= g[s];
    }
    modint res = 0;
    int all = (1 << n) - 1;
    for (int s = 1; s < (1 << n); ++s) {
        res += dp[s] * __builtin_popcount(s) * g[s] * g[all ^ s] *
               f[s][__builtin_popcount(all ^ s)];
    }
    res /= g[all];
    std::cout << res.val() << "\n";
    return 0;
}