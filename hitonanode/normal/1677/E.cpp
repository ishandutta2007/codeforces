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
#ifndef ATCODER_LAZYSEGTREE_HPP
#define ATCODER_LAZYSEGTREE_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

// #include "atcoder/internal_bit"

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) { update(i); }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) const {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) const {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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

protected:
    int _n, size, log;
    mutable std::vector<S> d;
    mutable std::vector<F> lz;

    void update(int k) const { d[k] = op(d[2 * k], d[2 * k + 1]); }
    virtual void all_apply(int k, F f) const {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) const {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};
} // namespace atcoder
#endif // ATCODER_LAZYSEGTREE_HPP
// Reference: https://atcoder.github.io/ac-library/document_ja/lazysegtree.html
//            https://betrue12.hateblo.jp/entry/2020/09/22/194541
//            https://betrue12.hateblo.jp/entry/2020/09/23/005940
/*
struct S {};
S op(S l, S r) {
    return {};
}
S e() { return {}; };
using F = bool;
S mp(F f, S x) {
    return x;
}
F composition(F fnew, F gold) { return fnew ^ gold; }
F id() { return false; }

vector<S> A;
atcoder::lazy_segtree<S, op, e, F, mp, composition, id> seg(A);
*/

// 0-indexed BIT (binary indexed tree / Fenwick tree) (i : [0, len))
template <class T> struct BIT {
    int n;
    std::vector<T> data;
    BIT(int len = 0) : n(len), data(len) {}
    void reset() { std::fill(data.begin(), data.end(), T(0)); }
    void add(int pos, T v) { // a[pos] += v
        pos++;
        while (pos > 0 and pos <= n) data[pos - 1] += v, pos += pos & -pos;
    }
    T sum(int k) const { // a[0] + ... + a[k - 1]
        T res = 0;
        while (k > 0) res += data[k - 1], k -= k & -k;
        return res;
    }

    T sum(int l, int r) const { return sum(r) - sum(l); } // a[l] + ... + a[r - 1]

    template <class OStream> friend OStream &operator<<(OStream &os, const BIT &bit) {
        T prv = 0;
        os << '[';
        for (int i = 1; i <= bit.n; i++) {
            T now = bit.sum(i);
            os << now - prv << ',', prv = now;
        }
        return os << ']';
    }
};

template <class Int, class T> class RectangleAddRectangleSum {
    struct AddQuery {
        Int xl, xr, yl, yr;
        T val;
    };
    struct SumQuery {
        Int xl, xr, yl, yr;
    };
    std::vector<AddQuery> add_queries;
    std::vector<SumQuery> sum_queries;
public:
    RectangleAddRectangleSum() = default;

    void add_rectangle(Int xl, Int xr, Int yl, Int yr, T val) {
        add_queries.push_back(AddQuery{xl, xr, yl, yr, val});
    }

    void add_query(Int xl, Int xr, Int yl, Int yr) {
        sum_queries.push_back(SumQuery{xl, xr, yl, yr});
    }
    std::vector<T> solve() const {
        std::vector<Int> ys;
        for (const auto &a : add_queries) {
            ys.push_back(a.yl);
            ys.push_back(a.yr);
        }
        std::sort(ys.begin(), ys.end());
        ys.erase(std::unique(ys.begin(), ys.end()), ys.end());

        const int Y = ys.size();

        std::vector<std::tuple<Int, int, int>> ops;
        for (int q = 0; q < int(sum_queries.size()); ++q) {
            ops.emplace_back(sum_queries[q].xl, 0, q);
            ops.emplace_back(sum_queries[q].xr, 1, q);
        }
        for (int q = 0; q < int(add_queries.size()); ++q) {
            ops.emplace_back(add_queries[q].xl, 2, q);
            ops.emplace_back(add_queries[q].xr, 3, q);
        }
        std::sort(ops.begin(), ops.end());

        BIT<T> b00(Y), b01(Y), b10(Y), b11(Y);
        std::vector<T> ret(sum_queries.size());
        for (auto o : ops) {
            int qtype = std::get<1>(o), q = std::get<2>(o);
            if (qtype >= 2) {
                const AddQuery &query = add_queries.at(q);
                int i = std::lower_bound(ys.begin(), ys.end(), query.yl) - ys.begin();
                int j = std::lower_bound(ys.begin(), ys.end(), query.yr) - ys.begin();
                T x = std::get<0>(o);
                T yi = query.yl, yj = query.yr;
                if (qtype & 1) std::swap(i, j), std::swap(yi, yj);

                b00.add(i, x * yi * query.val);
                b01.add(i, -x * query.val);
                b10.add(i, -yi * query.val);
                b11.add(i, query.val);
                b00.add(j, -x * yj * query.val);
                b01.add(j, x * query.val);
                b10.add(j, yj * query.val);
                b11.add(j, -query.val);
            } else {
                const SumQuery &query = sum_queries.at(q);
                int i = std::lower_bound(ys.begin(), ys.end(), query.yl) - ys.begin();
                int j = std::lower_bound(ys.begin(), ys.end(), query.yr) - ys.begin();
                T x = std::get<0>(o);
                T yi = query.yl, yj = query.yr;
                if (qtype & 1) std::swap(i, j), std::swap(yi, yj);

                ret[q] += b00.sum(i) + b01.sum(i) * yi + b10.sum(i) * x + b11.sum(i) * x * yi;
                ret[q] -= b00.sum(j) + b01.sum(j) * yj + b10.sum(j) * x + b11.sum(j) * x * yj;
            }
        }
        return ret;
    }
};

int e() { return -1; }
int op(int l, int r) { return max(l, r); }

struct T {
    int qid;
    int querysign;
    int l, r;
    int bias1;
    int bias0;
    friend std::ostream &operator<<(std::ostream &os, const T &x) {
        return os << "(" << x.qid << "," << x.querysign << " " << x.l << " " << x.r << " " << x.bias0 << " " << x.bias1 << ")";
    }
};

// (sum, sz)
plint op2(plint l, plint r) { return l + r; }
plint e2() { return {0, 0}; }
using F = lint;
plint mp(F f, plint x) { return make_pair(x.first + x.second * f, x.second); }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> P(N);
    cin >> P;
    vector<int> Pinv(N + 1, -1);
    REP(i, N) Pinv[P[i]] = i;

    atcoder::segtree<int, op, e> tree(P);

    vector<vector<tuple<int, int, int, int>>> n_to_rects(N + 1);


    FOR(p, 1, N + 1) {
        for (lint q = p + 1; p * q <= N; ++q) {
            int l = Pinv[p], r = Pinv[q];
            if (l > r) swap(l, r);
            int in = Pinv[p * q];
            chmin(l, in);
            chmax(r, in);
            if (tree.prod(l, r + 1) > p * q) {
                continue;
            }
            int rr = tree.max_right(r, [&](int x) { return x <= p * q; }) - 1;
            int ll = tree.min_left(l, [&](int x) { return x <= p * q; });
            n_to_rects[p * q].emplace_back(ll, l, r, rr);
        }
    }

    RectangleAddRectangleSum<int, lint> rars;

    for (auto &vec : n_to_rects) {
        if (vec.empty()) continue;
        sort(vec.begin(), vec.end());
        vector<tuple<int, int, int, int>> vec2;
        for (auto [ll, l, r, rr] : vec) {
            while (vec2.size() and get<2>(vec2.back()) >= r) vec2.pop_back();
            vec2.emplace_back(ll, l, r, rr);
        }

        swap(vec, vec2);
        int lastl = -1;
        int lastr = -1;
        for (auto [ll, l, r, rr] : vec) {
            if (l <= lastl) continue;
            chmax(ll, lastl + 1);

            rars.add_rectangle(ll, l + 1, r, rr + 1, 1);

            lastl = l;
            lastr = r;
        }
    }

    REP(q, Q) {
        int l, r;
        cin >> l >> r;
        --l;
        rars.add_query(l, r, l, r);
    }

    for (auto x : rars.solve()) cout << x << '\n';
}