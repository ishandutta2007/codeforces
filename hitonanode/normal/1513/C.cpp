#include <bits/stdc++.h>
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
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
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
#else
#define dbg(x) (x)
#endif

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
        if (this->val < std::min(mod >> 1, 1 << 21)) {
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
        return (this->val & 1) ? ModInt(k * 2).fac() / (ModInt(2).pow(k) * ModInt(k).fac())
                               : ModInt(k).fac() * ModInt(2).pow(k);
    }
    MDCONST ModInt nCr(const ModInt &r) const {
        return (this->val < r.val) ? 0 : this->fac() / ((*this - r).fac() * r.fac());
    }

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
using mint = ModInt<1000000007>;

template <typename T> struct matrix {
    int H, W;
    std::vector<T> elem;
    typename std::vector<T>::iterator operator[](int i) { return elem.begin() + i * W; }
    inline T &at(int i, int j) { return elem[i * W + j]; }
    inline T get(int i, int j) const { return elem[i * W + j]; }
    operator std::vector<std::vector<T>>() const {
        std::vector<std::vector<T>> ret(H);
        for (int i = 0; i < H; i++)
            std::copy(elem.begin() + i * W, elem.begin() + (i + 1) * W, std::back_inserter(ret[i]));
        return ret;
    }

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
        for (auto &x : ret.elem) x /= v;
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
                for (int j = 0; j < r.W; j++) { ret.at(i, j) += this->get(i, k) * r.get(k, j); }
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
        if (n == 0) return ret;
        for (int i = 63 - __builtin_clzll(n); i >= 0; i--) {
            ret *= ret;
            if ((n >> i) & 1) ret *= (*this);
        }
        return ret;
    }
    matrix transpose() const {
        matrix ret(W, H);
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++) ret.at(j, i) = this->get(i, j);
        return ret;
    }
    // Gauss-Jordan elimination
    // - Require inverse for every non-zero element
    // - Complexity: O(H^2 W)
    matrix gauss_jordan() const {
        int c = 0;
        matrix mtr(*this);
        std::vector<int> ws;
        ws.reserve(W);
        for (int h = 0; h < H; h++) {
            if (c == W) break;
            int piv = -1;
            for (int j = h; j < H; j++)
                if (mtr.get(j, c)) {
                    piv = j;
                    break;
                }
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
            const T hcinv = mtr.at(h, c).inv();
            for (int hh = 0; hh < H; hh++)
                if (hh != h) {
                    const T coeff = mtr.at(hh, c) * hcinv;
                    for (auto w : ws) mtr.at(hh, w) -= mtr.at(h, w) * coeff;
                }
            c++;
        }
        return mtr;
    }
    int rank_of_gauss_jordan() const {
        for (int i = H * W - 1; i >= 0; i--)
            if (elem[i]) return i / W + 1;
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
            if (ti == H)
                continue;
            else
                rank++;
            ret[i].swap(ret[ti]), tmp[i].swap(tmp[ti]);
            T inv = tmp[i][i].inv();
            for (int j = 0; j < W; j++) { ret[i][j] *= inv; }
            for (int j = i + 1; j < W; j++) { tmp[i][j] *= inv; }
            for (int h = 0; h < H; h++) {
                if (i == h) continue;
                const T c = -tmp[h][i];
                for (int j = 0; j < W; j++) { ret[h][j] += ret[i][j] * c; }
                for (int j = i + 1; j < W; j++) { tmp[h][j] += tmp[i][j] * c; }
            }
        }
        *this = ret;
        return rank;
    }
    friend std::vector<T> operator*(const matrix &m, const std::vector<T> &v) {
        assert(m.W == int(v.size()));
        std::vector<T> ret(m.H);
        for (int i = 0; i < m.H; i++) {
            for (int j = 0; j < m.W; j++) { ret[i] += m.get(i, j) * v[j]; }
        }
        return ret;
    }
    friend std::vector<T> operator*(const std::vector<T> &v, const matrix &m) {
        assert(int(v.size()) == m.H);
        std::vector<T> ret(m.W);
        for (int i = 0; i < m.H; i++) {
            for (int j = 0; j < m.W; j++) { ret[j] += v[i] * m.get(i, j); }
        }
        return ret;
    }
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

// Fibonacci numbers f(n) = af(n - 1) + bf(n - 2)
// Example (a = b = 1): 0=>1, 1=>1, 2=>2, 3=>3, 4=>5, ...
template <typename T> T Fibonacci(long long int k, int a = 1, int b = 1) {
    matrix<T> mat(2, 2);
    mat[0][1] = 1;
    mat[1][0] = b;
    mat[1][1] = a;
    return mat.pow(k + 1)[0][1];
}

matrix<mint> mat;

vector<matrix<mint>> mats;

mint solve() {
    int N, M;
    cin >> N >> M;
    vector<mint> v(10);
    while (N) {
        v[N % 10] += 1;
        N /= 10;
    }
    REP(d, 30) {
        if ((M >> d) & 1) {
            v = mats[d + 1] * v;
        }
    }
    return accumulate(v.begin(), v.end(), mint(0));
}

int main() {
    mat = matrix<mint>(10, 10);
    mats.resize(31);
    REP(i, 9) mat[i + 1][i] = 1;
    mat[1][9] = mat[0][9] = 1;
    mats[1] = mat;
    FOR(i, 2, mats.size()) mats[i] = mats[i - 1] * mats[i - 1];
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}