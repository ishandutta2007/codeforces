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

template< typename flow_t, typename cost_t >
struct PrimalDual {
    const cost_t INF = 1e17;

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

string ans[55];
ll N, M;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans[i].push_back('0');
        }
    }
    while(M--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        ans[x][y] = '1';
    }
    PrimalDual<ll, ll> graph(2502);
    int S = 2500;
    int T = 2501;
    int num = 0;
    int MaxNum = N * (N - 1) / 2;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            graph.add_edge(S, num, 1, 0);
            if(ans[i][j] != '1') {
                graph.add_edge(num, MaxNum + j, 1, 0);
            }
            if(ans[j][i] != '1') {
                graph.add_edge(num, MaxNum + i, 1, 0);
            }
            num++;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            graph.add_edge(MaxNum + i, T, 1, 2 * j + 1);
        }
    }
    cerr << graph.min_cost_flow(S, T, MaxNum) << endl;
    num = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            for(auto e : graph.graph[num]) {
                if(e.isrev) continue;
                int from = e.to - MaxNum;
                int to;
                if(from == i) to = j;
                else to = i;
                //cerr << from << " " << to << " " << e.cap << endl;
                if(e.cap == 0) {
                    ans[from][to] = '1';
                }
            }
            num++;
        }
    }
    for(int i = 0; i < N; i++) cout << ans[i] << endl;
    return 0;
}