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
using mint = ModInt<3>;

template <typename T> struct matrix {
    int H, W;
    std::vector<T> elem;
    typename std::vector<T>::iterator operator[](int i) { return elem.begin() + i * W; }
    inline T &at(int i, int j) { return elem[i * W + j]; }
    inline T get(int i, int j) const { return elem[i * W + j]; }
    int height() const { return H; }
    int width() const { return W; }
    std::vector<std::vector<T>> vecvec() const {
        std::vector<std::vector<T>> ret(H);
        for (int i = 0; i < H; i++) {
            std::copy(elem.begin() + i * W, elem.begin() + (i + 1) * W, std::back_inserter(ret[i]));
        }
        return ret;
    }
    operator std::vector<std::vector<T>>() const { return vecvec(); }
    matrix() = default;
    matrix(int H, int W) : H(H), W(W), elem(H * W) {}
    matrix(const std::vector<std::vector<T>> &d) : H(d.size()), W(d.size() ? d[0].size() : 0) {
        for (auto &raw : d) std::copy(raw.begin(), raw.end(), std::back_inserter(elem));
    }

    static matrix Identity(int N) {
        matrix ret(N, N);
        for (int i = 0; i < N; i++) ret.at(i, i) = 1;
        return ret;
    }

    matrix operator-() const {
        matrix ret(H, W);
        for (int i = 0; i < H * W; i++) ret.elem[i] = -elem[i];
        return ret;
    }
    matrix operator*(const T &v) const {
        matrix ret = *this;
        for (auto &x : ret.elem) x *= v;
        return ret;
    }
    matrix operator/(const T &v) const {
        matrix ret = *this;
        const T vinv = T(1) / v;
        for (auto &x : ret.elem) x *= vinv;
        return ret;
    }
    matrix operator+(const matrix &r) const {
        matrix ret = *this;
        for (int i = 0; i < H * W; i++) ret.elem[i] += r.elem[i];
        return ret;
    }
    matrix operator-(const matrix &r) const {
        matrix ret = *this;
        for (int i = 0; i < H * W; i++) ret.elem[i] -= r.elem[i];
        return ret;
    }
    matrix operator*(const matrix &r) const {
        matrix ret(H, r.W);
        for (int i = 0; i < H; i++) {
            for (int k = 0; k < W; k++) {
                for (int j = 0; j < r.W; j++) ret.at(i, j) += this->get(i, k) * r.get(k, j);
            }
        }
        return ret;
    }
    matrix &operator*=(const T &v) { return *this = *this * v; }
    matrix &operator/=(const T &v) { return *this = *this / v; }
    matrix &operator+=(const matrix &r) { return *this = *this + r; }
    matrix &operator-=(const matrix &r) { return *this = *this - r; }
    matrix &operator*=(const matrix &r) { return *this = *this * r; }
    bool operator==(const matrix &r) const { return H == r.H and W == r.W and elem == r.elem; }
    bool operator!=(const matrix &r) const { return H != r.H or W != r.W or elem != r.elem; }
    bool operator<(const matrix &r) const { return elem < r.elem; }
    matrix pow(int64_t n) const {
        matrix ret = Identity(H);
        bool ret_is_id = true;
        if (n == 0) return ret;
        for (int i = 63 - __builtin_clzll(n); i >= 0; i--) {
            if (!ret_is_id) ret *= ret;
            if ((n >> i) & 1) ret *= (*this), ret_is_id = false;
        }
        return ret;
    }
    std::vector<T> pow_vec(int64_t n, std::vector<T> vec) const {
        matrix x = *this;
        while (n) {
            if (n & 1) vec = x * vec;
            x *= x;
            n >>= 1;
        }
        return vec;
    };
    matrix transpose() const {
        matrix ret(W, H);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) ret.at(j, i) = this->get(i, j);
        }
        return ret;
    }
    // Gauss-Jordan elimination
    // - Require inverse for every non-zero element
    // - Complexity: O(H^2 W)
    template <typename T2, typename std::enable_if<std::is_floating_point<T2>::value>::type * = nullptr>
    static int choose_pivot(const matrix<T2> &mtr, int h, int c) noexcept {
        int piv = -1;
        for (int j = h; j < mtr.H; j++) {
            if (mtr.get(j, c) and (piv < 0 or std::abs(mtr.get(j, c)) > std::abs(mtr.get(piv, c))))
                piv = j;
        }
        return piv;
    }
    template <typename T2, typename std::enable_if<!std::is_floating_point<T2>::value>::type * = nullptr>
    static int choose_pivot(const matrix<T2> &mtr, int h, int c) noexcept {
        for (int j = h; j < mtr.H; j++) {
            if (mtr.get(j, c) != 0) return j;
        }
        return -1;
    }
    matrix gauss_jordan() const {
        int c = 0;
        matrix mtr(*this);
        std::vector<int> ws;
        ws.reserve(W);
        for (int h = 0; h < H; h++) {
            if (c == W) break;
            int piv = choose_pivot(mtr, h, c);
            if (piv == -1) {
                c++;
                h--;
                continue;
            }
            if (h != piv) {
                for (int w = 0; w < W; w++) {
                    std::swap(mtr[piv][w], mtr[h][w]);
                    mtr.at(piv, w) *= -1; // To preserve sign of determinant
                }
            }
            ws.clear();
            for (int w = c; w < W; w++) {
                if (mtr.at(h, w) != 0) ws.emplace_back(w);
            }
            const T hcinv = T(1) / mtr.at(h, c);
            for (int hh = 0; hh < H; hh++)
                if (hh != h) {
                    const T coeff = mtr.at(hh, c) * hcinv;
                    for (auto w : ws) mtr.at(hh, w) -= mtr.at(h, w) * coeff;
                    mtr.at(hh, c) = 0;
                }
            c++;
        }
        return mtr;
    }
    int rank_of_gauss_jordan() const {
        for (int i = H * W - 1; i >= 0; i--) {
            if (elem[i] != 0) return i / W + 1;
        }
        return 0;
    }
    T determinant_of_upper_triangle() const {
        T ret = 1;
        for (int i = 0; i < H; i++) ret *= get(i, i);
        return ret;
    }
    int inverse() {
        assert(H == W);
        std::vector<std::vector<T>> ret = Identity(H), tmp = *this;
        int rank = 0;
        for (int i = 0; i < H; i++) {
            int ti = i;
            while (ti < H and tmp[ti][i] == 0) ti++;
            if (ti == H) {
                continue;
            } else {
                rank++;
            }
            ret[i].swap(ret[ti]), tmp[i].swap(tmp[ti]);
            T inv = T(1) / tmp[i][i];
            for (int j = 0; j < W; j++) ret[i][j] *= inv;
            for (int j = i + 1; j < W; j++) tmp[i][j] *= inv;
            for (int h = 0; h < H; h++) {
                if (i == h) continue;
                const T c = -tmp[h][i];
                for (int j = 0; j < W; j++) ret[h][j] += ret[i][j] * c;
                for (int j = i + 1; j < W; j++) tmp[h][j] += tmp[i][j] * c;
            }
        }
        *this = ret;
        return rank;
    }
    friend std::vector<T> operator*(const matrix &m, const std::vector<T> &v) {
        assert(m.W == int(v.size()));
        std::vector<T> ret(m.H);
        for (int i = 0; i < m.H; i++) {
            for (int j = 0; j < m.W; j++) ret[i] += m.get(i, j) * v[j];
        }
        return ret;
    }
    friend std::vector<T> operator*(const std::vector<T> &v, const matrix &m) {
        assert(int(v.size()) == m.H);
        std::vector<T> ret(m.W);
        for (int i = 0; i < m.H; i++) {
            for (int j = 0; j < m.W; j++) ret[j] += v[i] * m.get(i, j);
        }
        return ret;
    }
    std::vector<T> prod(const std::vector<T> &v) const { return (*this) * v; }
    std::vector<T> prod_left(const std::vector<T> &v) const { return v * (*this); }
    friend std::ostream &operator<<(std::ostream &os, const matrix &x) {
        os << "[(" << x.H << " * " << x.W << " matrix)";
        os << "\n[column sums: ";
        for (int j = 0; j < x.W; j++) {
            T s = 0;
            for (int i = 0; i < x.H; i++) s += x.get(i, j);
            os << s << ",";
        }
        os << "]";
        for (int i = 0; i < x.H; i++) {
            os << "\n[";
            for (int j = 0; j < x.W; j++) os << x.get(i, j) << ",";
            os << "]";
        }
        os << "]\n";
        return os;
    }
    friend std::istream &operator>>(std::istream &is, matrix &x) {
        for (auto &v : x.elem) is >> v;
        return is;
    }
};

// Solve Ax = b for T = ModInt<PRIME>
// - retval: {one of the solution, {freedoms}} (if solution exists)
//           {{}, {}} (otherwise)
// Complexity:
// - Yield one of the possible solutions: O(H^2 W) (H: # of eqs., W: # of variables)
// - Enumerate all of the bases: O(HW(H + W))
template <typename T> std::pair<std::vector<T>, std::vector<std::vector<T>>> system_of_linear_equations(matrix<T> A, std::vector<T> b) {
    int H = A.H, W = A.W;
    matrix<T> M(H, W + 1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) M[i][j] = A[i][j];
        M[i][W] = b[i];
    }
    M = M.gauss_jordan();
    std::vector<int> ss(W, -1);
    for (int i = 0; i < H; i++) {
        int j = 0;
        while (j <= W and M[i][j] == 0) j++;
        if (j == W) { // No solution
            return {{}, {}};
        }
        if (j < W) ss[j] = i;
    }
    std::vector<T> x(W);
    std::vector<std::vector<T>> D;
    for (int j = 0; j < W; j++) {
        if (ss[j] == -1) {
            // std::vector<T> d(W);
            // d[j] = 1;
            // for (int jj = 0; jj < j; jj++) {
            //     if (ss[jj] != -1) d[jj] = -M[ss[jj]][j] / M[ss[jj]][jj];
            // }
            // D.emplace_back(d);
        } else
            x[j] = M[ss[j]][W] / M[ss[j]][j];
    }
    return std::make_pair(x, D);
}

struct EnumerateTriangles {
    int V;
    std::vector<int> deg;
    std::vector<std::vector<int>> to;
    std::vector<std::pair<int, int>> edges;
    EnumerateTriangles(int N = 0) : V(N), deg(N), to(N) {}
    void add_edge(int s, int t) {
        assert(s >= 0 and s < V);
        assert(t >= 0 and t < V);
        assert(s != t);
        edges.emplace_back(s, t);
        deg[s]++, deg[t]++;
    }
    template <class F> void run(F f) {
        auto comp = [&](int i, int j) { return deg[i] != deg[j] ? deg[i] < deg[j] : i < j; };
        for (auto p : edges) {
            int s = p.first, t = p.second;
            if (comp(s, t)) {
                to[s].push_back(t);
            } else {
                to[t].push_back(s);
            }
        }
        std::vector<char> flag(V);
        for (int i = 0; i < V; i++) {
            for (auto j : to[i]) flag[j] = 1;
            for (auto j : to[i]) {
                for (auto k : to[j]) {
                    if (flag[k]) f(i, j, k);
                }
            }
            for (auto j : to[i]) flag[j] = 0;
        }
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> edges;
    EnumerateTriangles et(N);

    vector<pint> free_edges;
    vector<vector<pint>> to(N);
    map<pint, pint> st2eidw;

    REP(e, M) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        et.add_edge(a, b);
        if (w == 3) w = 0;
        edges.emplace_back(a, b, w);
        if (w >= 0) {
            to[a].emplace_back(b, w);
            to[b].emplace_back(a, w);
        } else {
            free_edges.emplace_back(a, b);
        }
        st2eidw[pint(a, b)] = st2eidw[pint(b, a)] = make_pair(e, w);
    }
    int Nvar = free_edges.size();
    map<int, int> eid2varid;
    REP(i, free_edges.size()) {
        auto [a, b] = free_edges[i];
        eid2varid[st2eidw.at(free_edges[i]).first] = i;
    }

    vector<vector<mint>> A;
    vector<mint> B;

    auto func = [&](int i, int j, int k) -> void {
        dbg((vector<int>{i, j, k}));
        auto [e1, w1] = st2eidw.at(pint(i, j));
        auto [e2, w2] = st2eidw.at(pint(k, j));
        auto [e3, w3] = st2eidw.at(pint(i, k));
        vector<int> efs;
        if (w1 < 0) efs.push_back(e1);
        if (w2 < 0) efs.push_back(e2);
        if (w3 < 0) efs.push_back(e3);
        mint sum = (max(0, w1) + max(0, w2) + max(0, w3)) % 3;
        if (efs.size()) {
            vector<mint> avec(Nvar);
            for (auto e : efs) avec[eid2varid[e]] += 1;
            A.push_back(avec);
            B.push_back(-sum);
        }
    };

    et.run(func);

    dbg(A);
    dbg(B);
    vector<mint> syssol;
    if (A.size()) {
        syssol = system_of_linear_equations(matrix<mint>(A), B).first;
    } else {
        syssol = vector<mint>(Nvar);
    }

    vector<mint> sol;
    for (auto [a, b, w] : edges) {
        pint e(a, b);
        if (w >= 0) sol.push_back(w);
        else {
            sol.push_back(syssol.at(eid2varid.at(st2eidw.at(e).first)));
        }
    }

    bool feasible = true;
    auto func2 = [&](int i, int j, int k) -> void {
        auto [e1, w1] = st2eidw.at(pint(i, j));
        auto [e2, w2] = st2eidw.at(pint(k, j));
        auto [e3, w3] = st2eidw.at(pint(i, k));
        mint sum = sol.at(e1) + sol.at(e2) + sol.at(e3);
        if (sum != 0) feasible = false;
    };
    et.run(func2);
    if (feasible) {
        for (auto x : sol) {
            int a = x.val;
            if (a == 0) a = 3;
            cout << a << ' ';
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}