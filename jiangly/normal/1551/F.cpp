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

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    if (k == 2) {
        std::cout << n * (n - 1) / 2 << "\n";
        return;
    }
    
    Z ans = 0;
    for (int r = 0; r < n; r++) {
        
        std::vector<int> cnt(n);
        std::vector dp(n, std::vector<Z>(k + 1));
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = 1;
        }
        
        std::function<void(int, int, int)> dfs = [&](int u, int p, int d) {
            cnt[d]++;
            for (auto v : e[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u, d + 1);
            }
        };
        
        for (auto x : e[r]) {
            std::fill(cnt.begin(), cnt.end(), 0);
            dfs(x, r, 1);
            
            for (int i = 1; i < n; i++) {
                if (cnt[i] == 0) {
                    break;
                }
                for (int j = k; j > 0; j--) {
                    dp[i][j] += dp[i][j - 1] * cnt[i];
                }
            }
        }
        
        for (int i = 1; i < n; i++) {
            ans += dp[i][k];
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