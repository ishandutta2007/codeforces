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

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        c[a[i]]++;
    }
    
    std::vector<Z> fac(n + 1), invfac(n + 1), inv(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
    invfac[n] = fac[n].inv();
    for (int i = n; i; i--) {
        invfac[i - 1] = invfac[i] * i;
        inv[i] = invfac[i] * fac[i - 1];
    }
    
    if (a == std::vector(n, a[0])) {
        std::cout << "1\n";
        return;
    }
    
    Z ans = 0;
    
    int g = 0;
    for (int i = 0; i < n; i++) {
        g = std::gcd(g, c[i]);
    }
    std::vector<Z> f(n + 1), h(n + 1);
    for (int i = 1; i <= g; i++) {
        if (g % i == 0) {
            h[i] = fac[n / i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (c[i] >= 2) {
            for (int j = 1; j <= g; j++) {
                if (g % j == 0) {
                    f[j] += Z(n) * (c[i] / j) * (c[i] / j - 1) * inv[n / j] * inv[n / j - 1];
                    h[j] *= invfac[c[i] / j];
                }
            }
        }
    }
    Z ways = 0;
    for (int i = g; i; i--) {
        if (g % i == 0) {
            f[i] *= h[i];
            for (int j = 2 * i; j <= g; j += i) {
                f[i] -= f[j];
                h[i] -= h[j];
            }
            ans += f[i] * i;
            ways += h[i] * i;
        }
    }
    ans /= ways;
    ans = n - ans;
    std::cout << ans.val() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}