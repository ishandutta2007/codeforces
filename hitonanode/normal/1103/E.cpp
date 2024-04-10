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

using ull = unsigned long long;
ull power(ull x, ull n)
{
    ull ans = 1;
    while (n) {
        if (n & 1) ans *= x;
        x *= x;
        n >>= 1;
    }
   return ans;
}
// Solve ax+by=gcd(a, b)
lint extgcd(lint a, lint b, lint &x, lint &y)
{
    lint d = a;
    if (b != 0) d = extgcd(b, a % b, y, x), y -= (a / b) * x;
    else x = 1, y = 0;
    return d;
}
// Calc a^(-1) (MOD m)
lint mod_inverse(lint a, lint m)
{
    lint x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;

    constexpr int len = 100000;
    vector f(4, vector<ull>(len));

    vector g(4, array<ull, 10>());
    vector gdft(4, array<ull, 10>());

    vector cyc(121, vector<ull>(4));
    REP(k, 4) cyc[k][k] = 1;
    FOR(k, 4, cyc.size()) {
        cyc[k][0] = -cyc[k - 1][3];
        cyc[k][1] = cyc[k - 1][0] + cyc[k - 1][3];
        cyc[k][2] = cyc[k - 1][1] - cyc[k - 1][3];
        cyc[k][3] = cyc[k - 1][2] + cyc[k - 1][3];
    }

    auto dft = [&](int h, int dx) -> void {
        REP(d, g.size()) {
            REP(i, g[d].size()) g[d][i] = f[d][h + dx * i];
        }
        for (auto &v : gdft) v.fill(0);
        REP(d, 4) REP(i, 10) REP(j, 10) {
            REP(e, 4) gdft[e][j] += cyc[d + i * j][e] * g[d][i];
        }
        REP(d, gdft.size()) REP(i, gdft[d].size()) f[d][h + dx * i] = gdft[d][i];
    };

    auto idft = [&](int h, int dx) -> void {
        REP(d, g.size()) {
            REP(i, g[d].size()) g[d][i] = f[d][h + dx * i];
        }
        for (auto &v : gdft) v.fill(0);
        REP(d, 4) REP(i, 10) REP(j, 10) {
            REP(e, 4) gdft[e][j] += cyc[d + i * (10 - j)][e] * g[d][i];
        }
        REP(d, gdft.size()) REP(i, gdft[d].size()) f[d][h + dx * i] = gdft[d][i];
    };

    for (auto a : A) f[0][a]++;

    REP(i, N) dbg(f[0][i]);
    for (int d = 0, dx = 1; d < 5; d++, dx *= 10) {
        for (int h = 0; h < len; h++) {
            if ((h / dx) % 10 == 0) {
                dft(h, dx);
            }
        }
    }

    auto pow = [&](vector<ull> F, int n) -> vector<ull> {
        const int D = F.size();
        vector<ull> ret(D);
        ret[0] = 1;
        auto conv = [&](const vector<ull> &l, const vector<ull> &r) {
            vector<ull> ret(D);
            REP(i, D) REP(j, D) {
                REP(e, D) ret[e] += l[i] * r[j] * cyc[i + j][e];
            }
            return ret;
        };
        while (n) {
            if (n & 1) ret = conv(ret, F);
            F = conv(F, F);
            n >>= 1;
        }
        return ret;
    };

    vector<ull> G{1, 1, 3, 0};
    dbg(pow(G, 2));

    REP(i, len) {
        vector<ull> g(4);
        REP(d, g.size()) g[d] = f[d][i];
        g = pow(g, N);
        REP(d, g.size()) f[d][i] = g[d];
    }

    for (int d = 0, dx = 1; d < 5; d++, dx *= 10) {
        for (int h = 0; h < len; h++) {
            if ((h / dx) % 10 == 0) {
                idft(h, dx);
            }
        }
    }
    constexpr ull inv5 = 57646075230342349;
    constexpr ull md = 1LL << 58;
    REP(i, N) {
        ull ret = f[0][i];
        dbg(f[0][i]);
        REP(t, 5) ret = ret * inv5;
        cout << (ret >> 5) % md << '\n';
    }
}