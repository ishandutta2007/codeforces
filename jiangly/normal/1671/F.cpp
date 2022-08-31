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

Z f[12][12][35][13];
Z inv[12];

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;
    
    Z ans = 0;
    for (int l = 1; l <= n && l <= 34; l++) {
        Z b = 1;
        for (int z = 0; z <= l && z <= 12; z++) {
            if (z == 0) {
                if (n == l) {
                    ans += f[k][x][l][z];
                }
            } else {
                if (z > 1) {
                    b = b * (n - l + z - 1) * inv[z - 1];
                }
                ans += f[k][x][l][z] * b;
            }
        }
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 1; i <= 11; i++) {
        inv[i] = Z(i).inv();
    }
    
    Z dp[12][12][35][13][12] = {};
    dp[0][0][1][0][0] = 1;
    for (int k = 0; k <= 11; k++) {
        for (int x = 0; x <= 11; x++) {
            for (int l = 1; l <= 34; l++) {
                for (int z = 0; z <= 12; z++) {
                    for (int y = 0; y <= 11; y++) {
                        if (dp[k][x][l][z][y].val() == 0) {
                            continue;
                        }
                        f[k][x][l][z] += dp[k][x][l][z][y];
                        for (int a = 0; a <= 11 && a <= l; a++) {
                            if (l > 11 && a == 0 && y == 0) {
                                continue;
                            }
                            int nk = k + a;
                            int nx = x + (a > y);
                            int nl = l + 1;
                            int nz = z + (l >= 11 && a == 0);
                            if (nk <= 11) {
                                assert(nx <= 11);
                                assert(nl <= 34);
                                assert(nz <= 12);
                                dp[nk][nx][nl][nz][a] += dp[k][x][l][z][y];
                            }
                        }
                    }
                }
            }
        }
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}