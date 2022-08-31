// luogu
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
template<int P>
struct NTT {
    static constexpr int ROOT = 3;
    std::vector<int> rev, roots{0, 1};
    int power(int base, int e) {
        int res = 1;
        while (e > 0) {
            if (e % 2 == 1)
                res = 1LL * res * base % P;
            base = 1LL * base * base % P;
            e /= 2;
        }
        return res;
    }
    void dft(std::vector<int> &a) {
        int n = a.size();
        if (int(rev.size()) != n) {
            int k = __builtin_ctz(n) - 1;
            rev.resize(n);
            for (int i = 0; i < n; ++i)
                rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
        for (int i = 0; i < n; ++i)
            if (rev[i] < i)
                std::swap(a[i], a[rev[i]]);
        if (int(roots.size()) < n) {
            int k = __builtin_ctz(roots.size());
            roots.resize(n);
            while ((1 << k) < n) {
                int e = power(ROOT, (P - 1) >> (k + 1));
                for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                    roots[2 * i] = roots[i];
                    roots[2 * i + 1] = 1LL * roots[i] * e % P;
                }
                ++k;
            }
        }
        for (int k = 1; k < n; k *= 2) {
            for (int i = 0; i < n; i += 2 * k) {
                for (int j = 0; j < k; ++j) {
                    int u = a[i + j];
                    int v = 1LL * a[i + j + k] * roots[k + j] % P;
                    int x = u + v - P;
                    x += x >> 31 & P;
                    a[i + j] = x;
                    x = u - v;
                    x += x >> 31 & P;
                    a[i + j + k] = x;
                }
            }
        }
    }
    void idft(std::vector<int> &a) {
        int n = a.size();
        std::reverse(a.begin() + 1, a.end());
        dft(a);
        int inv = power(n, P - 2);
        for (int i = 0; i < n; ++i)
            a[i] = 1LL * a[i] * inv % P;
    }
    std::vector<int> multiply(std::vector<int> a, std::vector<int> b) {
        int sz = 1, tot = a.size() + b.size() - 1;
        while (sz < tot)
            sz *= 2;
        a.resize(sz);
        b.resize(sz);
        dft(a);
        dft(b);
        for (int i = 0; i < sz; ++i)
            a[i] = 1LL * a[i] * b[i] % P;
        idft(a);
        a.resize(tot);
        return a;
    }
};
NTT<998244353> t1;
NTT<1004535809> t2;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int p[26];
    for (int i = 0; i < 26; ++i) {
        std::cin >> p[i];
        --p[i];
    }
    std::string s, t;
    std::cin >> s >> t;
    int n = s.length(), m = t.length();
    std::vector<int> a(n), b(n), c(m);
    for (int i = 0; i < n; ++i) {
        a[i] = s[n - i - 1] - 'a';
        b[i] = p[a[i]];
    }
    for (int i = 0; i < m; ++i)
        c[i] = t[i] - 'a';
    int sz = 1;
    while (sz < m)
        sz *= 2;
    std::string ans(m - n + 1, '1');
    for (int i = 0; i < 2; ++i) {
        const int mod = i == 0 ? 998244353 : 1004535809;
        auto dft = [&](auto &a) {
            if (i == 0) {
                t1.dft(a);
            } else {
                t2.dft(a);
            }
        };
        std::vector<int> g(sz);
        std::vector<int> l(sz), r(sz);
        for (int i = 0; i < n; ++i)
            l[i] = 2 * (a[i] + b[i]) * a[i] * b[i];
        for (int i = 0; i < m; ++i)
            r[i] = c[i];
        dft(l);
        dft(r);
        for (int i = 0; i < sz; ++i)
            g[i] = 1ll * (mod - l[i]) * r[i] % mod;
        std::fill(l.begin(), l.end(), 0);
        std::fill(r.begin(), r.end(), 0);
        for (int i = 0; i < n; ++i)
            l[i] = a[i] * a[i] + b[i] * b[i] + 4 * a[i] * b[i];
        for (int i = 0; i < m; ++i)
            r[i] = c[i] * c[i];
        dft(l);
        dft(r);
        for (int i = 0; i < sz; ++i)
            g[i] = (g[i] + 1ll * l[i] * r[i]) % mod;
        std::fill(l.begin(), l.end(), 0);
        std::fill(r.begin(), r.end(), 0);
        for (int i = 0; i < n; ++i)
            l[i] = 2 * (a[i] + b[i]);
        for (int i = 0; i < m; ++i)
            r[i] = c[i] * c[i] * c[i];
        dft(l);
        dft(r);
        for (int i = 0; i < sz; ++i)
            g[i] = (g[i] + 1ll * (mod - l[i]) * r[i]) % mod;
        if (i == 0) {
            t1.idft(g);
        } else {
            t2.idft(g);
        }
        std::vector<int> pre(m + 1);
        for (int i = 0; i < m; ++i)
            pre[i + 1] = (pre[i] + c[i] * c[i] * c[i] * c[i]) % mod;
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum = (sum + a[i] * a[i] * b[i] * b[i]) % mod;
        for (int i = 0; i < m - n + 1; ++i) {
            g[i + n - 1] = (1ll * g[i + n - 1] + sum + pre[i + n] - pre[i] + mod) % mod;
            if (g[i + n - 1] != 0)
                ans[i] = '0';
        }
    }
    std::cout << ans << "\n";
    return 0;
}