#include <bits/stdc++.h>

const int P = 1000000007;

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int m;
    std::cin >> m;
    std::vector<int> c(m);
    for (int i = 0; i < m; ++i) std::cin >> c[i];
    int maxC = *std::max_element(c.begin(), c.end());
    std::vector<int> cnt(maxC * 2 - 1);
    for (int i = 0; i < m; ++i) {
        ++cnt[maxC - c[i]];
        if (maxC + c[i] < maxC * 2 - 1) --cnt[maxC + c[i]];
    }
    for (int i = 2; i < maxC * 2 - 1; ++i) cnt[i] += cnt[i - 2];
    std::vector<Z> fac(m + 1);
    fac[0] = 1;
    for (int i = 1; i <= m; ++i) fac[i] = fac[i - 1] * i;
    Z ways = 1;
    for (int i = 0; i < 2 * maxC - 1; ++i) ways *= fac[cnt[i]];
    Z sum = 0;
    int64 N = 0;
    for (int i = 0; i < 2 * maxC - 1; ++i) {
        sum += Z(cnt[i] * (N + N + cnt[i] - 1) / 2 % P) * (i - maxC + 1);
        N += cnt[i];
    }
    std::cout << sum.val() << ' ' << ways.val() << '\n';
    return 0;
}