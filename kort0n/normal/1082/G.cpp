#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
template< typename flow>
struct max_flow {
    struct edge {
        int to;
        flow cap;
        int rev; };
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;

    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(int from, int to, flow cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    flow dfs(int v, int t, flow f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                flow d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow run(int s, int t) {
        flow ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V,0);
            while ((f = dfs(s, t, INF)) > 0) ret += f;
        }
        return ret;
    }
};


int main() {
    //cout.precision(10);
    max_flow<ll> field(2005);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        field.add_edge(i, 2000, a * 2);
    }
    ll Default = 0;
    for(int i = 1; i <= m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        Default += 2 * w;
        field.add_edge(0, u, w);
        field.add_edge(0, v, w);
        field.add_edge(u, v, w);
        field.add_edge(v, u, w);
    }
    //cout << Default << " " << field.run(0, 2000) << endl;
    cout << (Default - field.run(0, 2000)) / 2 << endl;
    return 0;
}