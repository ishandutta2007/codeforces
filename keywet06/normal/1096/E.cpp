#include <bits/stdc++.h>

const int P = 998244353;

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
struct Mod {
    int x;
    Mod(int x = 0) : x(norm(x)) {}
    int val() const { return x; }
    Mod operator-() const { return Mod(norm(P - x)); }
    Mod inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Mod &operator*=(const Mod &rhs) {
        x = int64(x) * rhs.x % P;
        return *this;
    }
    Mod &operator+=(const Mod &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Mod &operator-=(const Mod &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Mod &operator/=(const Mod &rhs) { return *this *= rhs.inv(); }
    friend Mod operator*(const Mod &lhs, const Mod &rhs) {
        Mod res = lhs;
        res *= rhs;
        return res;
    }
    friend Mod operator+(const Mod &lhs, const Mod &rhs) {
        Mod res = lhs;
        res += rhs;
        return res;
    }
    friend Mod operator-(const Mod &lhs, const Mod &rhs) {
        Mod res = lhs;
        res -= rhs;
        return res;
    }
    friend Mod operator/(const Mod &lhs, const Mod &rhs) {
        Mod res = lhs;
        res /= rhs;
        return res;
    }
};

const int N = 1e4;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int p, r, s;
    std::cin >> p >> s >> r;
    std::vector<Mod> fac(N + 1), invfac(N + 1), inv(N + 1);
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * i;
    invfac[N] = fac[N].inv();
    for (int i = N; i > 0; i--) {
        invfac[i - 1] = invfac[i] * i;
        inv[i] = invfac[i] * fac[i - 1];
    }
    auto binom = [&](int n, int m) { return fac[n] * invfac[m] * invfac[n - m]; };
    Mod ways = binom(s - r + p - 1, p - 1);
    Mod sum = 0;
    for (int x = r; x <= s; ++x) {
        for (int c = 1; c * x <= s && c <= p; ++c) {
            Mod res = 0;
            int v = p - c;
            for (int i = 0; (i + c) * x <= s && i + c <= p; ++i) {
                int t = s - (i + c) * x;
                res += binom(p - c, i) * (i % 2 == 0 ? 1 : -1) * (v == 0 ? t == 0 : binom(t + v - 1, v - 1));
            }
            res *= binom(p - 1, c - 1);
            sum += res * inv[c];
        }
    }
    Mod ans = sum / ways;
    std::cout << ans.val() << "\n";
    return 0;
}