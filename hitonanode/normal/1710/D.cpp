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
    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> ret(par.size());
        for (int i = 0; i < int(par.size()); ++i) ret[find(i)].push_back(i);
        ret.erase(std::remove_if(ret.begin(), ret.end(),
                                 [&](const std::vector<int> &v) { return v.empty(); }),
                  ret.end());
        return ret;
    }
};

// UnionFind, able to rewind to the previous state by undo()
// Written for Educational Codeforces 62 F, although not verified yet.
struct UndoUnionFind {
    using pint = std::pair<int, int>;
    std::vector<int> par, cou;
    std::stack<std::pair<int, pint>> history;
    UndoUnionFind(int N) : par(N), cou(N, 1) { std::iota(par.begin(), par.end(), 0); }
    int find(int x) const { return (par[x] == x) ? x : find(par[x]); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (cou[x] < cou[y]) std::swap(x, y);
        history.emplace(y, pint(par[y], cou[x]));
        return x != y ? par[y] = x, cou[x] += cou[y], true : false;
    }
    void undo() {
        cou[par[history.top().first]] = history.top().second.second;
        par[history.top().first] = history.top().second.first;
        history.pop();
    }
    void reset() {
        while (!history.empty()) undo();
    }
    int count(int x) const { return cou[find(x)]; }
    bool same(int x, int y) const { return find(x) == find(y); }
};


vector<pint> solve() {
    int N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) {
        string s;
        cin >> s;
        REP(j, i) S[i] += S[j][i];
        S[i] += s;
    }

    UndoUnionFind uf(N);
    vector<pint> ret;

    vector<int> rmin(N), rmax(N);

    FOR(sz, 2, N + 1) {
        vector<pint> temp_edges;
        REP(l, N - sz + 1) {
            int r = l + sz - 1;
            if (S[l][r] == '1') {
                int nundo = 0;
                if (!uf.same(l, r)) {
                    temp_edges.emplace_back(l, r);
                    uf.unite(l, r);
                    ++nundo;
                    vector<int> rs;
                    vector<int> r_isin(N);

                    FOR(i, l + 1, r) {
                        int root = uf.find(i);
                        if (!uf.same(l, root) and chmax(r_isin[root], 1)) {
                            rs.push_back(root);
                            rmin[root] = rmax[root] = i;
                        }
                    }

                    FOR(i, l + 1, r) {
                        int root = uf.find(i);
                        if (r_isin[root]) {
                            chmin(rmin[root], i);
                            chmax(rmax[root], i);
                        }
                    }

                    dbg(rs);

                    REP(dr, rs.size()) {
                        int root = rs[dr];
                        int s, t;
                        if (dr == 0) {
                            s = rmin[root], t = r;
                            // uf.unite(rmin[root], )
                        } else {
                            s = rmax[root], t = l;
                        }
                        temp_edges.emplace_back(s, t);
                        uf.unite(s, t);
                        ++nundo;
                    }

                    while (nundo--) {
                        uf.undo();
                    }
                }
            } else if (S[l][r] == '0') {
                //
            } else {
                exit(1);
            }
        }

        for (auto [l, r] : temp_edges) {
            ret.emplace_back(l, r);
            uf.unite(l, r);
        }
    }

    for (auto &e : ret) e = make_pair(min(e.first, e.second), max(e.first, e.second));
    ret = sort_unique(ret);
    assert(int(ret.size()) == N - 1);
    assert(uf.count(0) == N);
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        auto ret = solve();
        for (auto [x, y] : ret) cout << x + 1 << ' ' << y + 1 << '\n';
    }
}