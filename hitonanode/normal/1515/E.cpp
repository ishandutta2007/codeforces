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
template <typename T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <typename T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
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

struct ModIntRuntime {
    using lint = long long int;
    static int get_mod() { return mod; }
    int val;
    static int mod;
    static std::vector<ModIntRuntime> &facs() {
        static std::vector<ModIntRuntime> facs_;
        return facs_;
    }
    static int &get_primitive_root() {
        static int primitive_root_ = 0;
        if (!primitive_root_) {
            primitive_root_ = [&]() {
                std::set<int> fac;
                int v = mod - 1;
                for (lint i = 2; i * i <= v; i++)
                    while (v % i == 0) fac.insert(i), v /= i;
                if (v > 1) fac.insert(v);
                for (int g = 1; g < mod; g++) {
                    bool ok = true;
                    for (auto i : fac)
                        if (ModIntRuntime(g).power((mod - 1) / i) == 1) {
                            ok = false;
                            break;
                        }
                    if (ok) return g;
                }
                return -1;
            }();
        }
        return primitive_root_;
    }
    static void set_mod(const int &m) {
        if (mod != m) facs().clear();
        mod = m;
        get_primitive_root() = 0;
    }
    ModIntRuntime &_setval(lint v) {
        val = (v >= mod ? v - mod : v);
        return *this;
    }
    ModIntRuntime() : val(0) {}
    ModIntRuntime(lint v) { _setval(v % mod + mod); }
    explicit operator bool() const { return val != 0; }
    ModIntRuntime operator+(const ModIntRuntime &x) const { return ModIntRuntime()._setval((lint)val + x.val); }
    ModIntRuntime operator-(const ModIntRuntime &x) const { return ModIntRuntime()._setval((lint)val - x.val + mod); }
    ModIntRuntime operator*(const ModIntRuntime &x) const { return ModIntRuntime()._setval((lint)val * x.val % mod); }
    ModIntRuntime operator/(const ModIntRuntime &x) const { return ModIntRuntime()._setval((lint)val * x.inv() % mod); }
    ModIntRuntime operator-() const { return ModIntRuntime()._setval(mod - val); }
    ModIntRuntime &operator+=(const ModIntRuntime &x) { return *this = *this + x; }
    ModIntRuntime &operator-=(const ModIntRuntime &x) { return *this = *this - x; }
    ModIntRuntime &operator*=(const ModIntRuntime &x) { return *this = *this * x; }
    ModIntRuntime &operator/=(const ModIntRuntime &x) { return *this = *this / x; }
    friend ModIntRuntime operator+(lint a, const ModIntRuntime &x) { return ModIntRuntime()._setval(a % mod + x.val); }
    friend ModIntRuntime operator-(lint a, const ModIntRuntime &x) { return ModIntRuntime()._setval(a % mod - x.val + mod); }
    friend ModIntRuntime operator*(lint a, const ModIntRuntime &x) { return ModIntRuntime()._setval(a % mod * x.val % mod); }
    friend ModIntRuntime operator/(lint a, const ModIntRuntime &x) { return ModIntRuntime()._setval(a % mod * x.inv() % mod); }
    bool operator==(const ModIntRuntime &x) const { return val == x.val; }
    bool operator!=(const ModIntRuntime &x) const { return val != x.val; }
    bool operator<(const ModIntRuntime &x) const { return val < x.val; } // To use std::map<ModIntRuntime, T>
    friend std::istream &operator>>(std::istream &is, ModIntRuntime &x) {
        lint t;
        return is >> t, x = ModIntRuntime(t), is;
    }
    friend std::ostream &operator<<(std::ostream &os, const ModIntRuntime &x) { return os << x.val; }

    lint power(lint n) const {
        lint ans = 1, tmp = this->val;
        while (n) {
            if (n & 1) ans = ans * tmp % mod;
            tmp = tmp * tmp % mod;
            n /= 2;
        }
        return ans;
    }
    ModIntRuntime pow(lint n) const { return power(n); }
    lint inv() const { return this->power(mod - 2); }

    ModIntRuntime fac() const {
        int l0 = facs().size();
        if (l0 > this->val) return facs()[this->val];

        facs().resize(this->val + 1);
        for (int i = l0; i <= this->val; i++) facs()[i] = (i == 0 ? ModIntRuntime(1) : facs()[i - 1] * ModIntRuntime(i));
        return facs()[this->val];
    }

    ModIntRuntime doublefac() const {
        lint k = (this->val + 1) / 2;
        return (this->val & 1) ? ModIntRuntime(k * 2).fac() / (ModIntRuntime(2).pow(k) * ModIntRuntime(k).fac()) : ModIntRuntime(k).fac() * ModIntRuntime(2).pow(k);
    }

    ModIntRuntime nCr(const ModIntRuntime &r) const { return (this->val < r.val) ? ModIntRuntime(0) : this->fac() / ((*this - r).fac() * r.fac()); }

    ModIntRuntime sqrt() const {
        if (val == 0) return 0;
        if (mod == 2) return val;
        if (power((mod - 1) / 2) != 1) return 0;
        ModIntRuntime b = 1;
        while (b.power((mod - 1) / 2) == 1) b += 1;
        int e = 0, m = mod - 1;
        while (m % 2 == 0) m >>= 1, e++;
        ModIntRuntime x = power((m - 1) / 2), y = (*this) * x * x;
        x *= (*this);
        ModIntRuntime z = b.power(m);
        while (y != 1) {
            int j = 0;
            ModIntRuntime t = y;
            while (t != 1) j++, t *= t;
            z = z.power(1LL << (e - j - 1));
            x *= z, z *= z, y *= z;
            e = j;
        }
        return ModIntRuntime(std::min(x.val, mod - x.val));
    }
};
int ModIntRuntime::mod = 1;
using mint = ModIntRuntime;

int main() {
    int N, M;
    cin >> N >> M;
    mint::set_mod(M);

    vector ncr(N * 2 + 2, vector<mint>(N * 2 + 2));
    REP(i, ncr.size()) ncr[i][0] = 1;
    FOR(i, 1, ncr.size()) FOR(j, 1, ncr[i].size()) ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];

    vector<mint> lendp(N + 2);
    lendp[1] = 1;
    FOR(i, 2, lendp.size()) {
        lendp[i] = lendp[i - 1] * 2;
    }

    vector dp(N + 10, vector<mint>(N + 10));
    dp[0][0] = 1;
    REP(l, N) {
        REP(k, N + 1) {
            if (dp[l][k]) {
                dp[l + 2][k + 1] += dp[l][k];
                FOR(w, 2, N + 1) {
                    int nx = l + w + 1;
                    if (nx > N + 2) break;
                    dp[nx][k + w] += dp[l][k] * lendp[w] / mint(w).fac();
                }
            }
        }
    }
    mint ret = 0;
    dbg(dp[N + 1][0]);
    dbg(dp[N + 1][1]);
    dbg(dp[N + 1][2]);
    dbg(dp[N + 1][3]);
    REP(k, N + 3) { ret += dp[N + 1][k] * mint(k).fac(); }

    // FOR(n, 2, N + 1) {
    //     int sp = N - n;
    //     if (sp >= n) continue;
    //     ret += mint(n).fac() * ncr[n - 1][sp];
    // }
    cout << ret << '\n';

    // vector dp(N + 2, vector<mint>(N + 2));
    // dp[1][1] = 1;
    // FOR(w, 2, N + 1) FOR(k, 2, N + 1) {
    //     mint tmp = dp[w - 1][k - 1] * 2;
    //     if (w > 2) tmp += dp[w - 2][k - 1] * 2;
    //     FOR(l, 1, w - 2) {
    //         int r = w - 2 - l;
    //         FOR(kl, 1, k - 1) {
    //             int kr = k - 1 - kl;
    //             tmp += dp[l][kl] * dp[r][kr] * ncr[kl + kr][kl] * 2;
    //         }
    //     }
    //     FOR(l, 1, w - 3) {
    //         int r = w - 3 - l;
    //         FOR(kl, 1, k - 1) {
    //             int kr = k - 1 - kl;
    //             tmp += dp[l][kl] * dp[r][kr] * ncr[kl + kr][kl];
    //         }
    //     }
    //     dp[w][k] = tmp;
    // }
    // dbg(dp[1][1]);
    // dbg(dp[1][2]);
    // dbg(dp[2][1]);
    // dbg(dp[2][2]);
    // dbg(dp[3][1]);
    // dbg(dp[3][2]);
    // dbg(dp[3][3]);
    // cout << accumulate(ALL(dp[N]), mint(0)) << '\n';
}