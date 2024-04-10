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
T power(T a, i64 b) {
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
    Z(i64 x) : x(norm(x % P)) {}
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
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    
    std::array<std::array<Z, 8>, 8> dp{};
    dp[0][0] = 1;
    for (auto c : s) {
        int d = c - '0';
        std::array<std::array<Z, 8>, 8> g{};
        for (int m = 0; m < 8; m++) {
            for (int l = 0; l < 8; l++) {
                for (int x = 0; x < 8; x++) {
                    if (!d && (x & ~l)) {
                        continue;
                    }
                    int t = m;
                    if (x == 1 || x == 6) {
                        t |= 1;
                    }
                    if (x == 2 || x == 5) {
                        t |= 2;
                    }
                    if (x == 4 || x == 3) {
                        t |= 4;
                    }
                    g[t][d ? (l | (7 ^ x)) : l] += dp[m][l];
                }
            }
        }
        dp = g;
    }
    
    Z ans = 0;
    for (int i = 0; i < 8; i++) {
        ans += dp[7][i];
    }
    std::cout << ans << "\n";
    
    return 0;
}