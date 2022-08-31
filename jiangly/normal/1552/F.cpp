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
    
    std::vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i] >> s[i];
    }
    
    std::vector<Z> f(n), g(n);
    g[0] = x[0] - y[0];
    f[0] = s[0] == 1 ? g[0] : 0;
    std::vector<Z> sum(n + 1);
    sum[1] = g[0];
    
    for (int i = 1; i < n; i++) {
        int v = std::lower_bound(x.begin(), x.end(), y[i]) - x.begin();
        g[i] = x[i] - y[i] + sum[i] - sum[v];
        sum[i + 1] = sum[i] + g[i];
        f[i] = f[i - 1] + (s[i] == 1 ? g[i] : 0);
    }
    
    auto ans = x[n - 1] + 1 + f[n - 1];
    
    std::cout << ans.val() << "\n";
    
    return 0;
}