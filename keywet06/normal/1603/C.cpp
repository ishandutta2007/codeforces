#include <bits/stdc++.h>

const int P = 998244353;

using int64 = long long;

int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}

template <class T>
T Pow(T a, int b) {
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
        return Pow(*this, P - 2);
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

Z f[100001], g[100001];

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    Z res;
    for (int i = n - 2; i >= 0; --i) {
        int x = a[i];
        f[a[i + 1]] += 1;
        for (int l = 1, r; l <= a[i + 1]; l = r + 1) {
            int v = a[i + 1] / l;
            r = a[i + 1] / v;
            int t = (x + v - 1) / v;
            res += f[v] * (t - 1) * (i + 1);
            g[x / t] += f[v];
            f[v] = 0;
        }
        for (int l = 1, r; l <= a[i]; l = r + 1) {
            int v = a[i] / l;
            r = a[i] / v;
            f[v] = g[v];
            g[v] = 0;
        }
    }
    for (int l = 1, r; l <= a[0]; l = r + 1) {
        int v = a[0] / l;
        r = a[0] / v;
        f[v] = 0;
    }
    std::cout << res.val() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}