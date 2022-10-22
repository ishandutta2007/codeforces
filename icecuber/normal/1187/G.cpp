#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int end, cap, cost;
};

const int maxt = 100;
vector<Edge> edges;
const int nax = maxt*50+10;
vector<int> node[nax];

void addEdge(int a, int b, int cost, int cap = 1) {
  node[a].push_back(edges.size());
  edges.push_back({b,cap, cost});
  node[b].push_back(edges.size());
  edges.push_back({a,0,-cost});
}

int dist[nax], phi[nax], par[nax];
void dijkstra(int N, int source) {
  fill_n(dist, N, 1e9);
  priority_queue<pair<int,int>> pq;
  pq.push({0,source});
  dist[source] = 0;
  while (pq.size()) {
    int p = pq.top().second;
    int d =-pq.top().first;
    pq.pop();
    if (d > dist[p]) continue;
    for (int ei : node[p]) {
      Edge&e = edges[ei];
      int dd = d+phi[p]+e.cost-phi[e.end];
      if (e.cap && dist[e.end] > dd) {
	dist[e.end] = dd;
	par[e.end] = ei;
	pq.push({-dist[e.end],e.end});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, K, c, d;
  cin >> n >> m >> K >> c >> d;
  int source = maxt*n, sink = maxt*n+1;
  int N = maxt*n+2;
  for (int i = 0; i < K; i++) {
    int a;
    cin >> a;
    a--;
    addEdge(source, a, 0);
  }
  for (int t = 0; t < maxt-1; t++) {
    addEdge(t*n,sink,t*c, 1e9);
    for (int i = 0; i < n; i++)
      addEdge(t*n+i, t*n+n+i, 0, 1e9);
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    for (int t = 0; t < maxt-1; t++)
      for (int k = 0; k < K; k++) {
	addEdge(t*n+a,t*n+n+b,d*((k+1)*(k+1)-k*k));
	addEdge(t*n+b,t*n+n+a,d*((k+1)*(k+1)-k*k));
      }
  }

  int ans = 0, flow = 0;
  while (1) {
    dijkstra(N, source);
    if (dist[sink] == 1e9) break;
    for (int i = 0; i < N; i++)
      phi[i] = min(phi[i]+dist[i], int(1e9));

    for (int p = sink; p != source; p = edges[par[p]^1].end) {
      int ei = par[p];
      edges[ei].cap--;
      edges[ei^1].cap++;
      ans += edges[ei].cost;
    }
    flow++;
  }
  assert(flow == K);
  cout << ans << endl;
}