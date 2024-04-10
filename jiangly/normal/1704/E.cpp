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

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<std::vector<int>> adj(n);
    std::vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        deg[y]++;
    }
    
    std::vector<int> q;
    for (int i = 0; i < n; i++) {
        if (!deg[i]) {
            q.push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        int x = q[i];
        for (auto y : adj[x]) {
            if (!--deg[y]) {
                q.push_back(y);
            }
        }
    }
    int ans = 0;
    while (ans < n && a != std::vector(n, 0)) {
        for (int i = n - 1; i >= 0; i--) {
            int x = q[i];
            if (a[x]) {
                a[x]--;
                for (auto y : adj[x]) {
                    a[y]++;
                }
            }
        }
        ans++;
    }
    
    if (a == std::vector(n, 0)) {
        std::cout << ans << "\n";
        return;
    }
    
    std::vector<Z> dp(a.begin(), a.end());
    for (auto x : q) {
        for (auto y : adj[x]) {
            dp[y] += dp[x];
        }
    }
    std::cout << dp[q[n - 1]] + ans << "\n";
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