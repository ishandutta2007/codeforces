#include <bits/stdc++.h>
constexpr int P = 998244353;
int power(int a, int b) {
    int res = 1;
    for (; b > 0; b /= 2, a = 1ll * a * a % P)
        if (b % 2 == 1) res = 1ll * res * a % P;
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k, c;
    std::cin >> n >> k >> c;
    std::vector<int> fac(k + 1), invFac(k + 1), inv(k + 1);
    fac[0] = 1;
    for (int i = 1; i <= k; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
    for (int i = 0; i <= k; ++i) invFac[i] = power(fac[i], P - 2);
    for (int i = 1; i <= k; ++i) inv[i] = power(i, P - 2);
    std::map<std::vector<int>, int> cnt;
    int xsum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        xsum ^= a;
        std::vector<int> d(k + 1);
        for (int j = 0; j <= k; ++j) d[j] = a ^ (a - j);
        ++cnt[d];
    }
    std::vector<int> f(1 << c), cntm(1 << k);
    for (int x = 0; x < (1 << c); ++x) {
        std::vector<int> e;
        for (auto [d, t] : cnt) {
            int mask = 0;
            for (int i = 1; i <= k; ++i) if (__builtin_parity(x & d[i])) mask |= 1 << (i - 1);
            if (cntm[mask] == 0) e.push_back(mask);
            cntm[mask] += t;
        }
        std::vector<int> g(k + 1);
        g[0] = 1;
        for (auto mask : e) {
            std::vector<int> a(k + 1);
            a[0] = 1;
            for (int i = 1; i <= k; ++i) {
                if (mask >> (i - 1) & 1) a[i] = P - invFac[i];
                else a[i] = invFac[i];
            }
            std::vector<int> pw(k + 1);
            int t = cntm[mask];
            pw[0] = 1;
            for (int i = 1; i <= k; ++i) {
                int res = 0;
                for (int j = 0; j < i; ++j) res = (res + 1ll * pw[j] * a[i - j] % P * (i - j)) % P;
                res = 1ll * res * t % P;
                for (int j = 1; j < i; ++j) res = (res + 1ll * (P - a[j]) * pw[i - j] % P * (i - j)) % P;
                pw[i] = 1ll * res * inv[i] % P;
            }
            for (int i = k; i >= 1; --i) {
                int res = 0;
                for (int j = 0; j <= i; ++j) res = (res + 1ll * pw[j] * g[i - j]) % P;
                g[i] = res;
            }
            cntm[mask] = 0;
        }
        f[x] = 1ll * g[k] * fac[k] % P;
    }
    for (int i = 1; i < (1 << c); i *= 2) {
        for (int j = 0; j < (1 << c); j += 2 * i) {
            for (int k = 0; k < i; ++k) {
                int u = f[j + k], v = f[i + j + k];
                f[j + k] = (u + v) % P;
                f[i + j + k] = (u - v + P) % P;
            }
        }
    }
    int invn = 1ll * power(1 << c, P - 2) * power(n, P - 1 - k) % P;
    for (int i = 0; i < (1 << c); ++i) std::cout << 1ll * f[i ^ xsum] * invn % P << " \n"[i == (1 << c) - 1];
    return 0;
}