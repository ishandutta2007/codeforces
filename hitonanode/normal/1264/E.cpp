#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

// MinCostFlow based on AtCoder Library
// Reference: <https://atcoder.github.io/ac-library/production/document_ja/mincostflow.html>
template <class Cap, class Cost>
struct mcf_graph {
    mcf_graph() {}
    mcf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap, cost});
        g[to].push_back(_edge{from, from_id, 0, -cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{
            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
        };
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = get_edge(i);
        }
        return result;
    }

    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }

    std::vector<Cost> dual, dist;
    std::vector<int> pv, pe;
    std::vector<bool> vis;
    bool _dual_ref(int s, int t) {
        std::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());
        std::fill(pv.begin(), pv.end(), -1);
        std::fill(pe.begin(), pe.end(), -1);
        std::fill(vis.begin(), vis.end(), false);
        struct Q {
            Cost key;
            int to;
            bool operator<(Q r) const { return key > r.key; }
        };
        std::priority_queue<Q> que;
        dist[s] = 0;
        que.push(Q{0, s});
        while (!que.empty()) {
            int v = que.top().to;
            que.pop();
            if (vis[v]) continue;
            vis[v] = true;
            if (v == t) break;
            // dist[v] = shortest(s, v) + dual[s] - dual[v]
            // dist[v] >= 0 (all reduced cost are positive)
            // dist[v] <= (n-1)C
            for (int i = 0; i < int(g[v].size()); i++) {
                auto e = g[v][i];
                if (vis[e.to] || !e.cap) continue;
                // |-dual[e.to] + dual[v]| <= (n-1)C
                // cost <= C - -(n-1)C + 0 = nC
                Cost cost = e.cost - dual[e.to] + dual[v];
                if (dist[e.to] - dist[v] > cost) {
                    dist[e.to] = dist[v] + cost;
                    pv[e.to] = v;
                    pe[e.to] = i;
                    que.push(Q{dist[e.to], e.to});
                }
            }
        }
        if (!vis[t]) {
            return false;
        }

        for (int v = 0; v < _n; v++) {
            if (!vis[v]) continue;
            // dual[v] = dual[v] - dist[t] + dist[v]
            //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, v) + dual[s] - dual[v])
            //         = - shortest(s, t) + dual[t] + shortest(s, v)
            //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C
            dual[v] -= dist[t] - dist[v];
        }
        return true;
    }

    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
        // variants (C = maxcost):
        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
        // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge
        dual.assign(_n, 0), dist.assign(_n, 0);
        pv.assign(_n, 0), pe.assign(_n, 0);
        vis.assign(_n, false);
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        std::vector<std::pair<Cap, Cost>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit) {
            if (!_dual_ref(s, t)) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v]) {
                c = std::min(c, g[pv[v]][pe[v]].cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                auto& e = g[pv[v]][pe[v]];
                e.cap -= c;
                g[v][e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }

    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    int _n;
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};
int main()
{
    int N, M;
    cin >> N >> M;
    int TM = N * (N - 1) / 2;
    int SZ = 1 + TM + N + 1;
    mcf_graph<int, int> mcf(SZ);
    REP(i, TM) mcf.add_edge(0, i + 1, 1, 0);
    vector<vector<int>> ret(N + 1, vector<int>(N + 1, -1));
    REP(i, N + 1) ret[i][i] = 0;
    while (M--) {
        int win, lose;
        cin >> win >> lose;
        ret[win][lose] = 1, ret[lose][win] = 0;
    }
    int m = 1;
    FOR(i, 1, N + 1) FOR(j, 1, i) {
        if (ret[i][j] > -1)
        {
            mcf.add_edge(m, TM + (ret[i][j] ? i : j), 1, 0);
        }
        else
        {
            mcf.add_edge(m, TM + i, 1, 0);
            mcf.add_edge(m, TM + j, 1, 0);
        }
        m++;
    }
    REP(_, N) {
        FOR(c, 1, N) mcf.add_edge(m, SZ - 1, 1, c);
        m++;
    }
    mcf.flow(0, SZ - 1, TM);
    FOR(i, 1, TM + 1) if (mcf.g[i].size() > 2)
    {
        int win = 0, lose = 0;
        for (auto s : mcf.g[i]) if (s.to != 0)
        {
            (s.cap ? lose : win) = s.to - TM;
        }
        ret[win][lose] = 1, ret[lose][win] = 0;
    }
    FOR(i, 1, N + 1) {
        FOR(j, 1, N + 1) printf("%d", ret[i][j]);
        puts("");
    }
}