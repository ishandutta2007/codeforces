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


/*
(Recursive) Centroid Decomposition
Verification: Codeforces #190 Div.1 C <https://codeforces.com/contest/321/submission/59093583>

fix_root(int r): Build information of the tree which `r` belongs to.
detect_centroid(int r): Enumerate centroid(s) of the tree which `r` belongs to.
*/
struct CentroidDecomposition {
    int NO_PARENT = -1;
    int V;
    int E;
    std::vector<std::vector<std::pair<int, int>>> to; // (node_id, edge_id)
    std::vector<int> par;                             // parent node_id par[root] = -1
    std::vector<std::vector<int>> chi;                // children id's
    std::vector<int> subtree_size;                    // size of each subtree
    std::vector<int> available_edge;                  // If 0, ignore the corresponding edge.

    CentroidDecomposition(int v = 0) : V(v), E(0), to(v), par(v, NO_PARENT), chi(v), subtree_size(v) {}
    CentroidDecomposition(const std::vector<std::vector<int>> &to_) : CentroidDecomposition(to_.size()) {
        for (int i = 0; i < V; i++) {
            for (auto j : to_[i]) {
                if (i < j) { add_edge(i, j); }
            }
        }
    }

    void add_edge(int v1, int v2) {
        to[v1].emplace_back(v2, E), to[v2].emplace_back(v1, E), E++;
        available_edge.emplace_back(1);
    }

    int _dfs_fixroot(int now, int prv) {
        chi[now].clear(), subtree_size[now] = 1;
        for (auto nxt : to[now]) {
            if (nxt.first != prv and available_edge[nxt.second]) {
                par[nxt.first] = now, chi[now].push_back(nxt.first);
                subtree_size[now] += _dfs_fixroot(nxt.first, now);
            }
        }
        return subtree_size[now];
    }

    void fix_root(int root) {
        par[root] = NO_PARENT;
        _dfs_fixroot(root, -1);
    }

    //// Centroid Decpmposition ////
    std::vector<int> centroid_cand_tmp;
    void _dfs_detect_centroids(int now, int prv, int n) {
        bool is_centroid = true;
        for (auto nxt : to[now]) {
            if (nxt.first != prv and available_edge[nxt.second]) {
                _dfs_detect_centroids(nxt.first, now, n);
                if (subtree_size[nxt.first] > n / 2) is_centroid = false;
            }
        }
        if (n - subtree_size[now] > n / 2) is_centroid = false;
        if (is_centroid) centroid_cand_tmp.push_back(now);
    }
    std::pair<int, int> detect_centroids(int r) { // ([centroid_node_id1], ([centroid_node_id2]|-1))
        centroid_cand_tmp.clear();
        while (par[r] != NO_PARENT) r = par[r];
        int n = subtree_size[r];
        _dfs_detect_centroids(r, -1, n);
        if (centroid_cand_tmp.size() == 1)
            return std::make_pair(centroid_cand_tmp[0], -1);
        else
            return std::make_pair(centroid_cand_tmp[0], centroid_cand_tmp[1]);
    }

    std::vector<int> _cd_vertices;
    void _centroid_decomposition(int now) {
        fix_root(now);
        now = detect_centroids(now).first;
        _cd_vertices.emplace_back(now);
        /*
        do something
        */
        for (auto p : to[now]) {
            int nxt, eid;
            std::tie(nxt, eid) = p;
            if (available_edge[eid] == 0) continue;
            available_edge[eid] = 0;
            _centroid_decomposition(nxt);
        }
    }
    std::vector<int> centroid_decomposition(int x) {
        _cd_vertices.clear();
        _centroid_decomposition(x);
        return _cd_vertices;
    }
};

// StarrySkyTree: segment tree for Range Minimum Query & Range Add Query
// Complexity: O(N) (construction), O(lg N) (add / get)
template <typename Tp> struct RangeAddRangeMin {
    int N, head;
    Tp defaultMin;
    std::vector<Tp> range_min, range_add;
    static inline Tp f(Tp x, Tp y) noexcept { return std::min(x, y); }

    inline void _merge(int pos) { range_min[pos] = f(range_min[pos * 2] + range_add[pos * 2], range_min[pos * 2 + 1] + range_add[pos * 2 + 1]); }
    void initialize(const std::vector<Tp> &data_init, Tp default_min) {
        N = data_init.size(), head = 1;
        while (head < N) head <<= 1;
        defaultMin = default_min;
        range_min.assign(head * 2, defaultMin);
        range_add.assign(head * 2, pint(0, 0));
        std::copy(data_init.begin(), data_init.end(), range_min.begin() + head);
        for (int pos = head; --pos;) _merge(pos);
    }
    RangeAddRangeMin() = default;
    RangeAddRangeMin(const std::vector<Tp> &data_init, Tp default_min) { initialize(data_init, default_min); }
    void _add(int begin, int end, int pos, int l, int r, Tp vadd) noexcept {
        if (r <= begin or end <= l) return;
        if (begin <= l and r <= end) {
            range_add[pos] = range_add[pos] + vadd;
            return;
        }
        _add(begin, end, pos * 2, l, (l + r) / 2, vadd);
        _add(begin, end, pos * 2 + 1, (l + r) / 2, r, vadd);
        _merge(pos);
    }
    // Add `vadd` to (x_begin, ..., x_{end - 1})
    void add(int begin, int end, Tp vadd) noexcept { return _add(begin, end, 1, 0, head, vadd); }
    Tp _get(int begin, int end, int pos, int l, int r) const noexcept {
        if (r <= begin or end <= l) return defaultMin;
        if (begin <= l and r <= end) return range_min[pos] + range_add[pos];
        return f(_get(begin, end, pos * 2, l, (l + r) / 2), _get(begin, end, pos * 2 + 1, (l + r) / 2, r)) + range_add[pos];
    }
    // Return f(x_begin, ..., x_{end - 1})
    Tp get(int begin, int end) const noexcept { return _get(begin, end, 1, 0, head); }
};

int main()
{
    int N;
    cin >> N;
    if (N == 1) {
        cout << "0\n1\n";
        return 0;
    }

    vector<vector<pint>> to(N);
    CentroidDecomposition tree(N);
    REP(_, N - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        to[u].emplace_back(v, w);
        to[v].emplace_back(u, w);
        tree.add_edge(u, v);
    }

    tree.fix_root(0);
    const auto [c, s_] = tree.detect_centroids(0);

    map<int, vector<int>> mp;

    lint retw = 0;
    auto dfs = [&](auto &&dfs, int now, int prv, int rid) -> int {
        mp[rid].emplace_back(now);
        int stsz = 1;
        for (auto [nxt, w] : to[now]) if (nxt != prv) {
            int tsz = dfs(dfs, nxt, now, rid);
            retw += lint(w) * min(tsz, N - tsz) * 2;
            stsz += tsz;
        }
        return stsz;
    };

    vector<int> ret(N, -1);

    auto finish_ = [&]() -> void {
        cout << retw << '\n';
        for (auto x : ret) cout << x + 1 << ' ';
        cout << '\n';
        exit(0);
    };

    auto assign_bipartite = [&](vector<int> v1, vector<int> v2) {
        assert(v1.size() == v2.size());
        sort(ALL(v1));
        sort(ALL(v2));
        REP(j, v1.size()) ret[v1[j]] = v2[j];
    };

    vector<set<int>> vv;
    vector<int> belong(N);

    for (auto [nxt, w] : to[c]) {
        const int sztmp = dfs(dfs, nxt, c, nxt);
        retw += lint(w) * min(sztmp, N - sztmp) * 2;
        vv.push_back({});
        for (auto x : mp[nxt]) {
            vv.back().insert(x), belong[x] = int(vv.size()) - 1;
        }
    }
    vv.push_back({c});
    belong[c] = int(vv.size()) - 1;

    dbg(vv);
    dbg(belong);

    const int R = vv.size();
    vector<int> szl(R);
    REP(r, R) szl[r] = vv[r].size();

    REP(r, R) {
        if (szl[r] * 2 == N) {
            vector<int> v1, v2;
            REP(i, N) (vv[r].count(i) ? v1 : v2).emplace_back(i);
            assign_bipartite(v1, v2);
            assign_bipartite(v2, v1);
            finish_();
        }
    }
    vector<pint> yo(R);
    REP(r, R) yo[r] = pint(N - szl[r] * 2, r);
    yo.back().first++;
    dbg(szl);
    dbg(yo);
    RangeAddRangeMin<pint> segtreel(yo, pint(1e9, 0));

    set<int> mins;
    REP(r, vv.size()) mins.emplace(*vv[r].begin());

    REP(i, N) {
        pint tmp = min(segtreel.get(0, belong[i]), segtreel.get(belong[i] + 1, R));
        if (tmp.first == 0) {
            const int r = tmp.second;
            vector<int> v1, v2;
            FOR(j, i, N) if (belong[j] == r) v1.emplace_back(j);
            REP(rr, vv.size()) if (rr != r) for (auto x : vv[rr]) v2.emplace_back(x);
            assign_bipartite(v1, v2);
            v1.clear(), v2.clear();
            FOR(j, i, N) if (belong[j] != r) v1.emplace_back(j);
            for (auto x : vv[r]) v2.emplace_back(x);
            assign_bipartite(v1, v2);
            finish_();
        }
        const int r = belong[i];

        auto itr = mins.begin();
        if (belong[*itr] == r and mins.size() > 1 and i != c) itr++;
        const int j = *itr, rj = belong[j];

        ret[i] = j;
        segtreel.add(0, R, pint(-1, 0));
        segtreel.add(r, r + 1, pint(1, 0));
        if (j != c) segtreel.add(rj, rj + 1, pint(1, 0));
        mins.erase(itr);
        assert(vv[rj].count(j));
        vv[rj].erase(j);
        if (vv[rj].size()) mins.insert(*vv[rj].begin());
    }
    finish_();
}