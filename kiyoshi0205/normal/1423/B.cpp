#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define DEBUG
#ifdef DEBUG
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '{';
    for(int i = 0; i < (int)v.size(); i++) {
        if(i) {
            os << ',';
        }
        os << v[i];
    }
    os << '}';
    return os;
}
void debugg() { cerr << endl; }
template <class T, class... Args>
void debugg(const T &x, const Args &... args) {
    cerr << " " << x;
    debugg(args...);
}
#define debug(...)                                                             \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debugg(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    }
} __Setup;

using ll = long long;
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#include <algorithm>

#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T &t) { payload.push_back(t); }
    T &front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

} // namespace internal

} // namespace atcoder

#include <cassert>
#include <limits>
#include <queue>
#include <vector>

namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        g[from].push_back(_edge{to, int(g[to].size()), cap});
        g[to].push_back(_edge{from, int(g[from].size()) - 1, 0});
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
        for(int i = 0; i < m; i++) {
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

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while(!que.empty()) {
                int v = que.front();
                que.pop();
                for(auto e : g[v]) {
                    if(e.cap == 0 || level[e.to] >= 0)
                        continue;
                    level[e.to] = level[v] + 1;
                    if(e.to == t)
                        return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if(v == s)
                return up;
            Cap res = 0;
            int level_v = level[v];
            for(int &i = iter[v]; i < int(g[v].size()); i++) {
                _edge &e = g[v][i];
                if(level_v <= level[e.to] || g[e.to][e.rev].cap == 0)
                    continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if(d <= 0)
                    continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if(res == up)
                    break;
            }
            return res;
        };

        Cap flow = 0;
        while(flow < flow_limit) {
            bfs();
            if(level[t] == -1)
                break;
            std::fill(iter.begin(), iter.end(), 0);
            while(flow < flow_limit) {
                Cap f = dfs(dfs, t, flow_limit - flow);
                if(!f)
                    break;
                flow += f;
            }
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for(auto e : g[p]) {
                if(e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

} // namespace atcoder

using namespace atcoder;

//-------------------------------------

struct edge {
    int from, to, day;
    edge() = default;
    edge(int from, int to, int day) : from(from), to(to), day(day) {}
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<edge> es(M);
    for(int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        es[i] = edge(u - 1, v + N - 1, d);
    }
    sort(ALL(es), [](const edge &a, const edge &b) { return (a.day < b.day); });

    auto f = [&](int x) {
        mf_graph<int> mf(2 * N + 2);
        int s = 2 * N;
        int t = s + 1;
        vector<bool> used(2 * N, 0);
        for(int i = 0; i < M; i++) {
            if(es[i].day > x) {
                break;
            }
            mf.add_edge(es[i].from, es[i].to, 1);
            if(!used[es[i].from]) {
                mf.add_edge(s, es[i].from, 1);
                used[es[i].from] = true;
            }
            if(!used[es[i].to]) {
                mf.add_edge(es[i].to, t, 1);
                used[es[i].to] = true;
            }
        }
        auto ans = mf.flow(s, t);
        return (ans == N);
    };

    int ok = es.back().day + 1, ng = 0;
    while(ok - ng > 1) {
        int mid = (ok + ng) >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    cout << (ok >= es.back().day + 1 ? -1 : ok) << "\n";
}