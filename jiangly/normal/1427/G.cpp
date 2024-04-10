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

using namespace atcoder;
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    std::vector<int> cand;
    std::vector<std::pair<int, int>> cells;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
            if (a[i][j] > 0) cand.push_back(a[i][j]);
            if (a[i][j] == 0) cells.emplace_back(i, j);
        }
    }
    std::sort(cand.begin(), cand.end());
    cand.erase(std::unique(cand.begin(), cand.end()), cand.end());
    std::vector<std::vector<int>> id(n, std::vector<int>(n, -1));
    auto solve = [&](auto solve, auto cells, int l, int r) {
        if (r - l == 1) {
            for (auto [x, y] : cells) a[x][y] = cand[l];
            return;
        }
        int m = (l + r) / 2;
        int cnt = cells.size();
        mf_graph<int> g(cnt + 2);
        for (int i = 0; i < cnt; ++i) {
            auto [x, y] = cells[i];
            id[x][y] = i;
        }
        for (auto [x, y] : cells) {
            int u = id[x][y];
            for (int k = 0; k < 4; ++k) {
                int x1 = x + dx[k];
                int y1 = y + dy[k];
                int v = id[x1][y1];
                if (v >= 0) {
                    g.add_edge(u, v, 1);
                } else if (a[x1][y1] != -1) {
                    if (a[x1][y1] < cand[m]) g.add_edge(cnt, u, 1);
                    else g.add_edge(u, cnt + 1, 1);
                }
            }
        }
        g.flow(cnt, cnt + 1);
        auto v = g.min_cut(cnt);
        std::vector<std::pair<int, int>> small, large;
        for (int i = 0; i < cnt; ++i) {
            auto [x, y] = cells[i];
            if (v[i]) a[x][y] = cand[m - 1], small.emplace_back(x, y);
            else a[x][y] = cand[m], large.emplace_back(x, y);
        }
        for (auto [x, y] : cells) id[x][y] = -1;
        solve(solve, small, l, m);
        solve(solve, large, m, r);
    };
    solve(solve, cells, 0, cand.size());
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + 1 < n && a[i][j] != -1 && a[i + 1][j] != -1) ans += std::abs(a[i][j] - a[i + 1][j]);
            if (j + 1 < n && a[i][j] != -1 && a[i][j + 1] != -1) ans += std::abs(a[i][j] - a[i][j + 1]);
        }
    }
    std::cout << ans << "\n";
    
    return 0;
}