#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

int cnt = 0;
const int INF = 1 << 30;
struct graph {
  typedef long long flow_type;
  int flow_value;
  struct edge {
    int src, dst;
    flow_type capacity, flow;
    size_t rev;
    int ind;
  };
  int n;
  vector<vector<edge>> adj;
  vector<bool> visited;
  graph(int n) : n(n), adj(n), visited(n){ }
  void add_edge(int src, int dst, flow_type capacity) {
    adj[src].push_back({src, dst, capacity, 0, adj[dst].size(), ++cnt});
    adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1, cnt});
  }
  void init(){
    for (int u = 0; u < n; ++u)
    for (auto &e: adj[u]) e.flow = 0;
  }
  int max_flow(int s, int t) {
    function<flow_type(int,flow_type)> augment = [&](int u, flow_type cur) {
      if (u == t) return cur;
      visited[u] = true;
      for (auto &e: adj[u]) {
        if (!visited[e.dst] && e.capacity > e.flow) {
          flow_type f = augment(e.dst, min(e.capacity - e.flow, cur));
          if (f > 0) {
            e.flow += f;
            adj[e.dst][e.rev].flow -= f;
            return f;
          }
        }
      }
      return flow_type(0);
    };
    while (1) {
      fill(all(visited), false);
      flow_type f = augment(s, INF);
      if (f == 0) break;
      flow_value += f;
    }
    return flow_value;
  }
};


const int N = 10005;
int a[N], b[N], deg[N];
void print(vector<int> & edges){
    printf("%d ", (int)edges.size());
    for(int x : edges) printf("%d ", x); printf("\n");
}

vector<int> ans[N];
int main() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    int n = n1 + n2 + 2;
    int src = 0, dst = n1 + n2 + 1;
    for(int i = 1; i <= m; i++) cin >> a[i] >> b[i], deg[a[i]]++, deg[b[i] + n1]++;;
    int mindeg = INF;
    for(int i = 1; i <= n1 + n2; i++) mindeg = min(mindeg, deg[i]);
    graph g(n);
    for(int h = mindeg; h >= 0; h--){
        if(h == mindeg){
            for(int i = 1; i <= m; i++) g.add_edge(a[i], b[i] + n1, 1);
            for(int i = 1; i <= n1; i++) g.add_edge(src, i, deg[i] - h);
            for(int i = 1; i <= n2; i++) g.add_edge(i + n1, dst, deg[i + n1] - h);
            g.init();
        } else{
            for(int i = 1; i <= n1; i++) g.add_edge(src, i, 1);
            for(int i = 1; i <= n2; i++) g.add_edge(n1 + i, dst, 1);
        }

        int maxflow = g.max_flow(src, dst);
        for(int i = 1; i <= n1; i++) for(auto e : g.adj[i]) if(!e.flow && e.ind <= m){
            ans[h].push_back(e.ind);
        }
    }
    for(int i = 0; i <= mindeg; i++) print(ans[i]);
}