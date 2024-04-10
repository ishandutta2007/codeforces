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

constexpr int N = 2E5;

int fen[N];

void add(int x, int y) {
    for (int i = x + 1; i <= N; i += i & -i) {
        fen[i - 1] += y;
    }
}

int find(int k) {
    int x = 0, s = 0;
    for (int i = 1 << 17; i > 0; i >>= 1) {
        if (x + i <= N && x + i - s - fen[x + i - 1] <= k) {
            x += i;
            s += fen[x - 1];
        }
    }
    return x;
}

Z fac[2 * N + 1], invfac[2 * N + 1];

Z binom(int n, int m) {
    return fac[n] * invfac[m] * invfac[n - m];
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    int x[m], y[m];
    
    for (int i = 0; i < m; i++) {
        std::cin >> x[i] >> y[i];
        y[i]--;
    }
    
    std::set<int> s;
    
    for (int i = m - 1; i >= 0; i--) {
        s.insert(find(y[i] + 1));
        y[i] = find(y[i]);
        add(y[i], 1);
    }
    
    for (int i = 0; i < m; i++) {
        add(y[i], -1);
    }
    
    Z res = binom(n + n - 1 - s.size(), n);
    
    std::cout << res.val() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    fac[0] = 1;
    for (int i = 1; i <= 2 * N; i++) {
        fac[i] = fac[i - 1] * i;
    }
    invfac[2 * N] = fac[2 * N].inv();
    for (int i = 2 * N; i > 0; i--) {
        invfac[i - 1] = invfac[i] * i;
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}