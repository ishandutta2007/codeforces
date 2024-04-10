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

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind {
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) { iota(par.begin(), par.end(), 0); }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};


int main() {
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> edges;
    map<pint, vector<int>> wuv2es[2];

    vector<int> used_eid(M);
    vector<vector<int>> eids1(N), eids2(N);
    vector<int> degs1(N), degs2(N);
    REP(e, M) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.emplace_back(u, v, w);
        wuv2es[w - 1][pint(u, v)].push_back(e);
        if (w == 1) {
            eids1[u].push_back(e);
            eids1[v].push_back(e);
            degs1[u]++, degs1[v]++;
        } else {
            eids2[u].push_back(e);
            eids2[v].push_back(e);
            degs2[u]++, degs2[v]++;
        }
    }

    auto sol_paths = [&](vector<vector<int>> &eids, vector<int> &degs) -> vector<vector<int>> {
        vector<vector<int>> ret;
        auto find_edge = [&](int now) {
            while (eids[now].size()) {
                int e = eids[now].back();
                if (used_eid[e]) {
                    eids[now].pop_back();
                } else {
                    break;
                }
            }
            if (eids[now].empty()) return -1;
            return eids[now].back();
        };

        auto use_e = [&](int eid) {
            auto [u, v, w] = edges[eid];
            used_eid[eid] = 1;
            degs[u]--, degs[v]--;
        };

        REP(t, 2) {
            REP(i, N) {
                while (degs[i]) {
                    if (t == 0 and degs[i] % 2 == 0) break;
                    ret.push_back({});
                    int now = i;
                    int e = find_edge(now);
                    ret.back().push_back(now);
                    while (e >= 0) {
                        auto [u, v, w] = edges[e];
                        int nxt = u ^ v ^ now;
                        use_e(e);
                        now = nxt;
                        ret.back().push_back(now);
                        e = find_edge(now);
                    }
                }
            }
        }
        return ret;
    };

    vector<vector<int>> p1s = sol_paths(eids1, degs1);
    vector<vector<int>> p2s = sol_paths(eids2, degs2);

    dbg(degs1);
    dbg(degs2);
    assert(accumulate(ALL(degs1), 0) == 0);
    assert(accumulate(ALL(degs2), 0) == 0);

    int total_edges = 0;
    for (const auto &v : p1s) total_edges += v.size() - 1;
    for (const auto &v : p2s) total_edges += v.size() - 1;
    assert(total_edges == M);

    const int D1 = p1s.size(), D2 = p2s.size(), D = D1 + D2;

    UnionFind uf(D * 2);
    vector<int> v2pid(N, -1);
    REP(d, D1) {
        if (p1s[d].front() == p1s[d].back()) continue;
        assert(v2pid[p1s[d].front()] < 0);
        assert(v2pid[p1s[d].back()] < 0);
        v2pid[p1s[d].front()] = d;
        v2pid[p1s[d].back()] = d;
    }

    auto add_const = [&](int i1, int i2) {
        auto diff = [&](int i1, int i2) {
            uf.unite(i1, i2 + D);
            uf.unite(i2, i1 + D);
        };
        auto same = [&](int i1, int i2) {
            uf.unite(i1, i2);
            uf.unite(i1 + D, i2 + D);
        };
        if (p1s[i1].front() == p2s[i2].front()) diff(i1, i2 + D1);
        if (p1s[i1].back() == p2s[i2].back()) diff(i1, i2 + D1);
        if (p1s[i1].front() == p2s[i2].back()) same(i1, i2 + D1);
        if (p1s[i1].back() == p2s[i2].front()) same(i1, i2 + D1);
    };
    dbg(p1s);
    dbg(p2s);
    dbg(v2pid);

    REP(d, D2) {
        auto f = p2s[d].front(), b = p2s[d].back();
        if (f == b) continue;

        if (v2pid[f] >= 0) {
            int i1 = v2pid[f];
            add_const(i1, d);
        }
        if (v2pid[b] >= 0) {
            int i1 = v2pid[b];
            add_const(i1, d);
        }
    }

    auto is_trans = [&](int d) { return uf.find(d) < uf.find(d + D); };

    REP(d, D1) if (is_trans(d)) reverse(ALL(p1s[d]));
    REP(d, D2) if (is_trans(d + D1)) reverse(ALL(p2s[d]));
    dbg(p1s);
    dbg(p2s);

    string ret(M, '0');
    auto retrieve = [&](map<pint, vector<int>> &mp, const vector<vector<int>> &paths) {
        for (auto path : paths) {
            FOR(i, 1, path.size()) {
                int u = path[i - 1], v = path[i];
                if (mp.count(pint(u, v))) {
                    pint p(u, v);
                    int e = mp[p].back();
                    mp[p].pop_back();
                    if (mp[p].empty()) mp.erase(p);
                    ret[e] = '1';
                } else {
                    pint p(v, u);
                    assert(mp.count(p));
                    int e = mp[p].back();
                    mp[p].pop_back();
                    if (mp[p].empty()) mp.erase(p);
                    ret[e] = '2';
                }
            }
        }
    };
    retrieve(wuv2es[0], p1s);
    retrieve(wuv2es[1], p2s);

    assert(wuv2es[0].empty());
    assert(wuv2es[1].empty());

    int retcnt = 0;
    for (auto p : p1s) {
        if (p.front() != p.back()) retcnt += 2;
    }
    cout << retcnt << '\n' << ret << '\n';
}