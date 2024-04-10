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
template <class T1, class T2> std::pair<T1, T2> operator+(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first + r.first, l.second + r.second); }
template <class T1, class T2> std::pair<T1, T2> operator-(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first - r.first, l.second - r.second); }
template <class T> std::vector<T> sort_unique(std::vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <class T> int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <class T> int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <class IStream, class T> IStream &operator>>(IStream &is, std::vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec);
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr);
template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec);
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const pair<T, U> &pa);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec);
template <class OStream, class T> OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec);
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa);
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp);
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp);
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl);

template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <class... T> std::istream &operator>>(std::istream &is, std::tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <class OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl) { os << '('; std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os << ')'; }
#endif
template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
template <class OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) std::cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << std::endl
#define dbgif(cond, x) ((cond) ? std::cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << std::endl : std::cerr)
#else
#define dbg(x) ((void)0)
#define dbgif(cond, x) ((void)0)
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


// Max size min weight two spanning forests
// Complexity: O(NM + M log M)
// Reference: https://www.slideshare.net/tmaehara/ss-17402143
// Verified:
// - https://www.codechef.com/submit/HAMEL
// - https://community.topcoder.com/stat?c=problem_statement&pm=14909&rd=17198
template <class Label, class W = int>
std::pair<std::vector<bool>, std::vector<bool>>
edge_disjoint_min_spanning_forests(const std::vector<std::pair<Label, Label>> &edges,
                                   const std::vector<W> &ws = {}) {
    assert(ws.empty() or ws.size() == edges.size());
    const int M = edges.size();
    std::vector<Label> lbl(M * 2);
    for (int e = 0; e < M; e++) lbl[e * 2] = edges[e].first, lbl[e * 2 + 1] = edges[e].second;
    std::sort(lbl.begin(), lbl.end());
    lbl.erase(std::unique(lbl.begin(), lbl.end()), lbl.end());
    const int N = lbl.size();

    std::vector<std::pair<int, int>> uvs(M);
    for (int e = 0; e < M; e++) {
        int u = std::lower_bound(lbl.begin(), lbl.end(), edges[e].first) - lbl.begin();
        int v = std::lower_bound(lbl.begin(), lbl.end(), edges[e].second) - lbl.begin();
        uvs[e] = {u, v};
    }

    std::vector<int> es(M);
    std::iota(es.begin(), es.end(), 0);
    if (!ws.empty()) std::sort(es.begin(), es.end(), [&](int i, int j) { return ws[i] < ws[j]; });

    UnionFind uf1(N);
    UnionFind uf2(N);

    std::vector<std::vector<bool>> I(2, std::vector<bool>(M));
    std::vector<std::vector<std::pair<int, int>>> to(N);

    int nb_accepted_edges = 0;
    auto accept_edge = [&](int e) {
        nb_accepted_edges++;
        int u = uvs[e].first, v = uvs[e].second;
        to[u].emplace_back(v, e);
        to[v].emplace_back(u, e);
    };

    auto dfs = [&](int head, const std::vector<bool> &I) -> std::vector<std::pair<int, int>> {
        std::vector<int> st{head};
        std::vector<std::pair<int, int>> prv(N, {-1, -1});
        prv[head] = {head, -1};
        while (!st.empty()) {
            int now = st.back();
            st.pop_back();
            for (auto p : to[now]) {
                int nxt = p.first, e = p.second;
                if (!I[e] or prv[nxt].first >= 0) continue;
                prv[nxt] = {now, e}, st.push_back(nxt);
            }
        }
        return prv;
    };

    std::vector<int> prveid(M, -1), visited(N);
    std::vector<std::vector<int>> L(2);
    std::vector<std::vector<std::pair<int, int>>> prv(2);
    for (const int e : es) {
        if (nb_accepted_edges > 2 * (N - 1)) break;
        const int u = uvs[e].first, v = uvs[e].second;

        bool found = false;

        if (!uf1.same(u, v)) {
            uf1.unite(u, v);
            accept_edge(e);
            I[0][e] = 1;
            found = true;
        } else if (!uf2.same(u, v)) {
            uf2.unite(u, v);
            accept_edge(e);
            I[1][e] = 1;
            found = true;
        }

        if (found) continue;

        for (int d = 0; d < 2; d++) {
            prv[d] = dfs(u, I[d]);
            if (prv[d][v].first < 0) {
                accept_edge(e);
                I[d][e] = 1;
                found = true;
                break;
            }
        }
        if (found) continue;

        visited.assign(N, 0);
        visited[u] = 1;
        L[0] = {e}, L[1] = {};

        int ehead = -1;
        prveid[e] = -1;
        for (int i = 0;; i ^= 1) {
            if (L[i].empty()) break;
            L[i ^ 1].clear();
            while (!L[i].empty()) {
                const int exy = L[i].back();
                L[i].pop_back();
                int x = uvs[exy].first, y = uvs[exy].second;
                if (prv[i][x].first < 0 or prv[i][y].first < 0) {
                    ehead = exy;
                    break;
                }
                if (!visited[x]) std::swap(x, y);
                while (!visited[y]) {
                    int nxty = prv[i][y].first, nxte = prv[i][y].second;
                    L[i ^ 1].push_back(nxte);
                    visited[y] = 1;
                    y = nxty;
                    prveid[nxte] = exy;
                }
            }
            if (ehead >= 0) {
                accept_edge(e);
                int c = I[0][ehead];
                for (; ehead >= 0; ehead = prveid[ehead], c ^= 1) {
                    I[c][ehead] = 1, I[c ^ 1][ehead] = 0;
                }
                break;
            }
        }
    }
    return {I[0], I[1]};
}

string solve() {
    int N, M;
    cin >> N >> M;
    vector<pint> edges(M);
    for (auto &[a, b] : edges) {
        cin >> a >> b;
        --a, --b;
    }
    auto [I1, I2] = edge_disjoint_min_spanning_forests<int>(edges);
    string ret(M, '0');
    REP(i, M) if (I2.at(i)) ret[i] = '1';
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
        // cout << (solve() ? "YES" : "NO") << '\n';
    }
}