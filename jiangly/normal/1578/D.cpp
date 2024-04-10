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

template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};


void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });
    
    int t;
    std::cin >> t;
    
    std::vector<bool> vis(n);
    for (int i = 0; i < t; i++) {
        int x;
        std::cin >> x;
        x--;
        vis[x] = true;
    }
    
    std::vector<int> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (vis[p[i]]) {
            suf[i] = b[p[i]];
        }
        suf[i] = std::max(suf[i], suf[i + 1]);
    }
    
    for (int i = 0; i < n; i++) {
        if (suf[i] > b[p[i]]) {
            vis[p[i]] = true;
        }
    }
    
    std::vector<Z> dp(n);
    Fenwick<Z> fen(2 * n);
    Z res = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[p[i]] = fen.sum(b[p[i]]) + 1;
        fen.add(b[p[i]], dp[p[i]]);
        if (vis[p[i]]) {
            res += dp[p[i]];
        }
    }
    std::cout << res.val() << "\n";
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}