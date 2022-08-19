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
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    Z ans = 0;
    std::vector dis(n, std::vector<int>(n, n));
    for (int i = 0; i < n; i++) {
        dis[i][i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        dis[u][v] = dis[v][u] = 1;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    std::vector<Z> inv(n + 1);
    for (int i = 1; i <= n; i++) {
        inv[i] = Z(1) / i;
    }
    std::vector dp(n + 1, std::vector<Z>(n + 1));
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * inv[2];
        }
    }
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < u; v++) {
            Z res;
            for (int s = 0; s < n; s++) {
                if (dis[s][u] + dis[u][v] == dis[s][v]) {
                    res += 1;
                } else if (dis[s][v] + dis[u][v] == dis[s][u]) {
                    res += 0;
                } else {
                    int c = dis[s][u] + dis[s][v] - dis[u][v];
                    c /= 2;
                    int a = dis[s][u] - c;
                    int b = dis[s][v] - c;
                    res += dp[a][b];
                }
            }
            res *= inv[n];
            ans += res;
        }
    }
    std::cout << ans.val() << "\n";
    return 0;
}