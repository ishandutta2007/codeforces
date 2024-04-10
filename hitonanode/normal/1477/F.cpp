#include <bits/stdc++.h>
using namespace std;

template <int mod> struct ModInt {
#if __cplusplus >= 201402L
#define MDCONST constexpr
#else
#define MDCONST
#endif
    using lint = long long;
    MDCONST static int get_mod() { return mod; }
    static int get_primitive_root() {
        static int primitive_root = 0;
        if (!primitive_root) {
            primitive_root = [&]() {
                std::set<int> fac;
                int v = mod - 1;
                for (lint i = 2; i * i <= v; i++)
                    while (v % i == 0) fac.insert(i), v /= i;
                if (v > 1) fac.insert(v);
                for (int g = 1; g < mod; g++) {
                    bool ok = true;
                    for (auto i : fac)
                        if (ModInt(g).pow((mod - 1) / i) == 1) {
                            ok = false;
                            break;
                        }
                    if (ok) return g;
                }
                return -1;
            }();
        }
        return primitive_root;
    }
    int val;
    MDCONST ModInt() : val(0) {}
    MDCONST ModInt &_setval(lint v) { return val = (v >= mod ? v - mod : v), *this; }
    MDCONST ModInt(lint v) { _setval(v % mod + mod); }
    MDCONST explicit operator bool() const { return val != 0; }
    MDCONST ModInt operator+(const ModInt &x) const { return ModInt()._setval((lint)val + x.val); }
    MDCONST ModInt operator-(const ModInt &x) const { return ModInt()._setval((lint)val - x.val + mod); }
    MDCONST ModInt operator*(const ModInt &x) const { return ModInt()._setval((lint)val * x.val % mod); }
    MDCONST ModInt operator/(const ModInt &x) const { return ModInt()._setval((lint)val * x.inv() % mod); }
    MDCONST ModInt operator-() const { return ModInt()._setval(mod - val); }
    MDCONST ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    MDCONST ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    MDCONST ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    MDCONST ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend MDCONST ModInt operator+(lint a, const ModInt &x) { return ModInt()._setval(a % mod + x.val); }
    friend MDCONST ModInt operator-(lint a, const ModInt &x) { return ModInt()._setval(a % mod - x.val + mod); }
    friend MDCONST ModInt operator*(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.val % mod); }
    friend MDCONST ModInt operator/(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.inv() % mod); }
    MDCONST bool operator==(const ModInt &x) const { return val == x.val; }
    MDCONST bool operator!=(const ModInt &x) const { return val != x.val; }
    MDCONST bool operator<(const ModInt &x) const { return val < x.val; } // To use std::map<ModInt, T>
    friend std::istream &operator>>(std::istream &is, ModInt &x) {
        lint t;
        return is >> t, x = ModInt(t), is;
    }
    MDCONST friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { return os << x.val; }
    MDCONST ModInt pow(lint n) const {
        lint ans = 1, tmp = this->val;
        while (n) {
            if (n & 1) ans = ans * tmp % mod;
            tmp = tmp * tmp % mod, n /= 2;
        }
        return ans;
    }

    static std::vector<long long> facs, invs;
    MDCONST static void _precalculation(int N) {
        int l0 = facs.size();
        if (N <= l0) return;
        facs.resize(N), invs.resize(N);
        for (int i = l0; i < N; i++) facs[i] = facs[i - 1] * i % mod;
        long long facinv = ModInt(facs.back()).pow(mod - 2).val;
        for (int i = N - 1; i >= l0; i--) {
            invs[i] = facinv * facs[i - 1] % mod;
            facinv = facinv * i % mod;
        }
    }
    MDCONST lint inv() const {
        if (this->val < 1 << 20) {
            while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
            return invs[this->val];
        } else {
            return this->pow(mod - 2).val;
        }
    }
    MDCONST ModInt fac() const {
        while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
        return facs[this->val];
    }

    MDCONST ModInt doublefac() const {
        lint k = (this->val + 1) / 2;
        return (this->val & 1) ? ModInt(k * 2).fac() / (ModInt(2).pow(k) * ModInt(k).fac()) : ModInt(k).fac() * ModInt(2).pow(k);
    }
    MDCONST ModInt nCr(const ModInt &r) const { return (this->val < r.val) ? 0 : this->fac() / ((*this - r).fac() * r.fac()); }

    ModInt sqrt() const {
        if (val == 0) return 0;
        if (mod == 2) return val;
        if (pow((mod - 1) / 2) != 1) return 0;
        ModInt b = 1;
        while (b.pow((mod - 1) / 2) == 1) b += 1;
        int e = 0, m = mod - 1;
        while (m % 2 == 0) m >>= 1, e++;
        ModInt x = pow((m - 1) / 2), y = (*this) * x * x;
        x *= (*this);
        ModInt z = b.pow(m);
        while (y != 1) {
            int j = 0;
            ModInt t = y;
            while (t != 1) j++, t *= t;
            z = z.pow(1LL << (e - j - 1));
            x *= z, z *= z, y *= z;
            e = j;
        }
        return ModInt(std::min(x.val, mod - x.val));
    }
};
template <int mod> std::vector<long long> ModInt<mod>::facs = {1};
template <int mod> std::vector<long long> ModInt<mod>::invs = {0};

// Integer convolution for arbitrary mod
// with NTT (and Garner's algorithm) for ModInt / ModIntRuntime class.
// We skip Garner's algorithm if `skip_garner` is true or mod is in `nttprimes`.
// input: a (size: n), b (size: m)
// return: vector (size: n + m - 1)
template <typename MODINT> std::vector<MODINT> nttconv(std::vector<MODINT> a, std::vector<MODINT> b, bool skip_garner = false);

constexpr int nttprimes[3] = {998244353, 167772161, 469762049};

// Integer FFT (Fast Fourier Transform) for ModInt class
// (Also known as Number Theoretic Transform, NTT)
// is_inverse: inverse transform
// ** Input size must be 2^n **
template <typename MODINT> void ntt(std::vector<MODINT> &a, bool is_inverse = false) {
    int n = a.size();
    if (n == 1) return;
    static const int mod = MODINT::get_mod();
    static const MODINT root = MODINT::get_primitive_root();
    assert(__builtin_popcount(n) == 1 and (mod - 1) % n == 0);

    static std::vector<MODINT> w{1}, iw{1};
    for (int m = w.size(); m < n / 2; m *= 2) {
        MODINT dw = root.pow((mod - 1) / (4 * m)), dwinv = 1 / dw;
        w.resize(m * 2), iw.resize(m * 2);
        for (int i = 0; i < m; i++) w[m + i] = w[i] * dw, iw[m + i] = iw[i] * dwinv;
    }

    if (!is_inverse) {
        for (int m = n; m >>= 1;) {
            for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
                for (int i = s; i < s + m; i++) {
                    MODINT x = a[i], y = a[i + m] * w[k];
                    a[i] = x + y, a[i + m] = x - y;
                }
            }
        }
    } else {
        for (int m = 1; m < n; m *= 2) {
            for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
                for (int i = s; i < s + m; i++) {
                    MODINT x = a[i], y = a[i + m];
                    a[i] = x + y, a[i + m] = (x - y) * iw[k];
                }
            }
        }
        int n_inv = MODINT(n).inv();
        for (auto &v : a) v *= n_inv;
    }
}
template <int MOD> std::vector<ModInt<MOD>> nttconv_(const std::vector<int> &a, const std::vector<int> &b) {
    int sz = a.size();
    assert(a.size() == b.size() and __builtin_popcount(sz) == 1);
    std::vector<ModInt<MOD>> ap(sz), bp(sz);
    for (int i = 0; i < sz; i++) ap[i] = a[i], bp[i] = b[i];
    ntt(ap, false);
    if (a == b)
        bp = ap;
    else
        ntt(bp, false);
    for (int i = 0; i < sz; i++) ap[i] *= bp[i];
    ntt(ap, true);
    return ap;
}
long long garner_ntt_(int r0, int r1, int r2, int mod) {
    using mint2 = ModInt<nttprimes[2]>;
    static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];
    static const long long m0_inv_m1 = ModInt<nttprimes[1]>(nttprimes[0]).inv();
    static const long long m01_inv_m2 = mint2(m01).inv();

    int v1 = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];
    auto v2 = (mint2(r2) - r0 - mint2(nttprimes[0]) * v1) * m01_inv_m2;
    return (r0 + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val) % mod;
}
template <typename MODINT> std::vector<MODINT> nttconv(std::vector<MODINT> a, std::vector<MODINT> b, bool skip_garner) {
    int sz = 1, n = a.size(), m = b.size();
    while (sz < n + m) sz <<= 1;
    if (sz <= 16) {
        std::vector<MODINT> ret(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) ret[i + j] += a[i] * b[j];
        }
        return ret;
    }
    int mod = MODINT::get_mod();
    if (skip_garner or std::find(std::begin(nttprimes), std::end(nttprimes), mod) != std::end(nttprimes)) {
        a.resize(sz), b.resize(sz);
        if (a == b) {
            ntt(a, false);
            b = a;
        } else
            ntt(a, false), ntt(b, false);
        for (int i = 0; i < sz; i++) a[i] *= b[i];
        ntt(a, true);
        a.resize(n + m - 1);
    } else {
        std::vector<int> ai(sz), bi(sz);
        for (int i = 0; i < n; i++) ai[i] = a[i].val;
        for (int i = 0; i < m; i++) bi[i] = b[i].val;
        auto ntt0 = nttconv_<nttprimes[0]>(ai, bi);
        auto ntt1 = nttconv_<nttprimes[1]>(ai, bi);
        auto ntt2 = nttconv_<nttprimes[2]>(ai, bi);
        a.resize(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) { a[i] = garner_ntt_(ntt0[i].val, ntt1[i].val, ntt2[i].val, mod); }
    }
    return a;
}
//////////////////////// TEMPLATE ENDS ////////////////////////

using mint = ModInt<998244353>;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> L(N);
    for (auto &l : L) cin >> l;
    const mint lsum = accumulate(L.begin(), L.end(), mint(0));

    using P = pair<int, vector<vector<mint>>>;
    priority_queue<P, vector<P>, greater<P>> pque;

    for (auto Li : L) {
        vector<vector<mint>> tmp{{1}, {0}};
        for (int pi = 1; pi * K < Li; pi++) {
            mint b = mint(Li - K * pi);
            tmp[0].push_back(b.pow(pi) / mint(pi).fac());
            tmp[1].push_back(b.pow(pi - 1) / mint(pi - 1).fac());
        }
        pque.emplace(tmp.size() * tmp[0].size(), tmp);
    }

    // 2D convolution
    while (pque.size() > 1) {
        auto [d1_, f1] = pque.top();
        pque.pop();
        auto [d2_, f2] = pque.top();
        pque.pop();
        int D = int(f1[0].size() + f2[0].size()) - 1;
        vector<vector<mint>> f(f1.size() + f2.size() - 1, vector<mint>(D));
        for (int d1 = 0; d1 < int(f1.size()); d1++) {
            for (int d2 = 0; d2 < int(f2.size()); d2++) {
                auto v = nttconv(f1[d1], f2[d2]);
                for (int i = 0; i < D; i++) f[d1 + d2][i] += v[i];
            }
        }
        pque.emplace(f.size() * f[0].size(), f);
    }

    const auto v = pque.top().second;

    mint ret = 0;
    for (int q = 1; q < int(v[0].size()); q++) {
        for (int d = 0; d < min(q + 1, int(v.size())); d++) {
            ret -= mint(-1).pow(q) * lsum / mint(K * q).pow(q + 1 - d) * mint(q - d).fac() * v[d][q];
        }
    }
    cout << ret << '\n';
}