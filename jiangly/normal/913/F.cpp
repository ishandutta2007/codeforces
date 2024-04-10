#include <bits/stdc++.h>

constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
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
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
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
    
    int n;
    std::cin >> n;
    
    int a, b;
    std::cin >> a >> b;
    
    auto p = Z(a) / b;
    
    std::vector<Z> p1(n + 1), p2(n + 1);
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p1[i] = p1[i - 1] * p;
        p2[i] = p2[i - 1] * (1 - p);
    }
    
    std::vector<Z> f(n + 1), scc(n + 1), g(n + 1);
    scc[1] = 1;
    g[0] = g[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            g[j] = g[j - 1] * p2[i - j] + g[j] * p1[j];
        }
        scc[i] = 1;
        for (int j = 1; j < i; j++) {
            scc[i] -= g[j] * scc[j];
        }
        for (int j = 1; j < i; j++) {
            f[i] += g[j] * scc[j] * (f[j] + f[i - j] - (i - j) * (i - j - 1) / 2);
        }
        f[i] = (f[i] + i * (i - 1) / 2) / (1 - scc[i]);
    }
    
    std::cout << f[n].val() << "\n";
    
    return 0;
}