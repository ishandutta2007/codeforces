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

constexpr int M = 12252240;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    std::cin >> a[0];
    int x, y, k, m;
    std::cin >> x >> y >> k >> m;
    
    Z ans;
    
    for (int i = 1; i < n; i++) {
        a[i] = (1LL * a[i - 1] * x + y) % m;
    }
    for (int i = 0; i < n; i++) {
        ans += a[i] - a[i] % M;
    }
    
    ans *= Z(k) / n;
    
    std::vector<Z> f(M);
    for (int i = 0; i < n; i++) {
        f[a[i] % M] += 1;
    }
    
    auto inv = Z(n).inv();
    for (int i = 1; i <= k; i++) {
        std::vector<Z> g(M);
        for (int j = 0; j < M; j++) {
            ans += f[j] * j * inv;
            g[j - j % i] += f[j] * inv;
            g[j] += f[j] * (1 - inv);
        }
        f = std::move(g);
    }
    ans *= power(Z(n), k);
    std::cout << ans.val() << "\n";
    
    return 0;
}