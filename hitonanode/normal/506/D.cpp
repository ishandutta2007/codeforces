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
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
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
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind
{
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) {
        iota(par.begin(), par.end(), 0);
    }
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

// UnionFind, able to rewind to the previous state by undo()
// Written for Educational Codeforces 62 F, although not verified yet.
struct UndoSizeAwareUnionFind
{
    using pint = std::pair<int, int>;
    std::vector<int> par, cou;
    std::stack<std::pair<int, pint>> history;
    UndoSizeAwareUnionFind(int N) : par(N), cou(N, 1) {
        std::iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return (par[x] == x) ? x :find(par[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (cou[x] < cou[y]) std::swap(x, y);
        history.emplace(y, pint(par[y], cou[x]));
        if (x != y) par[y] = x, cou[x] += cou[y];
    }
    void undo() {
        cou[par[history.top().first]] = history.top().second.second;
        par[history.top().first] = history.top().second.first;
        history.pop();
    }
    void reset() {
        while (!history.empty()) undo();
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


constexpr int ETH = 300;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<pint>> c2e(M + 1);
    REP(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        c2e[c].emplace_back(a, b);
    }
    vector<pint> sz2c;
    REP(c, c2e.size()) {
        if (c2e[c].size()) {
            sz2c.emplace_back(c2e[c].size(), c);
        }
    }
    sort(sz2c.begin(), sz2c.end());

    int Q;
    cin >> Q;
    vector<pint> UV;
    REP(i, Q) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        UV.emplace_back(u, v);
    }

    vector<int> ret(Q);

    for (auto [sz, c] : sz2c) {
        if (sz < ETH) continue;
        UnionFind uf(N);
        for (auto [a, b] : c2e[c]) {
            uf.unite(a, b);
        }
        REP(i, Q) {
            if (uf.same(UV[i].first, UV[i].second)) {
                ret[i]++;
            }
        }
    }

    while (sz2c.size() and sz2c.back().first >= ETH) sz2c.pop_back();

    UndoSizeAwareUnionFind uf(N);
    constexpr int B = 100;
    vector<unordered_map<int, int>> vmp(N);

    for (int l = 0; l < sz2c.size(); l += B) {
        REP(i, N) vmp[i].clear();

        const int r = min<int>(l + B, sz2c.size());
        FOR(d, l, r) {
            const int c = sz2c[d].second;
            shuffle(ALL(c2e[c]), rng);
            vector<int> vs;
            for (auto [a, b] : c2e[c]) {
                uf.unite(a, b);
                vs.emplace_back(a), vs.emplace_back(b);
            }
            vs = srtunq(vs);
            REP(j, vs.size()) REP(i, j) if (uf.same(vs[i], vs[j])) {
                vmp[vs[i]][vs[j]]++;
            }
            uf.reset();
        }
        REP(i, Q) {
            const int u = UV[i].first, v = UV[i].second;
            if (vmp[u].count(v)) {
                ret[i] += vmp[u][v];
            }
        }
    }
    for (auto x : ret) cout << x << '\n';
}