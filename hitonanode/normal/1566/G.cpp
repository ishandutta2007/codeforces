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



int main() {
    auto START = std::chrono::system_clock::now();

    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> init_edges;
    map<pint, int> mp;
    REP(t, M) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        mp[minmax(a, b)] = w;
        init_edges.emplace_back(a, b, w);
    }
    int Q;
    cin >> Q;
    vector<tuple<int, int, int, int>> query;
    constexpr int ADD = 1, RM = 0;
    REP(q, Q) {
        int tp, u, v, w = -1;
        cin >> tp >> v >> u;
        u--, v--;
        if (tp == ADD) {
            cin >> w;
            mp[minmax(u, v)] = w;
        } else if (tp == RM) {
            w = mp.at(minmax(u, v));
        } else {
            throw;
        }
        query.emplace_back(tp, u, v, w);
    }
    // dbg(init_edges);
    // dbg(query);
    vector<lint> ret(Q + 1, 1LL << 60);
    {
        // a-b, a-c, a-d
        vector<multiset<int>> vms(N);
        for (auto [a, b, w] : init_edges) {
            vms[a].insert(w);
            vms[b].insert(w);
        }
        multiset<lint> sum_lo_3;

        auto calc_sum = [&](int i) {
            auto itr = vms[i].begin();
            lint sum = *itr;
            REP(t, 2) {
                ++itr;
                sum += *itr;
            }
            return sum;
        };

        auto add = [&](int i) {
            if (vms[i].size() >= 3) {
                lint sum = calc_sum(i);
                sum_lo_3.insert(sum);
            }
        };

        auto rm = [&](int i) {
            if (vms[i].size() >= 3) {
                lint sum = calc_sum(i);
                sum_lo_3.erase(sum_lo_3.lower_bound(sum));
            }
        };

        int nq = 0;
        auto get_ans = [&]() -> void {
            if (sum_lo_3.size()) chmin(ret[nq], *sum_lo_3.begin());
            nq++;
        };

        REP(i, N) add(i);
        get_ans();
        for (auto [tp, a, b, w] : query) {
            if (tp == RM) {
                rm(a);
                rm(b);
                vms[a].erase(w);
                vms[b].erase(w);
                add(a);
                add(b);
            } else if (tp == ADD) {
                rm(a);
                rm(b);
                vms[a].insert(w);
                vms[b].insert(w);
                add(a);
                add(b);
            } else {
                throw;
            }
            get_ans();
        }
        assert(nq == Q + 1);
    }

    REP(t, 100) {
        int64_t spent_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - START).count();
        if (spent_ms > 1900) break;

        // a-b / c-d
        vector<int> color(N);
        REP(i, N) color[i] = rnd(2);
        multiset<int> ms[2];
        auto add_e = [&](int a, int b, int w) {
            a = color[a], b = color[b];
            if (a == b) ms[a].insert(w);
        };
        auto erase_e = [&](int a, int b, int w) {
            a = color[a], b = color[b];
            if (a == b) ms[a].erase(ms[a].lower_bound(w));
        };

        int nq = 0;
        auto get_ans = [&]() -> void {
            if (ms[0].size() and ms[1].size()) chmin(ret[nq], lint(*ms[0].begin()) + *ms[1].begin());
            nq++;
        };
        for (auto [a, b, w] : init_edges) add_e(a, b, w);

        get_ans();
        for (auto [tp, a, b, w] : query) {
            if (tp == 0) erase_e(a, b, w);
            else add_e(a, b, w);
            get_ans();
        }
        assert(nq == Q + 1);
    }

    for (auto x : ret) cout << x << '\n';
}