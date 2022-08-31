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
};
void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> minp(n + 1), primes;
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (i % p == 0) {
                break;
            }
        }
    }
    
    std::vector<std::vector<std::array<int, 3>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        std::cin >> u >> v >> x >> y;
        u--;
        v--;
        int g = std::gcd(x, y);
        x /= g;
        y /= g;
        adj[u].push_back({v, x, y});
        adj[v].push_back({u, y, x});
    }
    
    std::vector<int> c(n + 1), mn(n + 1);
    Z ans = 0;
    auto dfs = [&](auto self, auto u, auto p, auto val) -> void {
        ans += val;
        for (auto [v, x, y] : adj[u]) {
            if (v == p) {
                continue;
            }
            for (int i = x; i > 1; i /= minp[i]) {
                c[minp[i]]--;
                mn[minp[i]] = std::min(mn[minp[i]], c[minp[i]]);
            }
            for (int i = y; i > 1; i /= minp[i]) {
                c[minp[i]]++;
            }
            self(self, v, u, val / x * y);
            for (int i = x; i > 1; i /= minp[i]) {
                c[minp[i]]++;
            }
            for (int i = y; i > 1; i /= minp[i]) {
                c[minp[i]]--;
            }
        }
    };
    dfs(dfs, 0, -1, Z(1));
    
    for (int i = 1; i <= n; i++) {
        ans *= power(Z(i), -mn[i]);
    }
    
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