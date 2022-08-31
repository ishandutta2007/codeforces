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

constexpr int X = 1e6;

Z inv[50], C[50][50];

Z eval(const std::vector<Z> &f, Z x) {
    Z ans = 0;
    for (int i = int(f.size()) - 1; i >= 0; i--) {
        ans = ans * x + f[i];
    }
    return ans;
}

std::vector<Z> integral(const std::vector<Z> &f) {
    std::vector<Z> g(f.size() + 1);
    for (int i = 0; i < int(f.size()); i++) {
        g[i + 1] = f[i] * inv[i + 1];
    }
    return g;
}

Z integral(std::vector<Z> f, Z l, Z r) {
    f = integral(f);
    return eval(f, r) - eval(f, l);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 1; i < 50; i++) {
        inv[i] = Z(i).inv();
    }
    for (int i = 0; i < 50; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    
    auto invX = Z(X).inv();
    
    int n;
    std::cin >> n;
    
    std::vector<int> p;
    for (int i = 0; i <= n + 1; i++) {
        p.push_back(i * X);
    }
    
    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        double v;
        std::cin >> v;
        x[i] = v * X + 0.5;
        for (int j = 0; j < n; j++) {
            p.push_back(x[i] % X + j * X);
        }
    }
    
    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(), p.end()), p.end());
    int m = p.size() - 1;
    
    std::vector<std::vector<Z>> f(m);
    for (int i = 0; i < m; i++) {
        if (p[i] < x[0] && p[i] < X) {
            f[i] = {0, 1};
        } else {
            f[i] = {std::min(x[0], X) * invX};
        }
    }
    
    for (int i = 1; i < n; i++) {
        std::vector<std::vector<Z>> g(m);
        std::vector<Z> h(m);
        for (int j = 0; j < m; j++) {
            h[j] = integral(f[j], p[j] * invX, p[j + 1] * invX);
        }
        for (int j = 0; j < m; j++) {
            if (p[j] < x[i]) {
                g[j] = integral(f[j]);
                g[j][0] -= eval(g[j], p[j] * invX);
                for (int k = 0; k < j; k++) {
                    if (p[k] >= p[j + 1] - X) {
                        g[j][0] += h[k];
                    } else if (p[k] >= p[j] - X) {
                        auto a = integral(f[k]);
                        g[j][0] += eval(a, p[k + 1] * invX);
                        if (g[j].size() < a.size()) {
                            g[j].resize(a.size());
                        }
                        for (int x = 0; x < int(a.size()); x++) {
                            for (int y = 0; y <= x; y++) {
                                g[j][y] += ((y - x) % 2 == 0 ? -1 : 1) * C[x][y] * a[x];
                            }
                        }
                    }
                }
            } else {
                g[j] = {eval(g[j - 1], p[j] * invX)};
            }
        }
        f = g;
    }
    
    std::cout << f.back()[0].val() << "\n";
    
    return 0;
}