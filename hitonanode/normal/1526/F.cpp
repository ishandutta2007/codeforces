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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
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

int N;
vector<int> ansansnas;

struct rand_int_ {
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r) {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;

void initialize() {
#ifdef HITONANODE_LOCAL
    N = rnd(20, 40);
    ansansnas.resize(N);
    iota(ALL(ansansnas), 0);
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    shuffle(ALL(ansansnas), rng);
    if (ansansnas[0] > ansansnas[1]) swap(ansansnas[0], ansansnas[1]);
    dbg(ansansnas);
#endif
}


int readn() {
#ifdef HITONANODE_LOCAL
    return N;
#else
    int n;
    cin >> n;
    return n;
#endif
}

int ask(int a, int b, int c) {
#ifdef HITONANODE_LOCAL
    // dbg((vector<int>{a, b, c}));
    // if (a == b or b == c or c == a) { dbg((vector<int>{a, b, c})); }
    assert(a != b and b != c and c != a);
    vector<int> v{abs(ansansnas[a] - ansansnas[b]), abs(ansansnas[b] - ansansnas[c]), abs(ansansnas[c] - ansansnas[a])};
    sort(ALL(v));
    return v[1];
#else
    cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
    int ret;
    cin >> ret;
    if (ret < 0) exit(8);
    return ret;
#endif
}
void answer(const vector<int> &P) {
#ifdef HITONANODE_LOCAL
    if (P != ansansnas) {
        dbg(P);
        dbg(ansansnas);
    }
    assert(P == ansansnas);
#else
    cout << "!";
    for (auto x : P) cout << ' ' << x + 1;
    cout << endl;
    int ret;
    cin >> ret;
#endif
}

void solve() {
    N = readn();
    vector<int> counter(N);
    vector<int> ret1(N);
    FOR(i, 2, N) {
        ret1[i] = ask(0, 1, i);
        counter[ret1[i]]++;
    }
    int lo = 0;
    while (!counter[lo]) lo++;
    vector<vector<int>> arg(N);
    FOR(i, 2, N) arg[ret1[i]].push_back(i);

    int d;

    auto height2perm = [](vector<int> height) {
        int N = height.size();
        vector<pint> h2i;
        REP(i, N) h2i.emplace_back(height[i], i);
        std::sort(h2i.begin(), h2i.end());
        vector<int> ret(N);
        REP(v, N) ret[h2i[v].second] = v;
        return ret;
    };

    // dbg(counter);
    vector<int> equal_dists(N);
    FOR(i, 1, N - 1) equal_dists[i] = 1;
    if (counter[lo] == 1 and counter != equal_dists) {
        d = lo * 2;
    } else if (lo == 1) {
        d = 1;
        vector<int> grp_lo, grp_hi;
        for (auto i1 : arg[1]) {
            for (auto i2 : arg[2]) {
                if (ask(0, i1, i2) == 1) grp_lo = {0, i1, i2};
                if (ask(1, i1, i2) == 1) grp_hi = {1, i1, i2};
            }
        }
        for (auto i : arg[1]) {
            if (grp_lo.empty() and !count(ALL(grp_hi), i)) grp_lo.push_back(i);
            if (grp_hi.empty() and !count(ALL(grp_lo), i)) grp_hi.push_back(i);
        }
        FOR(d, 3, N) {
            for (auto cand : arg[d]) {
                if (grp_lo.size() > 1 and ask(grp_lo.back(), grp_lo[grp_lo.size() - 2], cand) == 1) {
                    grp_lo.push_back(cand);
                } else {
                    grp_hi.push_back(cand);
                }
            }
        }
        vector<int> height(N);
        REP(j, grp_lo.size()) height[grp_lo[j]] = -1 - j;
        REP(j, grp_hi.size()) height[grp_hi[j]] = j;
        auto ret = height2perm(height);
        answer(ret);
        return;
    } else {
        d = lo * 2 - 1;
    }
    // dbg(d);
    int P = -1, Q = -1, R = -1;
    int P2 = -1, Q2 = -1, R2 = -1;
    if (d == 3) {
        for (auto x : arg[2]) {
            for (auto y : arg[3]) {
                if (ask(x, y, 0) == 1) P = x, Q = y;
                if (ask(x, y, 1) == 1) P2 = x, Q2 = y;
            }
        }
        if (P2 == -1) {
            for (auto x : arg[2]) if (x != P) P2 = x;
        }
        if (P == -1) {
            for (auto x : arg[2]) if (x != P2) P = x;
        }
    } else if (d == 2) {
        P = arg[1][0];
        for (auto y : arg[2]) {
            if (ask(y, P, 0) == 1) Q = y;
            if (ask(y, P, 1) == 1) Q2 = y;
        }
        chmax(P, P2);
        chmax(P2, P);
    } else {
        for (auto x : arg[d - 1]) {
            for (auto y : arg[d - 2]) {
                if (ask(x, y, 0) == 1) P = x, R = y;
                if (ask(x, y, 1) == 1) P2 = x, R2 = y;
            }
        }
    }
    vector<int> height(N, -1);
    height[0] = 0;
    height[1] = d;
    height[P] = 1;
    height[P2] = d - 1;
    FOR(i, 2, N) if (height[i] < 0) {
        if (ret1[i] < d) {
            height[i] = ask(0, P, i) + 1;
        } else {
            int tmp = ask(0, P, i);
            if (tmp < d) {
                height[i] = -tmp;
            } else if (tmp == d) {
                int t2 = ask(1, P2, i);
                if (t2 < d) {
                    height[i] = d + t2;
                } else {
                    height[i] = -d;
                }
            } else {
                if (ret1[i] == d) {
                    height[i] = tmp + 1;
                } else {
                    if (tmp == ret1[i]) {
                        height[i] = -tmp;
                    } else {
                        height[i] = tmp + 1;
                    }
                }
            }
        }
    }
    answer(height2perm(height));
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        initialize();
        solve();
    }
}