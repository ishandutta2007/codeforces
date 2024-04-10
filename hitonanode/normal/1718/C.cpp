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
#define dbg(x) 0
#define dbgif(cond, x) 0
#endif

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
Sieve sieve(201010);

#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

} // namespace internal

} // namespace atcoder

#endif // ATCODER_INTERNAL_BITOP_HPP

#ifndef ATCODER_SEGTREE_HPP
#define ATCODER_SEGTREE_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

// #include "atcoder/internal_bit"

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) { update(i); }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

} // namespace atcoder

#endif // ATCODER_SEGTREE_HPP

// Reference: https://atcoder.github.io/ac-library/document_ja/segtree.html
/* usage:
struct S {
    long long su;
    int nb;
};
S e() { return {0, 0}; }
S op(S l, S r) { return {l.su + r.su, l.nb + r.nb}; }
vector<S> seginit(100000, e());
atcoder::segtree<S, op, e> segtree(seginit);
*/

lint op(lint l, lint r) { return max(l, r); }
lint e() { return -(1LL << 50); }

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<lint> Ainit(N);
    cin >> Ainit;
    // Ainit.resize(180180, 1);
    N = Ainit.size();
    vector<pint> PX;
    REP(q, Q) {
        int p, x;
        cin >> p >> x;
        --p;
        PX.emplace_back(p, x);
    }
    vector<vector<lint>> sums(N + 1);

    vector<pint> pbs;
    {
        auto fac = sieve.factorize(N);
        for (auto [p, d] : fac) pbs.emplace_back(N / p, N / p);
    }

    // for (auto d : pbs) sums[d.first].assign(d.first, 0);

    // multiset<lint> his;

    // vector<lint> current(N);

    vector<vector<int>> i2idx(N);
    int head = 0;
    vector<lint> coeffs;
    dbg(pbs);
    for (auto [p, d] : pbs) {
        int c = 0;
        REP(i, N) {
            i2idx[i].push_back(head + c);
            ++c;
            if (c == d) c = 0;
        }
        REP(_, d) coeffs.push_back(d);
        head += d;
    }

    vector<lint> seginit(head, 0);
    dbg(head);
    dbg(i2idx);

    REP(i, N) {
        for (auto j : i2idx[i]) {
            seginit[j] += Ainit[i] * coeffs[j];
        }
    }
    atcoder::segtree<lint, op, e> tree(seginit);

    cout << tree.all_prod() << '\n';

    // cout << *prev(his.end()) << '\n';

    for (auto [p, x] : PX) {
        lint diff = x - Ainit[p];
        Ainit[p] = x;
        for (auto i : i2idx[p]) {
            seginit[i] += diff * coeffs[i];
            tree.set(i, seginit[i]);
        }
        cout << tree.all_prod() << '\n';
        // set(p, x, false);
        // cout << *prev(his.end()) << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}