#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int w, s, e;
};
bool operator<(Edge a, Edge b) {
  return a.w > b.w;
}

vector<pair<int,int>> node[200000];
int done[200000];
vector<int> child[200000];
int par[19][200000];
int ma[19][200000];
int depth[200000];

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].emplace_back(b,c);
    node[b].emplace_back(a,c);
    edges.push_back({c,a,b});
  }
  priority_queue<Edge> pq;
  pq.push({0,0,0});
  depth[0] = -1;
  int ans = 0;
  while (pq.size()) {
    int w = pq.top().w;
    int s = pq.top().s;
    int p = pq.top().e;
    pq.pop();
    if (done[p]++) continue;
    child[s].push_back(p);
    par[0][p] = s;
    ma[0][p] = w;
    depth[p] = depth[s]+1;
    for (auto e : node[p])
      pq.push({e.second, p, e.first});
  }
  for (int i = 1; i < 19; i++) {
    for (int j = 0; j < n; j++) {
      par[i][j] = par[i-1][par[i-1][j]];
      ma[i][j] = max(ma[i-1][j], ma[i-1][par[i-1][j]]);
    }
  }
  for (auto e : edges) {
    int a = e.s, b = e.e, w = e.w;
    if (depth[b] > depth[a]) swap(a,b);
    int found = 0;
    for (int i = 18; i >= 0; i--) {
      if (depth[a] >= depth[b]+(1<<i)) {
	found |= w==ma[i][a];
	a = par[i][a];
      }
    }
    for (int i = 18; i >= 0; i--) {
      if (par[i][a] != par[i][b]) {
	found |= w==ma[i][a] || w==ma[i][b];
	a = par[i][a];
	b = par[i][b];
      }
    }
    found |= w==ma[0][a] || w==ma[0][b];
    ans += found;
  }
  ans -= n-1;
  cout << ans << endl;
}