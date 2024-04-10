#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
    fast_ios() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); };
} fast_ios_;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
//
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args>
void ndarray(vector<T>& vec, const V& val, int len, Args... args)
{
    vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T& m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T>
bool chmin(T& m, const T q) { return m > q ? (m = q, true) : false; }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T>
vector<T> srtunq(vector<T> vec) { return sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()), vec; }
template <typename T>
istream& operator>>(istream& is, vector<T>& vec)
{
    return for_each(begin(vec), end(vec), [&](T& v) { is >> v; }), is;
}

// output
template <typename T, typename V>
ostream& dmpseq(ostream&, const T&, const string&, const string&, const string&);
#if __cplusplus >= 201703L
template <typename... T>
ostream& operator<<(ostream& os, const tuple<T...>& tpl)
{
    return apply([&os](auto&&... args) { ((os << args << ','), ...); }, tpl), os;
}
#endif
//
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '(' << p.first << ',' << p.second << ')'; }
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& x) { return dmpseq<vector<T>, T>(os, x, "[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& x) { return dmpseq<deque<T>, T>(os, x, "deq[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const set<T>& x) { return dmpseq<set<T>, T>(os, x, "{", ",", "}"); }
template <typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_set<T, TH>& x) { return dmpseq<unordered_set<T, TH>, T>(os, x, "{", ",", "}"); }
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& x) { return dmpseq<multiset<T>, T>(os, x, "{", ",", "}"); }
template <typename TK, typename T>
ostream& operator<<(ostream& os, const map<TK, T>& x) { return dmpseq<map<TK, T>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename TK, typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_map<TK, T, TH>& x) { return dmpseq<unordered_map<TK, T, TH>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename T, typename V>
ostream& dmpseq(ostream& os, const T& seq, const string& pre, const string& sp, const string& suf)
{
    return os << pre, for_each(begin(seq), end(seq), [&](V x) { os << x << sp; }), os << suf;
}
template <typename T>
void print(const vector<T>& x) { dmpseq<vector<T>, T>(cout, x, "", " ", "\n"); }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

template <int mod>
struct ModInt
{
    using lint = long long;
    static int get_mod() { return mod; }
    static int get_primitive_root() {
        static int primitive_root = 0;
        if (!primitive_root) {
            primitive_root = [&](){
                std::set<int> fac;
                int v = mod - 1;
                for (lint i = 2; i * i <= v; i++) while (v % i == 0) fac.insert(i), v /= i;
                if (v > 1) fac.insert(v);
                for (int g = 1; g < mod; g++) {
                    bool ok = true;
                    for (auto i : fac) if (ModInt(g).power((mod - 1) / i) == 1) { ok = false; break; }
                    if (ok) return g;
                }
                return -1;
            }();
        }
        return primitive_root;
    }
    int val;
    constexpr ModInt() : val(0) {}
    constexpr ModInt &_setval(lint v) { val = (v >= mod ? v - mod : v); return *this; }
    constexpr ModInt(lint v) { _setval(v % mod + mod); }
    explicit operator bool() const { return val != 0; }
    constexpr ModInt operator+(const ModInt &x) const { return ModInt()._setval((lint)val + x.val); }
    constexpr ModInt operator-(const ModInt &x) const { return ModInt()._setval((lint)val - x.val + mod); }
    constexpr ModInt operator*(const ModInt &x) const { return ModInt()._setval((lint)val * x.val % mod); }
    constexpr ModInt operator/(const ModInt &x) const { return ModInt()._setval((lint)val * x.inv() % mod); }
    constexpr ModInt operator-() const { return ModInt()._setval(mod - val); }
    constexpr ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    constexpr ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    constexpr ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    constexpr ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend constexpr ModInt operator+(lint a, const ModInt &x) { return ModInt()._setval(a % mod + x.val); }
    friend constexpr ModInt operator-(lint a, const ModInt &x) { return ModInt()._setval(a % mod - x.val + mod); }
    friend constexpr ModInt operator*(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.val % mod); }
    friend constexpr ModInt operator/(lint a, const ModInt &x) { return ModInt()._setval(a % mod * x.inv() % mod); }
    constexpr bool operator==(const ModInt &x) const { return val == x.val; }
    constexpr bool operator!=(const ModInt &x) const { return val != x.val; }
    bool operator<(const ModInt &x) const { return val < x.val; }  // To use std::map<ModInt, T>
    friend std::istream &operator>>(std::istream &is, ModInt &x) { lint t; is >> t; x = ModInt(t); return is; }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { os << x.val;  return os; }
    constexpr lint power(lint n) const {
        lint ans = 1, tmp = this->val;
        while (n) {
            if (n & 1) ans = ans * tmp % mod;
            tmp = tmp * tmp % mod;
            n /= 2;
        }
        return ans;
    }
    constexpr lint inv() const { return this->power(mod - 2); }
    constexpr ModInt operator^(lint n) const { return ModInt(this->power(n)); }
    constexpr ModInt &operator^=(lint n) { return *this = *this ^ n; }

    inline ModInt fac() const {
        static std::vector<ModInt> facs;
        int l0 = facs.size();
        if (l0 > this->val) return facs[this->val];

        facs.resize(this->val + 1);
        for (int i = l0; i <= this->val; i++) facs[i] = (i == 0 ? ModInt(1) : facs[i - 1] * ModInt(i));
        return facs[this->val];
    }

    ModInt doublefac() const {
        lint k = (this->val + 1) / 2;
        if (this->val & 1) return ModInt(k * 2).fac() / ModInt(2).power(k) / ModInt(k).fac();
        else return ModInt(k).fac() * ModInt(2).power(k);
    }

    ModInt nCr(const ModInt &r) const {
        if (this->val < r.val) return ModInt(0);
        return this->fac() / ((*this - r).fac() * r.fac());
    }

    ModInt sqrt() const {
        if (val == 0) return 0;
        if (mod == 2) return val;
        if (power((mod - 1) / 2) != 1) return 0;
        ModInt b = 1;
        while (b.power((mod - 1) / 2) == 1) b += 1;
        int e = 0, m = mod - 1;
        while (m % 2 == 0) m >>= 1, e++;
        ModInt x = power((m - 1) / 2), y = (*this) * x * x;
        x *= (*this);
        ModInt z = b.power(m);
        while (y != 1) {
            int j = 0;
            ModInt t = y;
            while (t != 1) j++, t *= t;
            z = z.power(1LL << (e - j - 1));
            x *= z, z *= z, y *= z;
            e = j;
        }
        return ModInt(std::min(x.val, mod - x.val));
    }
};
constexpr lint MOD = 998244353;
using mint = ModInt<MOD>;

// Integer convolution for arbitrary mod
// with NTT (and Garner's algorithm) for ModInt / ModIntRuntime class.
// We skip Garner's algorithm if `skip_garner` is true or mod is in `nttprimes`.
// input: a (size: n), b (size: m)
// return: vector (size: n + m - 1)
template <typename MODINT>
std::vector<MODINT> nttconv(std::vector<MODINT> a, std::vector<MODINT> b, bool skip_garner = false);

constexpr int nttprimes[3] = {998244353, 167772161, 469762049};

// Integer FFT (Fast Fourier Transform) for ModInt class
// (Also known as Number Theoretic Transform, NTT)
// is_inverse: inverse transform
// ** Input size must be 2^n **
template <typename MODINT>
void ntt(std::vector<MODINT> &a, bool is_inverse = false)
{
    int n = a.size();
    if (n == 1) return;
    static const int mod = MODINT::get_mod();
    static const MODINT root = MODINT::get_primitive_root();
    assert(__builtin_popcount(n) == 1 and (mod - 1) % n == 0);

    static std::vector<MODINT> w{1}, iw{1};
    for (int m = w.size(); m < n / 2; m *= 2) {
        MODINT dw = root.power((mod - 1) / (4 * m)), dwinv = 1 / dw;
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
    }
    else {
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
template <int MOD>
std::vector<ModInt<MOD>> nttconv_(const std::vector<int> &a, const std::vector<int> &b) {
    int sz = a.size();
    assert(a.size() == b.size() and __builtin_popcount(sz) == 1);
    std::vector<ModInt<MOD>> ap(sz), bp(sz);
    for (int i = 0; i < sz; i++) ap[i] = a[i], bp[i] = b[i];
    ntt(ap, false);
    if (a == b) bp = ap;
    else ntt(bp, false);
    for (int i = 0; i < sz; i++) ap[i] *= bp[i];
    ntt(ap, true);
    return ap;
}
long long garner_ntt_(int r0, int r1, int r2, int mod)
{
    using mint2 = ModInt<nttprimes[2]>;
    static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];
    static const long long m0_inv_m1 = ModInt<nttprimes[1]>(nttprimes[0]).inv();
    static const long long m01_inv_m2 = mint2(m01).inv();

    int v1 = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];
    auto v2 = (mint2(r2) - r0 - mint2(nttprimes[0]) * v1) * m01_inv_m2;
    return (r0 + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val) % mod;
}
template <typename MODINT>
std::vector<MODINT> nttconv(std::vector<MODINT> a, std::vector<MODINT> b, bool skip_garner)
{
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
    if (skip_garner or std::find(std::begin(nttprimes), std::end(nttprimes), mod) != std::end(nttprimes))
    {
        a.resize(sz), b.resize(sz);
        if (a == b) { ntt(a, false); b = a; }
        else ntt(a, false), ntt(b, false);
        for (int i = 0; i < sz; i++) a[i] *= b[i];
        ntt(a, true);
        a.resize(n + m - 1);
    }
    else {
        std::vector<int> ai(sz), bi(sz);
        for (int i = 0; i < n; i++) ai[i] = a[i].val;
        for (int i = 0; i < m; i++) bi[i] = b[i].val;
        auto ntt0 = nttconv_<nttprimes[0]>(ai, bi);
        auto ntt1 = nttconv_<nttprimes[1]>(ai, bi);
        auto ntt2 = nttconv_<nttprimes[2]>(ai, bi);
        a.resize(n + m - 1);
        for (int i = 0; i < n + m - 1; i++) {
            a[i] = garner_ntt_(ntt0[i].val, ntt1[i].val, ntt2[i].val, mod);
        }
    }
    return a;
}

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind
{
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

// Formal Power Series () based on ModInt<mod> / ModIntRuntime
// Reference: <https://ei1333.github.io/luzhiled/snippets/math/formal-power-series.html>
template<typename T>
struct FormalPowerSeries : vector<T>
{
    using vector<T>::vector;
    using P = FormalPowerSeries;

    void shrink() { while (this->size() and this->back() == T(0)) this->pop_back(); }

    P operator+(const P &r) const { return P(*this) += r; }
    P operator+(const T &v) const { return P(*this) += v; }
    P operator-(const P &r) const { return P(*this) -= r; }
    P operator-(const T &v) const { return P(*this) -= v; }
    P operator*(const P &r) const { return P(*this) *= r; }
    P operator*(const T &v) const { return P(*this) *= v; }
    P operator/(const P &r) const { return P(*this) /= r; }
    P operator/(const T &v) const { return P(*this) /= v; }
    P operator%(const P &r) const { return P(*this) %= r; }

    P &operator+=(const P &r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];
        shrink();
        return *this;
    }
    P &operator+=(const T &v) {
        if (this->empty()) this->resize(1);
        (*this)[0] += v;
        shrink();
        return *this;
    }
    P &operator-=(const P &r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];
        shrink();
        return *this;
    }
    P &operator-=(const T &v) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= v;
        shrink();
        return *this;
    }
    P &operator*=(const T &v) {
        for (auto &x : (*this)) x *= v;
        shrink();
        return *this;
    }
    P &operator*=(const P &r) {
        if (this->empty() || r.empty()) this->clear();
        else {
            auto ret = nttconv(*this, r);
            *this = P(ret.begin(), ret.end());
        }
        return *this;
    }
    P &operator%=(const P &r) {
        *this -= *this / r * r;
        shrink();
        return *this;
    }
    P operator-() const {
        P ret = *this;
        for (auto &v : ret) v = -v;
        return ret;
    }
    P &operator/=(const T &v) {
        assert(v != T(0));
        for (auto &x : (*this)) x /= v;
        return *this;
    }
    P &operator/=(const P &r) {
        if (this->size() < r.size()) {
            this->clear();
            return *this;
        }
        int n = (int)this->size() - r.size() + 1;
        return *this = (reversed().pre(n) * r.reversed().inv(n)).pre(n).reversed(n);
    }
    P pre(int sz) const {
         P ret(this->begin(), this->begin() + min((int)this->size(), sz));
         ret.shrink();
         return ret;
    }
    P operator>>(int sz) const {
        if ((int)this->size() <= sz) return {};
        return P(this->begin() + sz, this->end());
    }
    P operator<<(int sz) const {
        if (this->empty()) return {};
        P ret(*this);
        ret.insert(ret.begin(), sz, T(0));
        return ret;
    }

    P reversed(int deg = -1) const {
        assert(deg >= -1);
        P ret(*this);
        if (deg != -1) ret.resize(deg, T(0));
        reverse(ret.begin(), ret.end());
        ret.shrink();
        return ret;
    }

    P differential() const { // formal derivative (differential) of f.p.s.
        const int n = (int)this->size();
        P ret(max(0, n - 1));
        for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);
        return ret;
    }

    P integral() const {
        const int n = (int)this->size();
        P ret(n + 1);
        ret[0] = T(0);
        for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);
        return ret;
    }

    P inv(int deg) const {
        assert(deg >= -1);
        assert(this->size() and ((*this)[0]) != T(0)); // Requirement: F(0) != 0
        const int n = this->size();
        if (deg == -1) deg = n;
        P ret({T(1) / (*this)[0]});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
        }
        ret = ret.pre(deg);
        ret.shrink();
        return ret;
    }

    P log(int deg = -1) const {
        assert(deg >= -1);
        assert(this->size() and ((*this)[0]) == T(1)); // Requirement: F(0) = 1
        const int n = (int)this->size();
        if (deg == 0) return {};
        if (deg == -1) deg = n;
        return (this->differential() * this->inv(deg)).pre(deg - 1).integral();
    }

    P sqrt(int deg = -1) const {
        assert(deg >= -1);
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        if (this->empty()) return {};
        if ((*this)[0] == T(0)) {
            for (int i = 1; i < n; i++) if ((*this)[i] != T(0)) {
                if ((i & 1) or deg - i / 2 <= 0) return {};
                return (*this >> i).sqrt(deg - i / 2) << (i / 2);
            }
            return {};
        }
        T sqrtf0 = (*this)[0].sqrt();
        if (sqrtf0 == T(0)) return {};

        P y = (*this) / (*this)[0], ret({T(1)});
        T inv2 = T(1) / T(2);
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret + y.pre(i << 1) * ret.inv(i << 1)) * inv2;
        }
        return ret.pre(deg) * sqrtf0;
    }

    P exp(int deg = -1) const {
        assert(deg >= -1);
        assert(this->empty() or ((*this)[0]) == T(0)); // Requirement: F(0) = 0
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        P ret({T(1)});
        for (int i = 1; i < deg; i <<= 1) {
            ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
        }
        return ret.pre(deg);
    }

    P pow(long long int k, int deg = -1) const {
        assert(deg >= -1);
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        for (int i = 0; i < n; i++) {
            if ((*this)[i] != T(0)) {
                T rev = T(1) / (*this)[i];
                P C(*this * rev);
                P D(n - i);
                for (int j = i; j < n; j++) D[j - i] = C[j];
                D = (D.log(deg) * T(k)).exp(deg) * (*this)[i].power(k);
                P E(deg);
                if (k * (i > 0) > deg or k * i > deg) return {};
                long long int S = i * k;
                for (int j = 0; j + S < deg and j < (int)D.size(); j++) E[j + S] = D[j];
                E.shrink();
                return E;
            }
        }
        return *this;
    }

    T coeff(int i) const {
        if ((int)this->size() <= i or i < 0) return T(0);
        return (*this)[i];
    }

    T eval(T x) const {
        T ret = 0, w = 1;
        for (auto &v : *this) ret += w * v, w *= x;
        return ret;
    }
};

using fps = FormalPowerSeries<mint>;
int main()
{
    int N;
    cin >> N;
    vector A(N, vector<int>(N));
    cin >> A;
    vector<pair<int, pint>> w2ij;
    REP(j, N)
    {
        REP(i, j)
        {
            w2ij.emplace_back(A[i][j], pint(i, j));
        }
    }
    sort(ALL(w2ij));
    dbg(w2ij);
    UnionFind uf(N);
    vector<fps> fs(N, { 1 });
    vector<fps> fsdiv(N, { 1 });
    fps prod { 1 };

    vector<int> nb_e(N);
    for (auto [w, p] : w2ij) {
        auto [i, j] = p;
        const int ri = uf.find(i), rj = uf.find(j);
        uf.unite(i, j);
        const int r = uf.find(i);
        if (ri != rj) nb_e[r] = nb_e[ri] + nb_e[rj];

        nb_e[r]++;

        const int n = uf.count(r);

        if (ri != rj)
        {
            auto f2 = fs[ri] * fs[rj];
            fs[ri] = fs[rj] = { 0 };
            fs[r] = f2;
            auto fsdivnew = fsdiv[ri] * fsdiv[rj];
            fsdiv[ri] = fsdiv[rj] = { 0 };
            fsdiv[r] = fsdivnew;
        }

        if (nb_e[r] == n * (n - 1) / 2)
        {
            fps fmono(uf.count(r));
            fmono[uf.count(r) - 1] = 1;
            fs[r] += fmono;
            prod = (prod * fs[r]) / fsdiv[r];
            fsdiv[r] = fs[r];
            prod.shrink();
        }
    }
    FOR(k, 1, N + 1)
    {
        cout << prod.coeff(N - k) << ' ';
    }
    cout << '\n';
}