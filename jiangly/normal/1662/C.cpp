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

constexpr int N = 200;

using Matrix = std::array<std::array<Z, N>, N>;

Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    
    Matrix f;
    for (int i = 0; i < n; i++) {
        f[i + n][i] = 1;
        f[i][i + n] = 1;
    }
    
    auto add = [&](int x, int y) {
        f[x][y] += 1;
        f[y + n][y] -= 1;
    };
    
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        add(a, b);
        add(b, a);
    }
    
    auto get = [&](auto k) {
        if (k < 0) {
            return Z(0);
        }
        Matrix g, a = f;
        for (int i = 0; i < n + n; i++) {
            g[i][i] = 1;
        }
        for (; k; k /= 2, a = a * a) {
            if (k & 1) {
                g = a * g;
            }
        }
        Z ans = 0;
        for (int i = 0; i < n; i++) {
            ans += g[i][i];
        }
        return ans;
    };
    
    auto ans = get(k) - get(k - 2);
    std::cout << ans.val() << "\n";
    
    return 0;
}