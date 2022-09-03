#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

/*
MinCostFlow: Minimum-cost flow problem solver WITH NO NEGATIVE CYCLE
Verified by SRM 770 Div1 Medium <https://community.topcoder.com/stat?c=problem_statement&pm=15702>
*/
struct MinCostFlow
{
    using TFLOW = long long int;
    using TCOST = long long int;
    const TCOST INF_COST = 1e16;
    struct edge {
        int to, rev;
        TFLOW cap;
        TCOST cost;
        int eid;
        friend ostream &operator<<(ostream &os, const edge &e) {
            os << "(" << e.to << "," << e.rev << "," << e.cap << "," << e.cost << ")";
            return os;
        }
    };
    int V;
    vector<vector<edge>> G;
    vector<TCOST> dist;
    vector<int> prevv, preve;
    vector<TCOST> h;  // h[V]: potential

    bool _calc_distance_bellman_ford(int s) {  // O(VE), able to detect negative cycle
        dist.assign(V, INF_COST);
        dist[s] = 0;
        bool upd = true;
        int cnt = 0;
        while (upd) {
            upd = false;
            cnt++;
            if (cnt > V) return false;  // Negative cycle existence
            for (int v = 0; v < V; v++) if (dist[v] != INF_COST) {
                for (int i = 0; i < (int)G[v].size(); i++) {
                    edge &e = G[v][i];
                    TCOST c = dist[v] + e.cost + h[v] - h[e.to];
                    if (e.cap > 0 and dist[e.to] > c) {
                        dist[e.to] = c, prevv[e.to] = v, preve[e.to] = i;
                        upd = true;
                    }
                }
            }
        }
        return true;
    }

    bool _calc_distance_dijkstra(int s) {  // O(ElogV)
        dist.assign(V, INF_COST);
        dist[s] = 0;
        using P = pair<TCOST, int>;
        priority_queue<P, vector<P>, greater<P>> q;
        q.emplace(0, s);
        while (!q.empty()) {
            P p = q.top();
            q.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i = 0; i < (int)G[v].size(); i++) {
                edge &e = G[v][i];
                TCOST c = dist[v] + e.cost + h[v] - h[e.to];
                if (e.cap > 0 and dist[e.to] > c) {
                    dist[e.to] = c, prevv[e.to] = v, preve[e.to] = i;
                    q.emplace(dist[e.to], e.to);
                }
            }
        }
        return true;
    }

    MinCostFlow(int V=0) : V(V), G(V) {}

    void add_edge(int from, int to, TFLOW cap, TCOST cost, int eid=-1) {
        G[from].emplace_back(edge{to, (int)G[to].size(), cap, cost, eid});
        G[to].emplace_back(edge{from, (int)G[from].size() - 1, (TFLOW)0, -cost, eid});
    }

    pair<TCOST, pair<bool, TFLOW>> flush(int s, int t, TFLOW f) {
        /*
        Flush amount of `f` from `s` to `t` using the Dijkstra's algorithm
        works for graph with no negative cycles (negative cost edges are allowed)
        retval: (min_flow, ([succeeded or not], residue flow))
        [Example] Succeeded: `([mincost], (true, 0))`
        */
        TCOST ret = 0;
        h.assign(V, 0);
        prevv.assign(V, -1);
        preve.assign(V, -1);
        while (f > 0) {
            _calc_distance_dijkstra(s);
            if (dist[t] == INF_COST) return make_pair(ret, make_pair(false, f));
            for (int v = 0; v < V; v++) h[v] += dist[v];
            TFLOW d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            ret += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return make_pair(ret, make_pair(true, 0));
    }

    friend ostream &operator<<(ostream &os, const MinCostFlow &mcf) {
        os << "[MinCostFlow]V=" << mcf.V << ":";
        for (int i = 0; i < (int)mcf.G.size(); i++) for (auto &e : mcf.G[i]) {
            os << "\n" << i << "->" << e.to << ": cap=" << e.cap << ", cost=" << e.cost;
        }
        return os;
    }
};

int main()
{
    int N1, N2, M, R, B;
    cin >> N1 >> N2 >> M >> R >> B;
    string S1, S2;
    cin >> S1 >> S2;
    vector<pint> e(M);
    vector<int> c1(N1), c2(N2);
    REP(i, M) {
        cin >> e[i].first >> e[i].second;
        e[i].first--, e[i].second--;
        c1[e[i].first]++, c2[e[i].second]++;
    }
    int S = N1 + N2, T = S + 1;
    MinCostFlow f(T + 1);
    constexpr lint INF = 1e9;
    lint cost = 0;
    REP(i, N1) {
        if (S1[i] == 'R') f.add_edge(S, i, c1[i] - 1, 0);
        if (S1[i] == 'B') {
            f.add_edge(S, i, c1[i] + 1, -INF);
            cost += INF * (c1[i] + 1);
            f.add_edge(S, i, c1[i] - 1, 0);
        }
        if (S1[i] == 'U') f.add_edge(S, i, 2 * c1[i], 0);
    }
    REP(j, N2) {
        if (S2[j] == 'R') f.add_edge(N1 + j, T, c2[j] - 1, 0);
        if (S2[j] == 'B') {
            f.add_edge(N1 + j, T, c2[j] + 1, -INF);
            cost += INF * (c2[j] + 1);
            f.add_edge(N1 + j, T, c2[j] - 1, 0);
        }
        if (S2[j] == 'U') f.add_edge(N1 + j, T, 2 * c2[j], 0);
    }

    REP(i, M) {
        f.add_edge(e[i].first, N1 + e[i].second, 1, -R, i);
        f.add_edge(e[i].first, N1 + e[i].second, 1, B, i + M);
        cost += R;
    }

    f.add_edge(S, T, INF, 0);

    cost += f.flush(S, T, INF).first;

    if (cost >= INF) {
        puts("-1");
        return 0;
    }

    vector<int> state(M);
    REP(i, N1) for (auto e : f.G[i]) if (e.eid != -1 and e.cap == 0) {
        state[e.eid % M]++;
    }
    printf("%lld\n", cost);
    REP(i, M) {
        if (state[i] == 0) printf("R");
        if (state[i] == 1) printf("U");
        if (state[i] == 2) printf("B");
    }
    puts("");
}