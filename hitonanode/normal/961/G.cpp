#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#define dbgif(cond, x) ((cond) ? cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl : cerr)
#else
#define dbg(x) (x)
#define dbgif(cond, x) 0
#endif


#line 1 "formal_power_series/test/stirling_number_of_2nd.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"
#line 2 "modint.hpp"
#include <iostream>
#include <set>
#include <vector>

// CUT begin
template <int md> struct ModInt {
#if __cplusplus >= 201402L
#define MDCONST constexpr
#else
#define MDCONST
#endif
    using lint = long long;
    MDCONST static int mod() { return md; }
    static int get_primitive_root() {
        static int primitive_root = 0;
        if (!primitive_root) {
            primitive_root = [&]() {
                std::set<int> fac;
                int v = md - 1;
                for (lint i = 2; i * i <= v; i++)
                    while (v % i == 0) fac.insert(i), v /= i;
                if (v > 1) fac.insert(v);
                for (int g = 1; g < md; g++) {
                    bool ok = true;
                    for (auto i : fac)
                        if (ModInt(g).pow((md - 1) / i) == 1) {
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
    MDCONST ModInt &_setval(lint v) { return val = (v >= md ? v - md : v), *this; }
    MDCONST ModInt(lint v) { _setval(v % md + md); }
    MDCONST explicit operator bool() const { return val != 0; }
    MDCONST ModInt operator+(const ModInt &x) const { return ModInt()._setval((lint)val + x.val); }
    MDCONST ModInt operator-(const ModInt &x) const { return ModInt()._setval((lint)val - x.val + md); }
    MDCONST ModInt operator*(const ModInt &x) const { return ModInt()._setval((lint)val * x.val % md); }
    MDCONST ModInt operator/(const ModInt &x) const { return ModInt()._setval((lint)val * x.inv() % md); }
    MDCONST ModInt operator-() const { return ModInt()._setval(md - val); }
    MDCONST ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    MDCONST ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    MDCONST ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    MDCONST ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend MDCONST ModInt operator+(lint a, const ModInt &x) { return ModInt()._setval(a % md + x.val); }
    friend MDCONST ModInt operator-(lint a, const ModInt &x) { return ModInt()._setval(a % md - x.val + md); }
    friend MDCONST ModInt operator*(lint a, const ModInt &x) { return ModInt()._setval(a % md * x.val % md); }
    friend MDCONST ModInt operator/(lint a, const ModInt &x) {
        return ModInt()._setval(a % md * x.inv() % md);
    }
    MDCONST bool operator==(const ModInt &x) const { return val == x.val; }
    MDCONST bool operator!=(const ModInt &x) const { return val != x.val; }
    MDCONST bool operator<(const ModInt &x) const { return val < x.val; } // To use std::map<ModInt, T>
    friend std::istream &operator>>(std::istream &is, ModInt &x) {
        lint t;
        return is >> t, x = ModInt(t), is;
    }
    MDCONST friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { return os << x.val; }
    MDCONST ModInt pow(lint n) const {
        ModInt ans = 1, tmp = *this;
        while (n) {
            if (n & 1) ans *= tmp;
            tmp *= tmp, n >>= 1;
        }
        return ans;
    }

    static std::vector<ModInt> facs, facinvs, invs;
    MDCONST static void _precalculation(int N) {
        int l0 = facs.size();
        if (N > md) N = md;
        if (N <= l0) return;
        facs.resize(N), facinvs.resize(N), invs.resize(N);
        for (int i = l0; i < N; i++) facs[i] = facs[i - 1] * i;
        facinvs[N - 1] = facs.back().pow(md - 2);
        for (int i = N - 2; i >= l0; i--) facinvs[i] = facinvs[i + 1] * (i + 1);
        for (int i = N - 1; i >= l0; i--) invs[i] = facinvs[i] * facs[i - 1];
    }
    MDCONST lint inv() const {
        if (this->val < std::min(md >> 1, 1 << 21)) {
            while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
            return invs[this->val].val;
        } else {
            return this->pow(md - 2).val;
        }
    }
    MDCONST ModInt fac() const {
        while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
        return facs[this->val];
    }
    MDCONST ModInt facinv() const {
        while (this->val >= int(facs.size())) _precalculation(facs.size() * 2);
        return facinvs[this->val];
    }
    MDCONST ModInt doublefac() const {
        lint k = (this->val + 1) / 2;
        return (this->val & 1) ? ModInt(k * 2).fac() / (ModInt(2).pow(k) * ModInt(k).fac())
                               : ModInt(k).fac() * ModInt(2).pow(k);
    }
    MDCONST ModInt nCr(const ModInt &r) const {
        return (this->val < r.val) ? 0 : this->fac() * (*this - r).facinv() * r.facinv();
    }
    MDCONST ModInt nPr(const ModInt &r) const {
        return (this->val < r.val) ? 0 : this->fac() * (*this - r).facinv();
    }

    ModInt sqrt() const {
        if (val == 0) return 0;
        if (md == 2) return val;
        if (pow((md - 1) / 2) != 1) return 0;
        ModInt b = 1;
        while (b.pow((md - 1) / 2) == 1) b += 1;
        int e = 0, m = md - 1;
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
        return ModInt(std::min(x.val, md - x.val));
    }
};
template <int md> std::vector<ModInt<md>> ModInt<md>::facs = {1};
template <int md> std::vector<ModInt<md>> ModInt<md>::facinvs = {1};
template <int md> std::vector<ModInt<md>> ModInt<md>::invs = {0};
// using mint = ModInt<998244353>;
// using mint = ModInt<1000000007>;
#line 3 "convolution/ntt.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <tuple>
#line 9 "convolution/ntt.hpp"

// CUT begin
// Integer convolution for arbitrary mod
// with NTT (and Garner's algorithm) for ModInt / ModIntRuntime class.
// We skip Garner's algorithm if `skip_garner` is true or mod is in `nttprimes`.
// input: a (size: n), b (size: m)
// return: vector (size: n + m - 1)
template <typename MODINT>
std::vector<MODINT> nttconv(std::vector<MODINT> a, std::vector<MODINT> b, bool skip_garner);

constexpr int nttprimes[3] = {998244353, 167772161, 469762049};

// Integer FFT (Fast Fourier Transform) for ModInt class
// (Also known as Number Theoretic Transform, NTT)
// is_inverse: inverse transform
// ** Input size must be 2^n **
template <typename MODINT> void ntt(std::vector<MODINT> &a, bool is_inverse = false) {
    int n = a.size();
    if (n == 1) return;
    static const int mod = MODINT::mod();
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
template <typename MODINT>
std::vector<MODINT> nttconv(std::vector<MODINT> a, std::vector<MODINT> b, bool skip_garner) {
    if (a.empty() or b.empty()) return {};
    int sz = 1, n = a.size(), m = b.size();
    while (sz < n + m) sz <<= 1;
    if (sz <= 16) {
        std::vector<MODINT> ret(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) ret[i + j] += a[i] * b[j];
        }
        return ret;
    }
    int mod = MODINT::mod();
    if (skip_garner or std::find(std::begin(nttprimes), std::end(nttprimes), mod) != std::end(nttprimes)) {
        a.resize(sz), b.resize(sz);
        if (a == b) {
            ntt(a, false);
            b = a;
        } else {
            ntt(a, false), ntt(b, false);
        }
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
        for (int i = 0; i < n + m - 1; i++) a[i] = garner_ntt_(ntt0[i].val, ntt1[i].val, ntt2[i].val, mod);
    }
    return a;
}

template <typename MODINT>
std::vector<MODINT> nttconv(const std::vector<MODINT> &a, const std::vector<MODINT> &b) {
    return nttconv<MODINT>(a, b, false);
}
#line 6 "formal_power_series/formal_power_series.hpp"
using namespace std;

// CUT begin
// Formal Power Series () based on ModInt<mod> / ModIntRuntime
// Reference: https://ei1333.github.io/luzhiled/snippets/math/formal-power-series.html
template <typename T> struct FormalPowerSeries : vector<T> {
    using vector<T>::vector;
    using P = FormalPowerSeries;

    void shrink() {
        while (this->size() and this->back() == T(0)) this->pop_back();
    }

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
        if (this->empty() || r.empty())
            this->clear();
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
        for (int i = 1; i < deg; i <<= 1) { ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1); }
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
            for (int i = 1; i < n; i++)
                if ((*this)[i] != T(0)) {
                    if ((i & 1) or deg - i / 2 <= 0) return {};
                    return (*this >> i).sqrt(deg - i / 2) << (i / 2);
                }
            return {};
        }
        T sqrtf0 = (*this)[0].sqrt();
        if (sqrtf0 == T(0)) return {};

        P y = (*this) / (*this)[0], ret({T(1)});
        T inv2 = T(1) / T(2);
        for (int i = 1; i < deg; i <<= 1) { ret = (ret + y.pre(i << 1) * ret.inv(i << 1)) * inv2; }
        return ret.pre(deg) * sqrtf0;
    }

    P exp(int deg = -1) const {
        assert(deg >= -1);
        assert(this->empty() or ((*this)[0]) == T(0)); // Requirement: F(0) = 0
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        P ret({T(1)});
        for (int i = 1; i < deg; i <<= 1) { ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1); }
        return ret.pre(deg);
    }

    P pow(long long k, int deg = -1) const {
        assert(deg >= -1);
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        for (int i = 0; i < n; i++) {
            if ((*this)[i] != T(0)) {
                T rev = T(1) / (*this)[i];
                P C = (*this) * rev, D(n - i);
                for (int j = i; j < n; j++) D[j - i] = C.coeff(j);
                D = (D.log(deg) * T(k)).exp(deg) * (*this)[i].pow(k);
                if (k * (i > 0) > deg or k * i > deg) return {};
                P E(deg);
                long long S = i * k;
                for (int j = 0; j + S < deg and j < (int)D.size(); j++) E[j + S] = D[j];
                E.shrink();
                return E;
            }
        }
        return *this;
    }

    // Calculate f(X + c) from f(X), O(NlogN)
    P shift(T c) const {
        const int n = (int)this->size();
        P ret = *this;
        for (int i = 0; i < n; i++) { ret[i] *= T(i).fac(); }
        reverse(ret.begin(), ret.end());
        P exp_cx(n, 1);
        for (int i = 1; i < n; i++) { exp_cx[i] = exp_cx[i - 1] * c / i; }
        ret = (ret * exp_cx), ret.resize(n);
        reverse(ret.begin(), ret.end());
        for (int i = 0; i < n; i++) { ret[i] /= T(i).fac(); }
        return ret;
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
#line 5 "formal_power_series/test/stirling_number_of_2nd.test.cpp"
using namespace std;

using mint = ModInt<1000000007>;

mint stir2(int N, int K) {
    FormalPowerSeries<mint> a(N + 1);
    a[N] = mint(N).fac().inv();
    for (int i = N - 1; i >= 0; i--) { a[i] = a[i + 1] * (i + 1); }
    auto b = a;
    for (int i = 0; i <= N; i++) { a[i] *= mint(i).pow(N), b[i] *= (i % 2 ? -1 : 1); }
    a *= b;

    mint coeff = a.coeff(K);
    return coeff;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<mint> W(N);
    cin >> W;
    if (N == K) {
        cout << accumulate(ALL(W), mint(0)) << endl;
        return 0;
    }
    mint c1 = stir2(N, K), c2 = stir2(N - 1, K);
    mint csolo = c1 - c2 * K;
    mint ca = c2 * K; // ai 
    dbg(c1);
    dbg(c2);
    dbg(ca);
    dbg(csolo);
    cout << accumulate(W.begin(), W.end(), mint(0)) * (ca * (1 + mint(N - 1) / K) + csolo) << endl;
}