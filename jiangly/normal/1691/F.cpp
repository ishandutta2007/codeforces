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
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<Z> binom(n + 1);
    binom[k] = 1;
    for (int i = k + 1; i <= n; i++) {
        binom[i] = binom[i - 1] * i / (i - k);
    }
    Z ans = binom[n] * n * n;
    
    std::vector<int> siz(n);
    std::vector<Z> f(n);
    std::function<void(int, int)> dfs1 = [&](int u, int p) {
        siz[u] = 1;
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs1(v, u);
            siz[u] += siz[v];
            f[u] -= binom[siz[v]];
        }
        f[u] += binom[siz[u]];
        if (u != 0) {
            ans += f[u] * siz[u] * (n - siz[u]);
            ans -= binom[siz[u]] * n;
        }
    };
    dfs1(0, -1);
    
    std::function<void(int, int)> dfs2 = [&](int u, int p) {
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            ans += (f[u] - binom[siz[u]] + binom[siz[v]] - binom[n - siz[u]] + binom[n - siz[v]])
                * siz[v] * (n - siz[v]);
            ans -= binom[n - siz[v]] * n;
            dfs2(v, u);
        }
    };
    dfs2(0, -1);
    
    std::cout << ans << "\n";
    
    return 0;
}