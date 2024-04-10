#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
    fast_ios() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); };
} fast_ios_;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
//
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args>
void ndarray(vector<T>& vec, const V& val, int len, Args... args)
{
    vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); });
}
template <typename T>
bool chmax(T& m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T>
bool chmin(T& m, const T q) { return m > q ? (m = q, true) : false; }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T>
vector<T> srtunq(vector<T> vec) { return sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()), vec; }
template <typename T>
istream& operator>>(istream& is, vector<T>& vec)
{
    return for_each(begin(vec), end(vec), [&](T& v) { is >> v; }), is;
}

// output
template <typename T, typename V>
ostream& dmpseq(ostream&, const T&, const string&, const string&, const string&);
#if __cplusplus >= 201703L
template <typename... T>
ostream& operator<<(ostream& os, const tuple<T...>& tpl)
{
    return apply([&os](auto&&... args) { ((os << args << ','), ...); }, tpl), os;
}
#endif
//
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << '(' << p.first << ',' << p.second << ')'; }
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& x) { return dmpseq<vector<T>, T>(os, x, "[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& x) { return dmpseq<deque<T>, T>(os, x, "deq[", ",", "]"); }
template <typename T>
ostream& operator<<(ostream& os, const set<T>& x) { return dmpseq<set<T>, T>(os, x, "{", ",", "}"); }
template <typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_set<T, TH>& x) { return dmpseq<unordered_set<T, TH>, T>(os, x, "{", ",", "}"); }
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& x) { return dmpseq<multiset<T>, T>(os, x, "{", ",", "}"); }
template <typename TK, typename T>
ostream& operator<<(ostream& os, const map<TK, T>& x) { return dmpseq<map<TK, T>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename TK, typename T, typename TH>
ostream& operator<<(ostream& os, const unordered_map<TK, T, TH>& x) { return dmpseq<unordered_map<TK, T, TH>, pair<TK, T>>(os, x, "{", ",", "}"); }
template <typename T, typename V>
ostream& dmpseq(ostream& os, const T& seq, const string& pre, const string& sp, const string& suf)
{
    return os << pre, for_each(begin(seq), end(seq), [&](V x) { os << x << sp; }), os << suf;
}
template <typename T>
void print(const vector<T>& x) { dmpseq<vector<T>, T>(cout, x, "", " ", "\n"); }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

// Bipartite matching of undirected bipartite graph (Hopcroft-Karp)
// <https://ei1333.github.io/luzhiled/snippets/graph/hopcroft-karp.html>
// Comprexity: O(EsqrtV)
// int solve(): enumerate maximum number of matching / return -1 (if graph is not bipartite)
struct BipartiteMatching
{
    int V;
    std::vector<std::vector<int>> to; // Adjacency list
    std::vector<int> dist;            // dist[i] = (Distance from i'th node)
    std::vector<int> match;           // match[i] = (Partner of i'th node) or -1 (No parter)
    std::vector<int> used, vv;        //
    std::vector<int> color;           // color of each node(checking bipartition): 0/1/-1(not determined)

    BipartiteMatching() = default;
    BipartiteMatching(int V_) : V(V_), to(V_), match(V_, -1), used(V_), color(V_, -1) {}

    void add_edge(int u, int v)
    {
        assert(u >= 0 and u < V and v >= 0 and v < V and u != v);
        to[u].push_back(v);
        to[v].push_back(u);
    }

    void bfs()
    {
        dist.assign(V, -1);
        std::queue<int> q;
        for (int i = 0; i < V; i++) {
            if (!color[i] and !used[i]) {
                q.emplace(i), dist[i] = 0;
            }
        }

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto nxt : to[now]) {
                int c = match[nxt];
                if (c >= 0 and dist[c] == -1) {
                    q.emplace(c), dist[c] = dist[now] + 1;
                }
            }
        }
    }

    bool dfs(int now)
    {
        vv[now] = true;
        for (auto nxt : to[now]) {
            int c = match[nxt];
            if (c < 0 or (!vv[c] and dist[c] == dist[now] + 1 and dfs(c))) {
                match[nxt] = now, match[now] = nxt;
                used[now] = true;
                return true;
            }
        }
        return false;
    }

    bool _color_bfs(int root)
    {
        color[root] = 0;
        std::queue<int> q;
        q.emplace(root);
        while (!q.empty()) {
            int now = q.front(), c = color[now];
            q.pop();
            for (auto nxt : to[now])
            if (color[nxt] == -1) color[nxt] = !c, q.emplace(nxt);
            else if (color[nxt] == c) return false;
        }
        return true;
    }

    int solve()
    {
        for (int i = 0; i < V; i++) if (color[i] == -1) {
            if (!_color_bfs(i)) return -1;
        }
        int ret = 0;
        while (true) {
            bfs();
            vv.assign(V, false);
            int flow = 0;
            for (int i = 0; i < V; i++) if (!color[i] and !used[i] and dfs(i)) flow++;
            if (!flow) break;
            ret += flow;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const BipartiteMatching &bm)
    {
        os << "{N=" << bm.V  << ':';
        for (int i = 0; i < bm.V; i++) if (bm.match[i] > i)
        {
            os << '(' << i << '-' << bm.match[i] << "),";
        }
        os << '}';
        return os;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<pint, int>> ij2d;
    REP(_, M)
    {
        int i, j, d;
        cin >> i >> j >> d;
        ij2d.emplace_back(pint(i - 1, j - 1), d);
    }

    constexpr int INF = 1e9 + 10;
    int lo = 0, hi = INF;
    while (hi - lo > 1) {
        int c = (lo + hi) / 2;
        int cnt = 0;
        BipartiteMatching bm(N * 2);
        for (auto [p, t] : ij2d) if (t <= c) {
            cnt++;
            bm.add_edge(p.first, p.second + N);
            }
        if (cnt < N or bm.solve() < N) lo = c;
        else hi = c;
    }
    cout << (hi == INF ? -1 : hi) << '\n';
}