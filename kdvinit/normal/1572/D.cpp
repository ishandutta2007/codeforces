/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

//#define int long
#define endl "\n"

//Works for both directed, undirected and with negative cost too
//doesn't work for negative cycles
//for undirected edges just make the directed flag false
//Complexity: O(min(E^2 *V log V, E logV * flow))
using T = int;
const T inf = 4e6;
struct MCMF {
  struct edge {
    int u, v;
    T cap, cost;
    int id;
    edge(int _u, int _v, T _cap, T _cost, int _id) {
      u = _u;
      v = _v;
      cap = _cap;
      cost = _cost;
      id = _id;
    }
  };
  int n, s, t, mxid;
  T flow, cost;
  vector<vector<int>> g;
  vector<edge> e;
  vector<T> d, potential, flow_through;
  vector<int> par;
  bool neg;
  MCMF() {}
  MCMF(int _n) { // 0-based indexing
    n = _n + 10;
    g.assign(n, vector<int> ());
    neg = false;
    mxid = 0;
  }
  void add_edge(int u, int v, T cap, T cost, int id = -1, bool directed = true) {
    if(cost < 0) neg = true;
    g[u].push_back(e.size());
    e.push_back(edge(u, v, cap, cost, id));
    g[v].push_back(e.size());
    e.push_back(edge(v, u, 0, -cost, -1));
    mxid = max(mxid, id);
    if(!directed) add_edge(v, u, cap, cost, -1, true);
  }
  bool dijkstra() {
    par.assign(n, -1);
    d.assign(n, inf);
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>> > q;
    d[s] = 0;
    q.push(pair<T, T>(0, s));
    while (!q.empty()) {
      int u = q.top().second;
      T nw = q.top().first;
      q.pop();
      if(nw != d[u]) continue;
      for (int i = 0; i < (int)g[u].size(); i++) {
        int id = g[u][i];
        int v = e[id].v;
        T cap = e[id].cap;
        T w = e[id].cost + potential[u] - potential[v];
        if (d[u] + w < d[v] && cap > 0) {
          d[v] = d[u] + w;
          par[v] = id;
          q.push(pair<T, T>(d[v], v));
        }
      }
    }
    for (int i = 0; i < n; i++) { // update potential
      if(d[i] < inf) potential[i] += d[i];
    }
    return d[t] != inf;
  }
  T send_flow(int v, T cur) {
    if(par[v] == -1) return cur;
    int id = par[v];
    int u = e[id].u;
    T w = e[id].cost;
    T f = send_flow(u, min(cur, e[id].cap));
    cost += f * w;
    e[id].cap -= f;
    e[id ^ 1].cap += f;
    return f;
  }
  //returns {maxflow, mincost}
  pair<T, T> solve(int _s, int _t, T goal = inf) {
    s = _s;
    t = _t;
    flow = 0, cost = 0;
    potential.assign(n, 0);
    if (neg) {
      // run Bellman-Ford to find starting potential
      d.assign(n, inf);
      for (int i = 0, relax = true; i < n && relax; i++) {
        for (int u = 0; u < n; u++) {
          for (int k = 0; k < (int)g[u].size(); k++) {
            int id = g[u][k];
            int v = e[id].v;
            T cap = e[id].cap, w = e[id].cost;
            if (d[v] > d[u] + w && cap > 0) {
              d[v] = d[u] + w;
              relax = true;
            }
          }
        }
      }
      for(int i = 0; i < n; i++) if(d[i] < inf) potential[i] = d[i];
    }
    while (flow < goal && dijkstra()) flow += send_flow(t, goal - flow);
    flow_through.assign(mxid + 10, 0);
    for (int u = 0; u < n; u++) {
      for (auto v : g[u]) {
        if (e[v].id >= 0) flow_through[e[v].id] = e[v ^ 1].cap;
      }
    }
    return make_pair(flow, cost);
  }
};

void solve()
{
    int n, k;
    cin>>n>>k;

    int mx = 1<<n; int a[mx];
    for(int i=0; i<mx; i++) cin>>a[i];

    int need = (2*n*k);
    priority_queue<array<int, 3>> pq;

    for(int i=0; i<mx; i++)
    {
        int y = __builtin_popcount(i);
        if(y%2) continue;
        for(int j=0; j<n; j++)
        {
            int i2 = i^(1<<j);
            pq.push({inf-(a[i]+a[i2]), i, i2});
            if(pq.size()>need) pq.pop();
        }
    }

    set<int> ver;
    vector<array<int, 3>> edges;

    while(!pq.empty())
    {
        auto x = pq.top(); pq.pop();
        int i = x[1]; int j = x[2];
        ver.insert(i); ver.insert(j);
        edges.push_back({i, j, x[0]});
    }

    map<int, int> mp;   int cnt=0;
    for(int x: ver) mp[x]=++cnt;

    MCMF F(cnt+10);
    int s = cnt+1, s1 = cnt+2;
    int t = cnt+3, t1 = cnt+4;

    F.add_edge(s, s1, k, 0);
    F.add_edge(t1, t, k, 0);

    for(int x: ver)
    {
        int y = __builtin_popcount(x);
        if(y%2) F.add_edge(mp[x], t1, 1, 0);
        else F.add_edge(s1, mp[x], 1, 0);
    }

    for(auto e: edges)
    {
        int i=e[0], j=e[1], w=e[2];
        F.add_edge(mp[i], mp[j], 1, w);
    }

    auto ans = F.solve(s, t);
    int val = ((ans.first)*inf) - (ans.second);
    cout<<val<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}