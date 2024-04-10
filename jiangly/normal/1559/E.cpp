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
    
    int n, m;
    std::cin >> n >> m;
    
    int l[n], r[n];
    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
        l[i]--;
    }
    
    int mu[m + 1] = {};
    mu[1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 2 * i; j <= m; j += i) {
            mu[j] -= mu[i];
        }
    }
    
    Z res = 0;
    
    for (int d = 1; d <= m; d++) {
        if (mu[d] == 0) {
            continue;
        }
        
        int s = m / d;
        
        int suml = 0;
        for (int i = 0; i < n; i++) {
            suml += l[i] / d + 1;
        }
        
        if (suml > s) {
            continue;
        }
        
        int t = s - suml;
        Z f[t + 1];
        f[0] = 1;
        
        for (int i = 0; i < n; i++) {
            int v = r[i] / d - l[i] / d;
            for (int j = 1; j <= t; j++) {
                f[j] += f[j - 1];
            }
            for (int j = t; j >= v; j--) {
                f[j] -= f[j - v];
            }
        }
        
        Z sum = std::accumulate(f, f + t + 1, Z(0));
        
        res += sum * mu[d];
    }
    
    std::cout << res.val() << "\n";
    
    return 0;
}