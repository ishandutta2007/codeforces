#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <cstring>
#include <functional>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())
#define TEST(s) if (!(s)) { cout << __LINE__ << " " << #s << endl; exit(-1); }

#define DEBUG 0

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

  flow_type max_flow(int s, int t) {
    vector<int> level(n), iter(n);
    function<int(void)> levelize = [&]() { // foward levelize
      level.assign(n, -1); level[s] = 0;
      queue<int> Q; Q.push(s);
      while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == t) break;
        for (auto &e: adj[u]) {
          if (e.capacity > e.flow && level[e.dst] < 0) {
            Q.push(e.dst);
            level[e.dst] = level[u] + 1;
          }
        }
      }
      return level[t];
    };
    function<flow_type(int, flow_type)> augment = [&](int u, flow_type cur) {
      if (u == t) return cur;
      for (int &i = iter[u]; i < adj[u].size(); ++i) {
        edge &e = adj[u][i], &r = adj[e.dst][e.rev];
        if (e.capacity > e.flow && level[u] < level[e.dst]) {
          flow_type f = augment(e.dst, min(cur, e.capacity - e.flow));
          if (f > 0) {
            e.flow += f;
            r.flow -= f;
            return f;
          }
        }
      }
      return flow_type(0);
    };
    for (int u = 0; u < n; ++u) // initialize
      for (auto &e: adj[u]) e.flow = 0;

    flow_type flow = 0;
    while (levelize() >= 0) {
      fill(all(iter), 0);
      for (flow_type f; (f = augment(s, INF)) > 0; )
        flow += f;
    }
    return flow;
  }

  void disp() {
    if (!DEBUG) return;
    cout << "--------" << endl;
    for (int u = 0; u < n; ++u)
      for (auto e: adj[u]) {
        cout << e.src << " " << e.dst << " " << e.capacity << " " << e.flow << " " << e.cost << endl;
      }
    cost_type cost = 0;
    for (int u = 0; u < n; ++u) 
      for (auto &e: adj[u])
        if (e.flow > 0) cost += e.flow * e.cost;
    cout << "cost = " << cost << endl;
  }

  bool minimum_mean_cycle_cancel() {
    vector<vector<flow_type>> dist(n+1, vector<flow_type>(n));
    vector<vector<int>> prev(n+1, vector<int>(n, -1));
    fill(all(prev[0]), 0);

    for (int k = 0; k < n; ++k) {
      for (int u = 0; u < n; ++u) {
        if (prev[k][u] < 0) continue;
        for (auto e: adj[u]) {
          if (e.capacity <= e.flow) continue;
          if (prev[k+1][e.dst] < 0 || dist[k+1][e.dst] > dist[k][u] + e.cost) {
            dist[k+1][e.dst] = dist[k][u] + e.cost;
            prev[k+1][e.dst] = e.rev;
          }
        }
      }
    }
    flow_type num = INF;
    int v, den = 1;
    for (int u = 0; u < n; ++u) {
      flow_type num_u = -INF;
      int den_u = 0;
      for (int k = 0; k < n; ++k) {
        if (prev[k][u] < 0) continue;
        if (num_u * (n-k) < (dist[n][u]-dist[k][u]) * den_u) {
            num_u = (dist[n][u] - dist[k][u]); den_u = n-k;
        }
      }
      if (den_u > 0 && num * den_u > num_u * den) {
        num = num_u; den = den_u; v = u;
      }
    }
    if (num >= 0) return false;
    vector<int> back(n, -1);
    for (int k = n; back[v] < 0; --k) {
      back[v] = prev[k][v];
      edge &r = adj[v][back[v]];
      v = r.dst;
    }
    function<flow_type(int,flow_type)> augment = [&](int u, flow_type cur) {
      if (cur < INF && u == v) return cur;
      edge &r = adj[u][back[u]], &e = adj[r.dst][r.rev];
      flow_type f = augment(r.dst, min(e.capacity - e.flow, cur));
      e.flow += f;
      r.flow -= f;
      return f;
    }; 
    augment(v, INF);
    return true;
  }
  pair<flow_type, cost_type> min_cost_max_flow(int s, int t) {
    flow_type flow = max_flow(s, t);
    while (minimum_mean_cycle_cancel());
    cost_type cost = 0;
    for (int u = 0; u < n; ++u) 
      for (auto &e: adj[u])
        if (e.flow > 0) cost += e.flow * e.cost;
    return {flow, cost};
  }
};

int freq[26], b[105];
int main() {
	int n; cin >> n;
	string s;
	cin >> s;
	s = "#" + s;
	for(int i = 1; i <= n; i++) freq[s[i] - 'a']++, cin >> b[i];
	graph g(100);

	for(int i = 1; i <= n / 2; i++){
		g.add_edge(0, i, 2, 0);
		for(int j = 0; j < 26; j++){
			if(s[i] != 'a' + j && s[n + 1 - i] != 'a' + j)
				g.add_edge(i, 60 + j, 1, 0);
		}
		if(s[i] != s[n + 1 - i]){
			g.add_edge(i, s[i] - 'a' + 60, 1, -b[i]);
			g.add_edge(i, s[n + 1 - i] - 'a' + 60, 1, -b[n + 1 - i]);
		}
		else if(s[i] == s[n + 1 - i])
			g.add_edge(i, s[i] - 'a' + 60, 1, -max(b[i], b[n + 1 - i]));
	}

	for(int j = 0; j < 26; j++)
		g.add_edge(j + 60, 99, freq[j], 0);

	pair<int, int> flowcost = g.min_cost_max_flow(0, 99);
	cerr << flowcost.first << endl;
	cout << -flowcost.second << endl;
}