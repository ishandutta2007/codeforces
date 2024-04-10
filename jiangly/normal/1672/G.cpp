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
};

void update(Z f[2], std::array<Z, 2> g) {
    Z r[2] = {f[0], f[1]};
    f[0] = r[0] * g[0] + r[1] * g[1];
    f[1] = r[0] * g[1] + r[1] * g[0];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    if (n % 2 == 0 && m % 2 == 0) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                k += s[i][j] == '?';
            }
        }
        std::cout << power(Z(2), k).val() << "\n";
        return 0;
    }
    
    if (m % 2 == 0) {
        std::vector<std::string> b(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j] += s[i][j];
            }
        }
        std::swap(n, m);
        s = b;
    }
    
    if (n % 2 == 0) {
        Z ans = 0;
        for (int t = 0; t < 2; t++) {
            Z res = 1;
            for (int i = 0; i < n; i++) {
                int k = 0;
                int v = 0;
                for (int j = 0; j < m; j++) {
                    if (s[i][j] == '?') {
                        k++;
                    } else {
                        v ^= (s[i][j] - '0');
                    }
                }
                if (k == 0) {
                    res *= (v == t);
                } else {
                    res *= power(Z(2), k - 1);
                }
            }
            ans += res;
        }
        std::cout << ans.val() << "\n";
        return 0;
    }
    
    Z ans = 0;
    for (int t = 0; t < 2; t++) {
        auto b = s;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (s[i][j] == '1') {
                    if (b[0][0] != '?') {
                        b[0][0] ^= 1;
                    }
                    if (b[i][0] != '?') {
                        b[i][0] ^= 1;
                    }
                    if (b[0][j] != '?') {
                        b[0][j] ^= 1;
                    }
                    b[i][j] ^= 1;
                }
            }
        }
        for (int c = 0; c < 2; c++) {
            if (b[0][0] != '0' + !c) {
                Z dp[2] = {1, 0};
                
                std::vector<bool> vis(n + m);
                for (int x = 1; x < n + m; x++) {
                    if (x == n) {
                        continue;
                    }
                    if (vis[x]) {
                        continue;
                    }
                    
                    Z dpr[2] = {1, 0}, dpc[2] = {1, 0};
                    int edge = 0, ver = 0;
                    auto dfs = [&](auto dfs, int u) -> void {
                        vis[u] = true;
                        ver++;
                        if (u < n) {
                            update(dpr, {b[u][0] != '1', b[u][0] != '0'});
                            for (int j = 1; j < m; j++) {
                                if (b[u][j] == '?') {
                                    edge++;
                                    if (!vis[n + j]) {
                                        dfs(dfs, n + j);
                                    }
                                }
                            }
                        } else {
                            update(dpc, {b[0][u - n] != '1', b[0][u - n] != '0'});
                            for (int i = 1; i < n; i++) {
                                if (b[i][u - n] == '?') {
                                    if (!vis[i]) {
                                        dfs(dfs, i);
                                    }
                                }
                            }
                        }
                    };
                    dfs(dfs, x);
                    Z v = power(Z(2), edge - ver + 1);
                    update(dp, {dpr[0] * dpc[0] * v, dpr[1] * dpc[1] * v});
                }
                
                ans += dp[c];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] != '?' && (i == 0 || j == 0)) {
                    s[i][j] ^= 1;
                }
            }
        }
    }
    std::cout << ans.val() << "\n";
    
    return 0;
}