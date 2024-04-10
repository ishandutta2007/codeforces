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
};
void solve() {
    int n, m;
    std::cin >> n >> m;
    
    int s, t;
    std::cin >> s >> t;
    s--;
    t--;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto bfs = [&](auto s) {
        
        std::vector<int> dis(n, -1);
        std::queue<int> q;
        q.push(s);
        dis[s] = 0;
        
        std::vector<Z> f(n);
        f[s] = 1;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (auto v : adj[u]) {
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
                if (dis[v] == dis[u] + 1) {
                    f[v] += f[u];
                }
            }
        }
        
        return std::pair(dis, f);
    };
    
    auto [ds, fs] = bfs(s);
    auto [dt, ft] = bfs(t);
    
    Z ans = fs[t];
    for (auto i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            if (ds[i] + dt[j] == ds[t] && ds[i] == ds[j]) {
                ans += fs[i] * ft[j];
            }
        }
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