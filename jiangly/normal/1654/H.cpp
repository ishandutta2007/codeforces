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

std::vector<int> rev;
std::vector<Z> roots{0, 1};
void dft(std::vector<Z> &a) {
    int n = a.size();
    
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; i++) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (rev[i] < i) {
            std::swap(a[i], a[rev[i]]);
        }
    }
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            Z e = power(Z(3), (P - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); i++) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = roots[i] * e;
            }
            k++;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                Z u = a[i + j];
                Z v = a[i + j + k] * roots[k + j];
                a[i + j] = u + v;
                a[i + j + k] = u - v;
            }
        }
    }
}
void idft(std::vector<Z> &a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    Z inv = (1 - P) / n;
    for (int i = 0; i < n; i++) {
        a[i] *= inv;
    }
}
struct Poly {
    std::vector<Z> a;
    Poly() {}
    Poly(const std::vector<Z> &a) : a(a) {}
    Poly(const std::initializer_list<Z> &a) : a(a) {}
    int size() const {
        return a.size();
    }
    void resize(int n) {
        a.resize(n);
    }
    Z operator[](int idx) const {
        if (idx < 0 || idx >= size()) {
            return 0;
        }
        return a[idx];
    }
    Z &operator[](int idx) {
        return a[idx];
    }
    Poly mulxk(int k) const {
        auto b = a;
        b.insert(b.begin(), k, 0);
        return Poly(b);
    }
    Poly modxk(int k) const {
        k = std::min(k, size());
        return Poly(std::vector<Z>(a.begin(), a.begin() + k));
    }
    Poly divxk(int k) const {
        if (size() <= k) {
            return Poly();
        }
        return Poly(std::vector<Z>(a.begin() + k, a.end()));
    }
    friend Poly operator+(const Poly &a, const Poly &b) {
        std::vector<Z> res(std::max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i++) {
            res[i] = a[i] + b[i];
        }
        return Poly(res);
    }
    friend Poly operator-(const Poly &a, const Poly &b) {
        std::vector<Z> res(std::max(a.size(), b.size()));
        for (int i = 0; i < int(res.size()); i++) {
            res[i] = a[i] - b[i];
        }
        return Poly(res);
    }
    friend Poly operator*(Poly a, Poly b) {
        if (a.size() == 0 || b.size() == 0) {
            return Poly();
        }
        int sz = 1, tot = a.size() + b.size() - 1;
        while (sz < tot)
            sz *= 2;
        a.a.resize(sz);
        b.a.resize(sz);
        dft(a.a);
        dft(b.a);
        for (int i = 0; i < sz; ++i) {
            a.a[i] = a[i] * b[i];
        }
        idft(a.a);
        a.resize(tot);
        return a;
    }
    friend Poly operator*(Z a, Poly b) {
        for (int i = 0; i < int(b.size()); i++) {
            b[i] *= a;
        }
        return b;
    }
    friend Poly operator*(Poly a, Z b) {
        for (int i = 0; i < int(a.size()); i++) {
            a[i] *= b;
        }
        return a;
    }
    Poly &operator+=(Poly b) {
        return (*this) = (*this) + b;
    }
    Poly &operator-=(Poly b) {
        return (*this) = (*this) - b;
    }
    Poly &operator*=(Poly b) {
        return (*this) = (*this) * b;
    }
    Poly deriv() const {
        if (a.empty()) {
            return Poly();
        }
        std::vector<Z> res(size() - 1);
        for (int i = 0; i < size() - 1; ++i) {
            res[i] = (i + 1) * a[i + 1];
        }
        return Poly(res);
    }
    Poly integr() const {
        std::vector<Z> res(size() + 1);
        for (int i = 0; i < size(); ++i) {
            res[i + 1] = a[i] / (i + 1);
        }
        return Poly(res);
    }
    Poly inv(int m) const {
        Poly x{a[0].inv()};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (Poly{2} - modxk(k) * x)).modxk(k);
        }
        return x.modxk(m);
    }
    Poly log(int m) const {
        return (deriv() * inv(m)).integr().modxk(m);
    }
    Poly exp(int m) const {
        Poly x{1};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x * (Poly{1} - x.log(k) + modxk(k))).modxk(k);
        }
        return x.modxk(m);
    }
    Poly pow(int k, int m) const {
        int i = 0;
        while (i < size() && a[i].val() == 0) {
            i++;
        }
        if (i == size() || 1LL * i * k >= m) {
            return Poly(std::vector<Z>(m));
        }
        Z v = a[i];
        auto f = divxk(i) * v.inv();
        return (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);
    }
    Poly sqrt(int m) const {
        Poly x{1};
        int k = 1;
        while (k < m) {
            k *= 2;
            x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((P + 1) / 2);
        }
        return x.modxk(m);
    }
    Poly mulT(Poly b) const {
        if (b.size() == 0) {
            return Poly();
        }
        int n = b.size();
        std::reverse(b.a.begin(), b.a.end());
        return ((*this) * b).divxk(n - 1);
    }
    std::vector<Z> eval(std::vector<Z> x) const {
        if (size() == 0) {
            return std::vector<Z>(x.size(), 0);
        }
        const int n = std::max(int(x.size()), size());
        std::vector<Poly> q(4 * n);
        std::vector<Z> ans(x.size());
        x.resize(n);
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                q[p] = Poly{1, -x[l]};
            } else {
                int m = (l + r) / 2;
                build(2 * p, l, m);
                build(2 * p + 1, m, r);
                q[p] = q[2 * p] * q[2 * p + 1];
            }
        };
        build(1, 0, n);
        std::function<void(int, int, int, const Poly &)> work = [&](int p, int l, int r, const Poly &num) {
            if (r - l == 1) {
                if (l < int(ans.size())) {
                    ans[l] = num[0];
                }
            } else {
                int m = (l + r) / 2;
                work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
                work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
            }
        };
        work(1, 0, n, mulT(q[1].inv(n)));
        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::string s;
    std::cin >> s;
    
    std::vector<Z> fac(n + 1), invfac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
    invfac[n] = fac[n].inv();
    for (int i = n; i > 0; i--) {
        invfac[i - 1] = invfac[i] * i;
    }
    
    auto binom = [&](int n, int m) {
        return fac[n] * invfac[m] * invfac[n - m];
    };
    
    std::vector<Z> g(m + 1), h(m + 1);
    
    Z ans = 0;
    for (int i = 0; i <= m; i++) {
        std::vector<Z> dp(m + 1);
        dp[i] = 1;
        for (int j = i; j > 0; j--) {
            if (s[j - 1] != '>') {
                continue;
            }
            dp[j - 1] += dp[j];
            int k = j;
            while (k > 0 && s[k - 1] == '>') {
                k--;
            }
            for (int l = k - 1; l >= 0; l--) {
                if (s[l] == '>') {
                    break;
                }
                dp[l] += dp[j] * binom(j - 1, j - l - 1) * binom(j - l - 2, j - k - 1);
            }
        }
        for (int j = i; j < m; j++) {
            if (s[j] != '<') {
                continue;
            }
            dp[j + 1] += dp[j];
            int k = j;
            while (k < m && s[k] == '<') {
                k++;
            }
            for (int l = k + 1; l <= m; l++) {
                if (s[l - 1] == '<') {
                    break;
                }
                dp[l] += dp[j] * binom(n - j - 2, l - j - 1) * binom(l - j - 2, k - j - 1);
            }
        }
        for (int j = i; j <= m; j++) {
            g[j] += dp[0] * dp[j] * binom(n - 1, i);
        }
        h[i] += dp[0];
    }
    
    std::vector<Z> tmp(n);
    tmp[0] += -1;
    tmp[1] += 2;
    Z pw = 1;
    for (int i = 0; i < n; i++) {
        tmp[i] += pw * invfac[i];
        pw *= 2;
        tmp[i] /= 4;
    }
    auto f = Poly(tmp).exp(n);
    for (int i = 0; i < n; i++) {
        f[i] *= fac[i];
    }
    
    std::vector<Z> p2(n + 1);
    p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p2[i] = p2[i - 1] * 2;
    }
    
    std::vector<Z> ff(n);
    
    ans += f[n - 1 - m] * g[m];
    for (int i = 0; i <= m; i++) {
        if (i < m && s[i] == '<') {
            int j = i;
            while (j < m && s[j] == '<') {
                j++;
            }
            if (j == m) {
                Z sum = 0;
                for (int k = 0; k < j - i - 1; k++) {
                    sum += binom(m - i - 1, k);
                }
                for (int k = m + 1; k < n; k++) {
                    ans += g[i] * binom(n - 2 - i, k - i - 1) * (p2[k - i - 2] - sum) * f[n - k - 1];
                    ff[k] += h[i] * binom(k - 1, k - i - 1) * (p2[k - i - 2] - sum);
                    sum = 2 * sum;
                    if (j > i + 1) {
                        sum -= binom(k - i - 2, j - i - 2);
                    }
                }
            } else {
                int l = j;
                while (l < m && s[l] == '>') {
                    l++;
                }
                if (l == m) {
                    for (int k = m + 1; k < n; k++) {
                        ans += g[i] * binom(n - 2 - i, k - i - 1) * binom(k - i - 2, k - j - 1) * f[n - k - 1];
                        ff[k] += h[i] * binom(k - 1, k - i - 1) * binom(k - i - 2, k - j - 1);
                    }
                }
            }
        }
        if (i == m) {
            for (int k = m + 1; k < n; k++) {
                if (k == m + 1) {
                    ff[k] += h[i];
                } else {
                    ff[k] += h[i] * binom(k - 1, k - i - 1) * p2[k - i - 2];
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        f[i] *= invfac[i];
        if (i > 0) {
            ff[i] *= invfac[i - 1];
        }
    }
    auto gg = (Poly(f) * Poly(ff)).modxk(n).a;
    for (int i = 1; i < n; i++) {
        gg[i] *= fac[i - 1];
    }
    
    auto solve = [&](auto self, int l, int r) -> void {
        if (r - l == 1) {
            if (l > 0) {
                gg[l] += 2 * gg[l - 1];
            }
            return;
        }
        int m = (l + r) / 2;
        self(self, l, m);
        std::vector<Z> t1(m - l), t2(r - l);
        for (int i = 0; i < m - l; i++) {
            t1[i] = gg[l + i] * invfac[l + i];
        }
        for (int i = 1; i < r - l; i++) {
            t2[i] = p2[i] * invfac[i];
        }
        auto tt = Poly(t1) * Poly(t2);
        for (int i = 0; i < r - l; i++) {
            if (m <= l + i + 1 && l + i + 1 < r) {
                gg[l + i + 1] += fac[l + i] * tt[i];
            }
        }
        self(self, m, r);
    };
    solve(solve, 0, n);
    
    ans += gg[n - 1];
    
    std::cout << ans.val() << "\n";
    
    return 0;
}