#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
const int INF = 1e9;
#define PI (acos(-1))
//const ll mod = 1000000007;
template< typename flow_t, typename cost_t >
struct PrimalDual {
    const cost_t INF;

    struct edge {
        int to;
        flow_t cap;
        cost_t cost;
        int rev;
        bool isrev;
    };
    vector< vector< edge > > graph;
    vector< cost_t > potential, min_cost;
    vector< int > prevv, preve;

    PrimalDual(int V) : graph(V), INF(numeric_limits< cost_t >::max()) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost) {
        graph[from].emplace_back((edge) {to, cap, cost, (int) graph[to].size(), false});
        graph[to].emplace_back((edge) {from, 0, -cost, (int) graph[from].size() - 1, true});
    }

    cost_t min_cost_flow(int s, int t, flow_t f) {
        int V = (int) graph.size();
        cost_t ret = 0;
        using Pi = pair< cost_t, int >;
        priority_queue< Pi, vector< Pi >, greater< Pi > > que;
        potential.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);

        while(f > 0) {
            min_cost.assign(V, INF);
            que.emplace(0, s);
            min_cost[s] = 0;
            while(!que.empty()) {
                Pi p = que.top();
                que.pop();
                if(min_cost[p.second] < p.first) continue;
                for(int i = 0; i < graph[p.second].size(); i++) {
                    edge &e = graph[p.second][i];
                    cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
                    if(e.cap > 0 && min_cost[e.to] > nextCost) {
                        min_cost[e.to] = nextCost;
                        prevv[e.to] = p.second, preve[e.to] = i;
                        que.emplace(min_cost[e.to], e.to);
                    }
                }
            }
            if(min_cost[t] == INF) return -1;
            for(int v = 0; v < V; v++) potential[v] += min_cost[v];
            flow_t addflow = f;
            for(int v = t; v != s; v = prevv[v]) {
                addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for(int v = t; v != s; v = prevv[v]) {
                edge &e = graph[prevv[v]][preve[v]];
                e.cap -= addflow;
                graph[v][e.rev].cap += addflow;
            }
       }
       return ret;
    }

    void output() {
        for(int i = 0; i < graph.size(); i++) {
            for(auto &e : graph[i]) {
                if(e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
            }
        }
    }
};

int n, m, k, c, d;
int a[55];
int x[55], y[55];
int start = 0;
int MaxDays = 500;
///int MaxDays = 5;
int target = (MaxDays + 2) * 50;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    PrimalDual<int, ll> graph(target + 1);
    cin >> n >> m >> k >> c >> d;
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
        graph.add_edge(start, a[i], 1, 0);
    }
    for(int i = 1; i <= m; i++) cin >> x[i] >> y[i];
    for(int day = 0; day < MaxDays; day++) {
        graph.add_edge(day * 50 + 1, target, k, 0);
        for(int city = 2; city <= n; city++) {
            graph.add_edge(day * 50 + city, (day + 1) * 50 + city, k, c);
        }
        for(int street = 1; street <= m; street++) {
            for(int num = 1; num <= k; num++) {
                graph.add_edge(day * 50 + x[street], (day + 1) * 50 + y[street], 1, d * (num * 2 - 1) + c);
                graph.add_edge(day * 50 + y[street], (day + 1) * 50 + x[street], 1, d * (num * 2 - 1) + c);
            }
        }
    }
    cout << graph.min_cost_flow(start, target, k) << endl;
    //graph.output();
    return 0;
}