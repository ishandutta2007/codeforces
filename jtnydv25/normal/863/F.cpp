#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())
#define TEST(s) if (!(s)) { cout << __LINE__ << " " << #s << endl; exit(-1); }

const long long INF = 99999999;
struct graph {
  typedef int flow_type;
  typedef int cost_type;
  struct edge {
    int src, dst;
    flow_type capacity, flow;
    cost_type cost;
    size_t rev;
  };
  vector<edge> edges;
  void add_edge(int src, int dst, flow_type cap, cost_type cost) {
    adj[src].push_back({src, dst, cap, 0, cost, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, -cost, adj[src].size()-1});
  }
  int n;
  vector<vector<edge>> adj;
  graph(int n) : n(n), adj(n) { }

  pair<flow_type, cost_type> min_cost_max_flow(int s, int t) {
    flow_type flow = 0;
    cost_type cost = 0;

    for (int u = 0; u < n; ++u) // initialize
      for (auto &e: adj[u]) e.flow = 0;

    vector<cost_type> p(n, 0);

    auto rcost = [&](edge e) { return e.cost + p[e.src] - p[e.dst]; };
    for (int iter = 0; ; ++iter) {
      vector<int> prev(n, -1); prev[s] = 0;
      vector<cost_type> dist(n, INF); dist[s] = 0;
      if (iter == 0) { // use Bellman-Ford to remove negative cost edges
        vector<int> count(n); count[s] = 1;
        queue<int> que; 
        for (que.push(s); !que.empty(); ) {
          int u = que.front(); que.pop();
          count[u] = -count[u];
          for (auto &e: adj[u]) {
            if (e.capacity > e.flow && dist[e.dst] > dist[e.src] + rcost(e)) {
              dist[e.dst] = dist[e.src] + rcost(e);
              prev[e.dst] = e.rev;
              if (count[e.dst] <= 0) {
                count[e.dst] = -count[e.dst] + 1;
                que.push(e.dst);
              }
            }
          }
        }
      } else { // use Dijkstra 
        typedef pair<cost_type, int> node;
        priority_queue<node, vector<node>, greater<node>> que;
        que.push({0, s});
        while (!que.empty()) {
          node a = que.top(); que.pop();
          if (a.snd == t) break;
          if (dist[a.snd] > a.fst) continue;
          for (auto e: adj[a.snd]) {
            if (e.capacity > e.flow && dist[e.dst] > a.fst + rcost(e)) {
              dist[e.dst] = dist[e.src] + rcost(e);
              prev[e.dst] = e.rev;
              que.push({dist[e.dst], e.dst});
            }
          }
        }
      }
      if (prev[t] == -1) break;

      for (int u = 0; u < n; ++u) 
        if (dist[u] < dist[t]) p[u] += dist[u] - dist[t];

      function<flow_type(int,flow_type)> augment = [&](int u, flow_type cur) {
        if (u == s) return cur;
        edge &r = adj[u][prev[u]], &e = adj[r.dst][r.rev];
        flow_type f = augment(e.src, min(e.capacity - e.flow, cur));
        e.flow += f; r.flow -= f;
        return f;
      };
      flow_type f = augment(t, INF);
      flow += f;
      cost += f * (p[t] - p[s]);
    }
    return {flow, cost};
  }
};

const int N = 55;
int mn[N], mx[N];

int main() {
	int n, q, type, l, r, v;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) mn[i] = 1, mx[i] = n;
	for(int i = 1; i <= q; i++){
		cin >> type >> l >> r >> v;
		for(int j = l; j <= r; j++){
			if(type == 1){
				mn[j] = max(mn[j], v);
			}
			else mx[j] = min(mx[j], v);
		}
	}
	graph g(105);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j ++){
			g.add_edge(0, i, 1, 2 * j - 1);
			if(mn[j] <= i && mx[j] >= i){
				g.add_edge(i, n + j, 1, 0);
			}
		}
		g.add_edge(n + i, 103, 1, 0);
	}
  	auto a = g.min_cost_max_flow(0, 103);
  	cout << (a.fst == n ? a.second : -1);
}