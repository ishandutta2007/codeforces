#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template <typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template <typename V, typename T> void ndfill(V &x, const T &val) { x = val; }
template <typename V, typename T> void ndfill(vector<V> &vec, const T &val) { for (auto &v : vec) ndfill(v, val); }
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
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

struct GridUnionFind
{
    int H, W;
    std::vector<int> par, cou;
    using P = std::pair<int, int>;
    GridUnionFind(int H_, int W_) : H(H_), W(W_), par(H * W), cou(H * W, 1) { std::iota(par.begin(), par.end(), 0); }
    inline int id_(int h, int w) { return h * W + w; }
    inline bool coordinate_valid(int h, int w) { return h >= 0 and h < H and w >= 0 and w < W; }
    int _find(int x) { return (par[x] == x) ? x : (par[x] = _find(par[x])); }
    bool _unite(int x, int y) {
        x = _find(x), y = _find(y); if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int find(int h, int w) {
        assert(coordinate_valid(h, w));
        return _find(id_(h, w));
    }
    bool unite(int h, int w, int h2, int w2) {
        assert(coordinate_valid(h, w) and coordinate_valid(h2, w2));
        return _unite(id_(h, w), id_(h2, w2));
    }
    int count(int h, int w) { return cou[find(h, w)]; }
    bool same(int h, int w, int h2, int w2) { return find(h, w) == find(h2, w2); }

    int find(P p) { return find(p.first, p.second); }
    bool unite(P p, P p2) { return unite(p.first, p.second, p2.first, p2.second);  }
    int count(P p) { return count(p.first, p.second); }
    bool same(P p, P p2) { return same(p.first, p.second, p2.first, p2.second); }

    void merge_outer() {
        for (int h = 0; h < H - 1; h++) unite(h, 0, h + 1, 0), unite(h, W - 1, h + 1, W - 1);
        for (int w = 0; w < W - 1; w++) unite(0, w, 0, w + 1), unite(H - 1, w, H - 1, w + 1);
    }
    friend std::ostream &operator<<(std::ostream &os, GridUnionFind &g)
    {
        constexpr int WW = 3;
        os << "[(" << g.H << " * " << g.W << " grid)\n";
        for (int i = 0; i < g.H; i++) {
            for (int j = 0; j < g.W - 1; j++) {
                os << std::setw(WW) << g.find(i, j) << (g.same(i, j, i, j + 1) ? '-' : ' ');
            }
            os << std::setw(WW) << g.find(i, g.W - 1) << '\n';
            if (i < g.H - 1) {
                for (int j = 0; j < g.W; j++) os << std::setw(WW + 1) << (g.same(i, j, i + 1, j) ? "| " : "  ");
                os << "\n";
            }
        }
        os << "]\n";
        return os;
    }
};

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>
// MaxFlow based and AtCoder Library, single class, no namespace, no private variables, compatible with C++11
// Document: <https://atcoder.github.io/ac-library/production/document_ja/maxflow.html>
template <class Cap>
struct mf_graph {
    struct simple_queue_int {
        std::vector<int> payload;
        int pos = 0;
        void reserve(int n) { payload.reserve(n); }
        int size() const { return int(payload.size()) - pos; }
        bool empty() const { return pos == int(payload.size()); }
        void push(const int &t) { payload.push_back(t); }
        int &front() { return payload[pos]; }
        void clear() {
            payload.clear();
            pos = 0;
        }
        void pop() { pos++; }
    };

    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto &_e = g[pos[i].first][pos[i].second];
        auto &_re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    std::vector<int> level, iter;
    simple_queue_int que;

    void _bfs(int s, int t) {
        std::fill(level.begin(), level.end(), -1);
        level[s] = 0;
        que.clear();
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto e : g[v]) {
                if (e.cap == 0 || level[e.to] >= 0) continue;
                level[e.to] = level[v] + 1;
                if (e.to == t) return;
                que.push(e.to);
            }
        }
    }
    Cap _dfs(int v, int s, Cap up) {
        if (v == s) return up;
        Cap res = 0;
        int level_v = level[v];
        for (int &i = iter[v]; i < int(g[v].size()); i++) {
            _edge &e = g[v][i];
            if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
            Cap d = _dfs(e.to, s, std::min(up - res, g[e.to][e.rev].cap));
            if (d <= 0) continue;
            g[v][i].cap += d;
            g[e.to][e.rev].cap -= d;
            res += d;
            if (res == up) break;
        }
        return res;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        level.assign(_n, 0), iter.assign(_n, 0);
        que.clear();

        Cap flow = 0;
        while (flow < flow_limit) {
            _bfs(s, t);
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                Cap f = _dfs(t, s, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        simple_queue_int que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

// MaxFlow with lower bound
// <https://snuke.hatenablog.com/entry/2016/07/10/043918>
// <https://ei1333.github.io/library/graph/flow/maxflow-lower-bound.cpp>
// flush(s, t): Calculate maxflow (if solution exists), -1 (otherwise)
template <typename Cap>
struct MaxFlowLowerBound {
    int N;
    mf_graph<Cap> mf;
    std::vector<Cap> in;
    MaxFlowLowerBound(int N = 0) : N(N), mf(N + 2), in(N) {}
    int add_edge(int from, int to, Cap cap_lo, Cap cap_hi)
    {
        assert(0 <= from and from < N);
        assert(0 <= to and to < N);
        assert(0 <= cap_lo and cap_lo <= cap_hi);
        in[from] -= cap_lo;
        in[to] += cap_lo;
        return mf.add_edge(from, to, cap_hi - cap_lo);
    }
    Cap flow(int s, int t) {
        assert(s != t);
        assert(0 <= s and s < N);
        assert(0 <= t and t < N);
        Cap sum = 0;
        for (int i = 0; i < N; i++) {
            if (in[i] > 0) mf.add_edge(N, i, in[i]), sum += in[i];
            if (in[i] < 0) mf.add_edge(i, N + 1, -in[i]);
        }
        auto erev = mf.add_edge(t, s, numeric_limits<Cap>::max());
        if (mf.flow(N, N + 1) < sum) return -1;
        return mf.get_edge(erev).flow + mf.flow(s, t);
    }
};

array<int, 4> dx{1, -1, 0, 0};
array<int, 4> dy{0, 0, 1, -1};

char dir(int x, int y, int nx, int ny)
{
    string ret = "DURL";
    REP(d, 4)
    {
        if (x + dx[d] == nx and y + dy[d] == ny)
        {
            return ret[d];
        }
    }
    return '-';
}
void solve()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    cin >> A;
    vector<int> vals;
    for (auto v : A) for (auto x : v) vals.emplace_back(x);
    vals = srtunq(vals);
    vector<vector<pint>> v2ij(vals.size());
    REP(i, H) REP(j, W) v2ij[lower_bound(ALL(vals), A[i][j]) - vals.begin()].emplace_back(i, j);
    vector<vector<int>> ret(H, vector<int>(W, 1e9 + 20));
    vector<string> cret(H, string(W, '-'));

    vector<vector<int>> ids(H, vector<int>(W));
    REP(t, v2ij.size()) if (v2ij[t].size())
    {
        const int T = vals[t];
        const vector<pint> &vs = v2ij[t];
        dbg(vs);
        REP(i, vs.size())
        {
            auto [x, y] = vs[i];
            ids[x][y] = i;
        }
        MaxFlowLowerBound<int> mf(vs.size() + 2);
        REP(i, vs.size())
        {
            auto [x, y] = vs[i];
            bool flg = false;
            bool parity = (x + y) % 2;
            if (parity) mf.add_edge(vs.size(), i, 1, 1);
            else mf.add_edge(i, vs.size() + 1, 1, 1);
            REP(d, 4)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 and ny >= 0 and nx < H and ny < W)
                {
                    int j = ids[nx][ny];
                    if (A[x][y] == A[nx][ny] and parity) mf.add_edge(i, j, 0, 1);
                    if (A[x][y] > A[nx][ny] and !flg) {
                        flg = true;
                        if (parity) mf.add_edge(i, vs.size() + 1, 0, 1);
                        else mf.add_edge(vs.size(), i, 0, 1);
                    }
                }
            }
        }
        int flow = mf.flow(vs.size(), vs.size() + 1);
        if (flow < 0)
        {
            cout << "NO\n";
            return;
        }
        // dbg(flow);
        REP(i, vs.size())
        {
            auto [x, y] = vs[i];
            bool parity = (x + y) % 2;
            for (auto &e : mf.mf.g[i]) {
                int j = e.to;
                if (parity and j < vs.size() and e.cap == 0) {
                    auto [nx, ny] = vs[j];
                    ret[x][y] = T - 1;
                    ret[nx][ny] = 1;
                    cret[x][y] = dir(x, y, nx, ny);
                    cret[nx][ny] = dir(nx, ny, x, y);
                }
                else if ((parity and e.to == vs.size() + 1 and e.cap == 0) or (!parity and e.to == vs.size() and e.cap == 1)) {
                    REP(d, 4)
                    {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if (nx >= 0 and ny >= 0 and nx < H and ny < W)
                        {
                            if (A[x][y] > A[nx][ny])
                            {
                                ret[x][y] = T - A[nx][ny];
                                cret[x][y] = dir(x, y, nx, ny);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "YES\n";
    REP(i, H)
    {
        REP(j, W) cout << ret[i][j] << ' ';
        cout << '\n';
    }
    REP(i, H)
    {
        REP(j, W) cout << cret[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}