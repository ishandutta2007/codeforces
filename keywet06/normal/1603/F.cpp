#include <bits/stdc++.h>

constexpr int P = 998244353;

using int64 = long long;

int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}

template <class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) res *= a;
    }
    return res;
}

struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const { return x; }
    Z operator-() const { return Z(norm(P - x)); }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = int64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

Z p[10000001], f[10000001], inv[10000001];

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;
    if (x == 0) {
        if (n > k) {
            std::cout << "0\n";
        } else {
            Z res = 1, p = power(Z(2), k), r = 1;
            for (int i = 0; i < n; ++i) res *= (p - r), r *= 2;
            std::cout << res.val() << "\n";
        }
        return;
    }
    p[0] = 1;
    Z pn = power(Z(2), n);
    Z inv2 = Z(2).inv();
    Z r = 1, res = 0;
    for (int i = 0; i < k; ++i) {
        res += r;
        r *= (1 - pn) * inv[i + 1];
        pn *= inv2;
        r *= p[k] - p[i + 1];
    }
    std::cout << res.val() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    p[0] = f[0] = 1;
    for (int i = 1; i <= 10000000; ++i) p[i] = 2 * p[i - 1];
    for (int i = 1; i <= 10000000; ++i) f[i] = f[i - 1] * (1 - p[i]);
    Z x = f[10000000].inv();
    for (int i = 10000000; i > 0; --i) inv[i] = x * f[i - 1], x *= (1 - p[i]);
    int T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}