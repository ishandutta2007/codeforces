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
    MDCONST ModInt operator-(const ModInt &x) const {
        return ModInt()._setval((lint)val - x.val + md);
    }
    MDCONST ModInt operator*(const ModInt &x) const {
        return ModInt()._setval((lint)val * x.val % md);
    }
    MDCONST ModInt operator/(const ModInt &x) const {
        return ModInt()._setval((lint)val * x.inv() % md);
    }
    MDCONST ModInt operator-() const { return ModInt()._setval(md - val); }
    MDCONST ModInt &operator+=(const ModInt &x) { return *this = *this + x; }
    MDCONST ModInt &operator-=(const ModInt &x) { return *this = *this - x; }
    MDCONST ModInt &operator*=(const ModInt &x) { return *this = *this * x; }
    MDCONST ModInt &operator/=(const ModInt &x) { return *this = *this / x; }
    friend MDCONST ModInt operator+(lint a, const ModInt &x) {
        return ModInt()._setval(a % md + x.val);
    }
    friend MDCONST ModInt operator-(lint a, const ModInt &x) {
        return ModInt()._setval(a % md - x.val + md);
    }
    friend MDCONST ModInt operator*(lint a, const ModInt &x) {
        return ModInt()._setval(a % md * x.val % md);
    }
    friend MDCONST ModInt operator/(lint a, const ModInt &x) {
        return ModInt()._setval(a % md * x.inv() % md);
    }
    MDCONST bool operator==(const ModInt &x) const { return val == x.val; }
    MDCONST bool operator!=(const ModInt &x) const { return val != x.val; }
    MDCONST bool operator<(const ModInt &x) const {
        return val < x.val;
    } // To use std::map<ModInt, T>
    friend std::istream &operator>>(std::istream &is, ModInt &x) {
        lint t;
        return is >> t, x = ModInt(t), is;
    }
    MDCONST friend std::ostream &operator<<(std::ostream &os, const ModInt &x) {
        return os << x.val;
    }
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
using mint = ModInt<998244353>;

// Linear sieve algorithm for fast prime factorization
// Complexity: O(N) time, O(N) space:
// - MAXN = 10^7:  ~44 MB,  80~100 ms (Codeforces / AtCoder GCC, C++17)
// - MAXN = 10^8: ~435 MB, 810~980 ms (Codeforces / AtCoder GCC, C++17)
// Reference:
// [1] D. Gries, J. Misra, "A Linear Sieve Algorithm for Finding Prime Numbers,"
//     Communications of the ACM, 21(12), 999-1003, 1978.
// - https://cp-algorithms.com/algebra/prime-sieve-linear.html
// - https://37zigen.com/linear-sieve/
struct Sieve {
    std::vector<int> min_factor;
    std::vector<int> primes;
    Sieve(int MAXN) : min_factor(MAXN + 1) {
        for (int d = 2; d <= MAXN; d++) {
            if (!min_factor[d]) {
                min_factor[d] = d;
                primes.emplace_back(d);
            }
            for (const auto &p : primes) {
                if (p > min_factor[d] or d * p > MAXN) break;
                min_factor[d * p] = p;
            }
        }
    }
    // Prime factorization for 1 <= x <= MAXN^2
    // Complexity: O(log x)           (x <= MAXN)
    //             O(MAXN / log MAXN) (MAXN < x <= MAXN^2)
    template <class T> std::map<T, int> factorize(T x) const {
        std::map<T, int> ret;
        assert(x > 0 and
               x <= ((long long)min_factor.size() - 1) * ((long long)min_factor.size() - 1));
        for (const auto &p : primes) {
            if (x < T(min_factor.size())) break;
            while (!(x % p)) x /= p, ret[p]++;
        }
        if (x >= T(min_factor.size())) ret[x]++, x = 1;
        while (x > 1) ret[min_factor[x]]++, x /= min_factor[x];
        return ret;
    }
    // Enumerate divisors of 1 <= x <= MAXN^2
    // Be careful of highly composite numbers https://oeis.org/A002182/list
    // https://gist.github.com/dario2994/fb4713f252ca86c1254d#file-list-txt (n, (# of div. of n)):
    // 45360->100, 735134400(<1e9)->1344, 963761198400(<1e12)->6720
    template <class T> std::vector<T> divisors(T x) const {
        std::vector<T> ret{1};
        for (const auto p : factorize(x)) {
            int n = ret.size();
            for (int i = 0; i < n; i++) {
                for (T a = 1, d = 1; d <= p.second; d++) {
                    a *= p.first;
                    ret.push_back(ret[i] * a);
                }
            }
        }
        return ret; // NOT sorted
    }
    // Euler phi functions of divisors of given x
    // Verified: ABC212 G https://atcoder.jp/contests/abc212/tasks/abc212_g
    // Complexity: O(sqrt(x) + d(x))
    template <class T> std::map<T, T> euler_of_divisors(T x) const {
        assert(x >= 1);
        std::map<T, T> ret;
        ret[1] = 1;
        std::vector<T> divs{1};
        for (auto p : factorize(x)) {
            int n = ret.size();
            for (int i = 0; i < n; i++) {
                ret[divs[i] * p.first] = ret[divs[i]] * (p.first - 1);
                divs.push_back(divs[i] * p.first);
                for (T a = divs[i] * p.first, d = 1; d < p.second; a *= p.first, d++) {
                    ret[a * p.first] = ret[a] * p.first;
                    divs.push_back(a * p.first);
                }
            }
        }
        return ret;
    }
    // Moebius function Table, (-1)^{# of different prime factors} for square-free x
    // return: [0=>0, 1=>1, 2=>-1, 3=>-1, 4=>0, 5=>-1, 6=>1, 7=>-1, 8=>0, ...] https://oeis.org/A008683
    std::vector<int> GenerateMoebiusFunctionTable() const {
        std::vector<int> ret(min_factor.size());
        for (unsigned i = 1; i < min_factor.size(); i++) {
            if (i == 1) {
                ret[i] = 1;
            } else if ((i / min_factor[i]) % min_factor[i] == 0) {
                ret[i] = 0;
            } else {
                ret[i] = -ret[i / min_factor[i]];
            }
        }
        return ret;
    }
    // Calculate [0^K, 1^K, ..., nmax^K] in O(nmax)
    // Note: **0^0 == 1**
    template <class MODINT> std::vector<MODINT> enumerate_kth_pows(long long K, int nmax) const {
        assert(nmax < int(min_factor.size()));
        assert(K >= 0);
        if (K == 0) return std::vector<MODINT>(nmax + 1, 1);
        std::vector<MODINT> ret(nmax + 1);
        ret[0] = 0, ret[1] = 1;
        for (int n = 2; n <= nmax; n++) {
            if (min_factor[n] == n) {
                ret[n] = MODINT(n).pow(K);
            } else {
                ret[n] = ret[n / min_factor[n]] * ret[min_factor[n]];
            }
        }
        return ret;
    }
};
Sieve sieve((1 << 20));


// f[n]  n  n*i  f[n*i]   O(N loglog N)
// p
//  https://yukicoder.me/submissions/385043
template <typename T> void fast_integer_zeta(std::vector<T> &f) {
    int N = f.size() - 1;
    std::vector<int> is_prime(N + 1, 1);
    for (int p = 2; p <= N; p++) {
        if (is_prime[p]) {
            for (int q = p * 2; q <= N; q += p) is_prime[q] = 0;
            for (int j = N / p * p; j > 0; j -= p) f[j / p] += f[j];
        }
    }
}

// fast_integer_zeta O(NloglogN)
//  https://yukicoder.me/submissions/385120
template <typename T> void fast_integer_moebius(std::vector<T> &f) {
    int N = f.size() - 1;
    std::vector<int> is_prime(N + 1, 1);
    for (int p = 2; p <= N; p++) {
        if (is_prime[p]) {
            for (int q = p * 2; q <= N; q += p) is_prime[q] = 0;
            for (int j = p; j <= N; j += p) f[j / p] -= f[j];
        }
    }
}

// f[n]  n  m  f[m]   O(N loglog N)
template <class T> void integer_zeta_2(std::vector<T> &f) {
    int N = f.size() - 1;
    std::vector<int> is_prime(N + 1, 1);
    for (int p = 2; p <= N; ++p) {
        if (is_prime[p]) {
            for (int q = p * 2; q <= N; q += p) is_prime[q] = 0;
            for (int j = 1; j * p <= N; ++j) f[j * p] += f[j];
        }
    }
}
template <class T> void integer_moebius_2(std::vector<T> &f) {
    int N = f.size() - 1;
    std::vector<int> is_prime(N + 1, 1);
    for (int p = 2; p <= N; ++p) {
        if (is_prime[p]) {
            for (int q = p * 2; q <= N; q += p) is_prime[q] = 0;
            for (int j = N / p; j > 0; --j) f[j * p] -= f[j];
        }
    }
}

mint solve() {
    int N;
    cin >> N;
    vector<int> cntr(N);
    REP(i, N) {
        int a;
        cin >> a;
        cntr[a - 1]++;
    }
    // cntr = {30612, 12124, 2};
    N = accumulate(ALL(cntr), 0);
    sort(cntr.rbegin(), cntr.rend());
    while (cntr.back() == 0) cntr.pop_back();

    dbg(cntr);
    if (cntr[0] == N) return 1;
    // if (int(cntr.size()) == N) return N;

    map<int, int> cntr2cnt;
    for (auto c : cntr) cntr2cnt[c]++;
    dbg(cntr2cnt);

    int g = 0;
    for (auto i : cntr) g = __gcd(g, i);

    auto divs = sieve.divisors(N);
    sort(divs.begin(), divs.end());
    dbg(divs);

    vector<mint> dp(N + 1);  //  n 
    vector<mint> weights(N + 1);
    for (auto n : divs) {
        int k = N / n; // k 
        if (g % k) continue;
        if (n == 1) continue;
        mint patt = mint(n).fac();
        mint nm1inv = mint(n - 1).inv();
        for (auto [c, t] : cntr2cnt) {
            assert(c % k == 0);
            int s = c / k;
            patt *= mint(s).facinv().pow(t);

            mint nw = mint(s) * (s - 1) * nm1inv * k * t;
            weights[n] += nw;
        }
        weights[n] *= patt;
        dp[n] = patt;
    }

    dbg(dp);

    // for (auto n : divs) {
    //     for (auto nn : sieve.divisors(n)) {
    //         if (nn == n) continue;
    //         dp[n] -= dp[nn];
    //         weights[n] -= weights[nn];
    //     }
    // }

    integer_moebius_2(dp);
    integer_moebius_2(weights);
    dbg(dp);

    mint nall = 0, wsum = 0;
    for (auto n : divs) {
        if (!dp[n]) continue;
        dp[n] *= mint(n).inv();
        weights[n] *= mint(n).inv();
        nall += dp[n];
        wsum += weights[n];
    }
    // mint nall = accumulate(dp.begin(), dp.end(), mint(0));
    // mint wsum = accumulate(weights.begin(), weights.end(), mint(0));

    return N - wsum / nall;
}

int main() {
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}