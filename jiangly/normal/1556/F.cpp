#include <bits/stdc++.h>

constexpr int P = 1000000007;
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
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    Z f[1 << n][n];
    Z g[1 << n];
    for (int s = 0; s < (1 << n); s++) {
        Z v = 1;
        for (int i = 0; i < n; i++) {
            if (s >> i & 1) {
                v *= a[i];
            }
        }
        f[s][0] = 1;
        for (int i = 1; i < n; i++) {
            f[s][i] = f[s][i - 1] * v;
        }
        g[s] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((s >> i & 1) && (s >> j & 1)) {
                    g[s] *= a[i] + a[j];
                }
            }
        }
    }
    
    Z dp[1 << n];
    for (int s = 1; s < (1 << n); s++) {
        dp[s] = g[s];
        for (int t = (s - 1) & s; t > 0; t = (t - 1) & s) {
            dp[s] -= dp[t] * g[t] * g[s ^ t] * f[t][__builtin_popcount(s ^ t)];
        }
        dp[s] /= g[s];
    }
    
    Z res = 0;
    int all = (1 << n) - 1;
    for (int s = 1; s < (1 << n); s++) {
        res += dp[s] * __builtin_popcount(s) * g[s] * g[all ^ s] * f[s][__builtin_popcount(all ^ s)];
    }
    res /= g[all];
    
    std::cout << res.val() << "\n";
    
    return 0;
}