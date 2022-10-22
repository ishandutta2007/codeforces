#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int end, cap;
};
vector<Edge> edges;
vector<int> node[10000];
int done[10000];
int maxflow(int p, int sink, int ma) {
  if (p == sink) return ma;
  done[p] = 1;
  for (int ei : node[p]) {
    Edge&e = edges[ei];
    int flow;
    if (e.cap && !done[e.end] && (flow = maxflow(e.end, sink, min(ma, e.cap)))) {
      edges[ei].cap -= flow;
      edges[ei^1].cap += flow;
      return flow;
    }
  }
  return 0;
}

void addEdge(int a, int b, int c) {
  node[a].push_back(edges.size());
  edges.push_back({b,c});
  node[b].push_back(edges.size());
  edges.push_back({a,0});
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, h, m;
  cin >> n >> h >> m;
  int source = n*h+m, sink = source+1, N = sink+1;
  int ans = h*h*n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < h; j++)
      addEdge(source, i*h+j, j*2+1);
  for (int i = 0; i < m; i++) {
    int l, r, x, c;
    cin >> l >> r >> x >> c;
    l--;
    addEdge(n*h+i, sink, c);
    for (int j = l; j < r; j++)
      for (int k = x; k < h; k++)
	addEdge(j*h+k, n*h+i, 1e9);
  }
  while (1) {
    fill_n(done, N, 0);
    int flow = maxflow(source, sink, 1e9);
    if (!flow) break;
    ans -= flow;
  }
  cout << ans << endl;
}