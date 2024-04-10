#include <bits/stdc++.h>

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
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder

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
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
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
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                Cap f = dfs(dfs, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
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

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder


constexpr int Inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<std::pair<int, int>>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }
    
    std::vector<int> id(n);
    
    int lg = std::__lg(n);
    std::vector<int> dep(n);
    std::vector<std::vector<int>> p(n, std::vector<int>(lg + 1, -1));
    std::function<void(int)> dfs = [&](int u) {
        for (int i = 1; (1 << i) <= dep[u]; ++i) {
            p[u][i] = p[p[u][i - 1]][i - 1];
        }
        for (auto [v, i] : e[u]) {
            if (v == p[u][0]) {
                continue;
            }
            dep[v] = dep[u] + 1;
            id[v] = i;
            p[v][0] = u;
            dfs(v);
        }
    };
    dfs(0);
    
    atcoder::mf_graph<int> g(n * (lg + 1) + m + 100000);
    
    const int S = 0, T = n;
    const int pBegin = n * (lg + 1);
    
    for (int i = 1; i < n; ++i) {
        g.add_edge(i, T, 1);
        for (int j = 1; (1 << j) <= dep[i]; ++j) {
            g.add_edge(j * n + i, (j - 1) * n + i, Inf);
            g.add_edge(j * n + i, (j - 1) * n + p[i][j - 1], Inf);
        }
    }
    
    auto addEdge = [&](int x, int y, int u) {
        g.add_edge(S, u, 1);
        if (dep[x] < dep[y]) {
            std::swap(x, y);
        }
        for (int i = lg; i >= 0; --i) {
            if (dep[x] - (1 << i) >= dep[y]) {
                g.add_edge(u, i * n + x, Inf);
                x = p[x][i];
            }
        }
        if (x == y) {
            return;
        }
        for (int i = lg; i >= 0; --i) {
            if (p[x][i] != p[y][i]) {
                g.add_edge(u, i * n + x, Inf);
                g.add_edge(u, i * n + y, Inf);
                x = p[x][i];
                y = p[y][i];
            }
        }
        g.add_edge(u, x, Inf);
        g.add_edge(u, y, Inf);
    };
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        addEdge(x, y, pBegin + i);
    }
    
    std::cout << g.flow(S, T) << "\n";
    auto c = g.min_cut(S);
    
    std::vector<int> ps, es;
    for (int i = 1; i < n; ++i) {
        if (c[i]) {
            es.push_back(id[i]);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (!c[pBegin + i]) {
            ps.push_back(i);
        }
    }
    std::cout << ps.size();
    for (auto x : ps) {
        std::cout << " " << x + 1;
    }
    std::cout << "\n";
    std::cout << es.size();
    for (auto x : es) {
        std::cout << " " << x + 1;
    }
    std::cout << "\n";
    
    return 0;
}