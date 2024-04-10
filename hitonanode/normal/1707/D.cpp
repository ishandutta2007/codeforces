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

struct ModIntRuntime {
private:
    static int md;

public:
    using lint = long long;
    static int mod() { return md; }
    int val_;
    static std::vector<ModIntRuntime> &facs() {
        static std::vector<ModIntRuntime> facs_;
        return facs_;
    }
    static int &get_primitive_root() {
        static int primitive_root_ = 0;
        if (!primitive_root_) {
            primitive_root_ = [&]() {
                std::set<int> fac;
                int v = md - 1;
                for (lint i = 2; i * i <= v; i++)
                    while (v % i == 0) fac.insert(i), v /= i;
                if (v > 1) fac.insert(v);
                for (int g = 1; g < md; g++) {
                    bool ok = true;
                    for (auto i : fac)
                        if (ModIntRuntime(g).power((md - 1) / i) == 1) {
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
        if (md != m) facs().clear();
        md = m;
        get_primitive_root() = 0;
    }
    ModIntRuntime &_setval(lint v) {
        val_ = (v >= md ? v - md : v);
        return *this;
    }
    int val() const noexcept { return val_; }
    ModIntRuntime() : val_(0) {}
    ModIntRuntime(lint v) { _setval(v % md + md); }
    explicit operator bool() const { return val_ != 0; }
    ModIntRuntime operator+(const ModIntRuntime &x) const {
        return ModIntRuntime()._setval((lint)val_ + x.val_);
    }
    ModIntRuntime operator-(const ModIntRuntime &x) const {
        return ModIntRuntime()._setval((lint)val_ - x.val_ + md);
    }
    ModIntRuntime operator*(const ModIntRuntime &x) const {
        return ModIntRuntime()._setval((lint)val_ * x.val_ % md);
    }
    ModIntRuntime operator/(const ModIntRuntime &x) const {
        return ModIntRuntime()._setval((lint)val_ * x.inv().val() % md);
    }
    ModIntRuntime operator-() const { return ModIntRuntime()._setval(md - val_); }
    ModIntRuntime &operator+=(const ModIntRuntime &x) { return *this = *this + x; }
    ModIntRuntime &operator-=(const ModIntRuntime &x) { return *this = *this - x; }
    ModIntRuntime &operator*=(const ModIntRuntime &x) { return *this = *this * x; }
    ModIntRuntime &operator/=(const ModIntRuntime &x) { return *this = *this / x; }
    friend ModIntRuntime operator+(lint a, const ModIntRuntime &x) {
        return ModIntRuntime()._setval(a % md + x.val_);
    }
    friend ModIntRuntime operator-(lint a, const ModIntRuntime &x) {
        return ModIntRuntime()._setval(a % md - x.val_ + md);
    }
    friend ModIntRuntime operator*(lint a, const ModIntRuntime &x) {
        return ModIntRuntime()._setval(a % md * x.val_ % md);
    }
    friend ModIntRuntime operator/(lint a, const ModIntRuntime &x) {
        return ModIntRuntime()._setval(a % md * x.inv().val() % md);
    }
    bool operator==(const ModIntRuntime &x) const { return val_ == x.val_; }
    bool operator!=(const ModIntRuntime &x) const { return val_ != x.val_; }
    bool operator<(const ModIntRuntime &x) const {
        return val_ < x.val_;
    } // To use std::map<ModIntRuntime, T>
    friend std::istream &operator>>(std::istream &is, ModIntRuntime &x) {
        lint t;
        return is >> t, x = ModIntRuntime(t), is;
    }
    friend std::ostream &operator<<(std::ostream &os, const ModIntRuntime &x) {
        return os << x.val_;
    }

    lint power(lint n) const {
        lint ans = 1, tmp = this->val_;
        while (n) {
            if (n & 1) ans = ans * tmp % md;
            tmp = tmp * tmp % md;
            n /= 2;
        }
        return ans;
    }
    ModIntRuntime pow(lint n) const { return power(n); }
    ModIntRuntime inv() const { return this->pow(md - 2); }

    ModIntRuntime fac() const {
        int l0 = facs().size();
        if (l0 > this->val_) return facs()[this->val_];

        facs().resize(this->val_ + 1);
        for (int i = l0; i <= this->val_; i++)
            facs()[i] = (i == 0 ? ModIntRuntime(1) : facs()[i - 1] * ModIntRuntime(i));
        return facs()[this->val_];
    }

    ModIntRuntime doublefac() const {
        lint k = (this->val_ + 1) / 2;
        return (this->val_ & 1)
                   ? ModIntRuntime(k * 2).fac() / (ModIntRuntime(2).pow(k) * ModIntRuntime(k).fac())
                   : ModIntRuntime(k).fac() * ModIntRuntime(2).pow(k);
    }

    ModIntRuntime nCr(const ModIntRuntime &r) const {
        return (this->val_ < r.val_) ? ModIntRuntime(0)
                                     : this->fac() / ((*this - r).fac() * r.fac());
    }

    ModIntRuntime sqrt() const {
        if (val_ == 0) return 0;
        if (md == 2) return val_;
        if (power((md - 1) / 2) != 1) return 0;
        ModIntRuntime b = 1;
        while (b.power((md - 1) / 2) == 1) b += 1;
        int e = 0, m = md - 1;
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
        return ModIntRuntime(std::min(x.val_, md - x.val_));
    }
};
int ModIntRuntime::md = 1;
using mint = ModIntRuntime;

int main() {
    int N, md;
    cin >> N >> md;
    mint::set_mod(md);

    vector<vector<int>> to(N);
    REP(e, N - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    auto rec = [&](auto &&self, int now, int prv) -> vector<mint> {
        vector<vector<mint>> dps;
        for (auto nxt : to[now]) {
            if (nxt == prv) continue;
            dps.push_back(self(self, nxt, now));
        }

        const int K = dps.size();

        vector<mint> ret(N + 1);
        vector<mint> cs(dps.size());
        vector<mint> odp(dps.size());

        vector<mint> lprod(K + 1, 1);
        vector<mint> rprod(K + 1, 1);

        REP(t, ret.size()) {
            mint prod_alive = 1;
            REP(k, dps.size()) {
                lprod[k + 1] = lprod[k] * cs[k];
                rprod[k + 1] = rprod[k] * cs[dps.size() - k - 1];
            }

            REP(k, dps.size()) {
                cs[k] += dps[k][t];
                prod_alive *= cs[k];
            }

            if (t) {
                REP(k, dps.size()) odp[k] += lprod[k] * rprod[K - 1 - k];
            }

            ret[t] += prod_alive;
            if (now) {
                REP(k, K) ret[t] += odp[k] * dps[k][t];
            }
        }
        dbg(make_pair(now, ret));
        return ret;
    };

    auto dp = rec(rec, 0, -1);
    dbg(dp);
    // FOR(i, 1, dp.size()) dp[i] += dp[i - 1];
    dp.insert(dp.begin(), 0);
    dbg(dp);

    FOR(i, 1, N) {
        REP(j, i) dp[i] -= dp[j] * mint(i).nCr(j);
        cout << dp[i] << ' ';
    }
    cout << '\n';
}