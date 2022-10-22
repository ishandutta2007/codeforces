#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
  int end;
  ll dist;
  int starti;
  bool operator<(const Edge&o) const {
    return dist > o.dist;
  }
};

vector<Edge> node[300000];
ll dist[300000];
Edge par[300000];
int done[300000];

int main() {
  ios::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--,b--;
    node[a].push_back({b,w,i+1});
    node[b].push_back({a,w,i+1});
  }
  for (int i = 1; i < n; i++)
    dist[i] = 1e18;

  vector<Edge> edges;
  priority_queue<Edge> pq;
  pq.push({0,0,0});
  while (pq.size()) {
    int p = pq.top().end;
    ll d = pq.top().dist;
    pq.pop();
    if (done[p]++) continue;
    if (p)
      edges.push_back(par[p]);
    for (Edge e : node[p]) {
      if (dist[e.end] > d+e.dist) {
	dist[e.end] = d+e.dist;
	par[e.end] = e;
	pq.push({e.end, dist[e.end], 0});
      }
    }
  }
  int e = min(int(edges.size()), k);
  cout << e << endl;
  for (int i = 0; i < e; i++)
    cout << edges[i].starti << ' ';
  cout << endl;
}