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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        mf_graph<int> g(n * m + 3);
        std::vector<int> out(n * m + 1);
        int O = n * m, S = n * m + 1, T = n * m + 2;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            bool less = false;
            if (i > 0 && a[i - 1][j] <= a[i][j]) {
                if (a[i - 1][j] < a[i][j]) less = true;
                else if ((i + j) % 2 == 0) g.add_edge(i * m + j, (i - 1) * m + j, 1);
                else g.add_edge((i - 1) * m + j, i * m + j, 1);
            }
            if (i + 1 < n && a[i + 1][j] <= a[i][j]) {
                if (a[i + 1][j] < a[i][j]) less = true;
                else if ((i + j) % 2 == 0) g.add_edge(i * m + j, (i + 1) * m + j, 1);
                else g.add_edge((i + 1) * m + j, i * m + j, 1);
            }
            if (j > 0 && a[i][j - 1] <= a[i][j]) {
                if (a[i][j - 1] < a[i][j]) less = true;
                else if ((i + j) % 2 == 0) g.add_edge(i * m + j, i * m + j - 1, 1);
                else g.add_edge(i * m + j - 1, i * m + j, 1);
            }
            if (j + 1 < m && a[i][j + 1] <= a[i][j]) {
                if (a[i][j + 1] < a[i][j]) less = true;
                else if ((i + j) % 2 == 0) g.add_edge(i * m + j, i * m + j + 1, 1);
                else g.add_edge(i * m + j + 1, i * m + j, 1);
            }
            if (less) {
                if ((i + j) % 2 == 0) g.add_edge(O, i * m + j, 1);
                else g.add_edge(i * m + j, O, 1);
            } else {
                if ((i + j) % 2 == 0) ++out[O], --out[i * m + j];
                else --out[O], ++out[i * m + j];
            }
        }
        int sum = 0;
        for (int i = 0; i <= n * m; ++i) {
            if (out[i] > 0) sum += out[i], g.add_edge(i, T, out[i]);
            else g.add_edge(S, i, -out[i]);
        }
        if (g.flow(S, T) != sum) {
            std::cout << "NO\n";
            continue;
        }
        std::cout << "YES\n";
        std::vector<std::vector<char>> dir(n, std::vector<char>(m, '?'));
        std::vector<std::vector<int>> b(n, std::vector<int>(m));
        auto edges = g.edges();
        for (auto e : edges) {
            if (e.from >= n * m || e.to >= n * m) continue;
            if (e.flow == 0) continue;
            int x1 = e.from / m, y1 = e.from % m;
            int x2 = e.to / m, y2 = e.to % m;
            if (x1 > x2 || y1 > y2) std::swap(x1, x2), std::swap(y1, y2);
            b[x1][y1] = 1;
            b[x2][y2] = a[x1][y1] - 1;
            if (x1 == x2) {
                dir[x1][y1] = 'R';
                dir[x2][y2] = 'L';
            } else {
                dir[x1][y1] = 'D';
                dir[x2][y2] = 'U';
            }
        }
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            if (dir[i][j] != '?') continue;
            if (i > 0 && a[i - 1][j] < a[i][j]) dir[i][j] = 'U', b[i][j] = a[i][j] - a[i - 1][j];
            else if (i + 1 < n && a[i + 1][j] < a[i][j]) dir[i][j] = 'D', b[i][j] = a[i][j] - a[i + 1][j];
            else if (j > 0 && a[i][j - 1] < a[i][j]) dir[i][j] = 'L', b[i][j] = a[i][j] - a[i][j - 1];
            else dir[i][j] = 'R', b[i][j] = a[i][j] - a[i][j + 1];
        }
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) std::cout << b[i][j] << " \n"[j == m - 1];
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) std::cout << dir[i][j] << " \n"[j == m - 1];
    }
    
    return 0;
}