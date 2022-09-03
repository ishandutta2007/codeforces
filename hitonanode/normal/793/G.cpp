#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

// MaxFlow based and AtCoder Library, single class, no namespace, no private variables, compatible with C++11
// Reference: <https://atcoder.github.io/ac-library/production/document_ja/maxflow.html>
template <class Cap> struct mf_graph {
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
        for (int i = 0; i < m; i++) { result.push_back(get_edge(i)); }
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
            if (res == up) return res;
        }
        level[v] = _n;
        return res;
    }

    Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
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
            Cap f = _dfs(t, s, flow_limit - flow);
            if (!f) break;
            flow += f;
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

// Enumerate nodes of nonrecursive segtree which cover [l, r)
std::vector<int> segtree_relevant_points(int N, int l, int r) {
    std::vector<int> ret;
    l += N, r += N;
    while (l < r) {
        if (l & 1) ret.push_back(l++);
        if (r & 1) ret.push_back(--r);
        l >>= 1, r >>= 1;
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    vector<vector<pair<bool, pint>>> x2yy(N + 1);

    map<int, pint> mp;
    mp[0] = pint(N, 0);
    x2yy[N].emplace_back(1, pint(0, N));

    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;
        x2yy[x1].emplace_back(1, pint(y1, y2)); // erase
        x2yy[x2].emplace_back(0, pint(y1, y2)); // add
    }
    for (auto &vec : x2yy) sort(vec.begin(), vec.end());

    vector<vector<int>> recs;
    auto add_rect = [&](const vector<int> &v) {
        if (v[0] < v[1]) recs.emplace_back(v);
    };

    REP(i, N + 1) {
        for (auto [m, p] : x2yy[i]) {
            if (m == 1) {
                auto itr = prev(mp.upper_bound(p.first));
                int l = itr->first, r = itr->second.first, j = itr->second.second;
                add_rect({j, i, l, r});
                mp.erase(l);
                if (l < p.first) mp[l] = pint(p.first, i);
                if (p.second < r) mp[p.second] = pint(r, i);
            } else {
                auto itr = mp.lower_bound(p.first);
                if (itr != mp.begin()) {
                    itr--;
                    if (itr->second.first == p.first) {
                        add_rect({itr->second.second, i, itr->first, itr->second.first});
                        p.first = itr->first;
                        mp.erase(itr->first);
                    }
                }
                itr = mp.lower_bound(p.first);
                if (itr != mp.end() and itr->first == p.second) {
                    add_rect({itr->second.second, i, itr->first, itr->second.first});
                    p.second = itr->second.first;
                    mp.erase(itr);
                }
                mp[p.first] = pint(p.second, i);
            }
        }
    }

    mf_graph<int> mf(4 * N + 2 + recs.size());
    const int s_mf = 4 * N, t_mf = s_mf + 1;
    REP(i, N) {
        mf.add_edge(s_mf, N + i, 1);
        mf.add_edge(N * 3 + i, t_mf, 1);
    }
    FOR(i, 1, N) {
        mf.add_edge(i * 2, i, N);
        mf.add_edge(i * 2 + 1, i, N);
        mf.add_edge(i + 2 * N, i * 2 + 2 * N, N);
        mf.add_edge(i + 2 * N, i * 2 + 1 + 2 * N, N);
    }

    REP(q, recs.size()) {
        const auto &rec = recs[q];
        for (auto i : segtree_relevant_points(N, rec[0], rec[1])) mf.add_edge(i, t_mf + 1 + q, N);
        for (auto i : segtree_relevant_points(N, rec[2], rec[3])) mf.add_edge(t_mf + 1 + q, i + 2 * N, N);
    }
    cout << mf.flow(s_mf, t_mf) << '\n';
}