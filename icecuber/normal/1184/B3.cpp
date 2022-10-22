#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[100][100];

const int nax = 1e5+10;
vector<pair<int,int>> base[nax];
struct Ship {
  int x, a, f;
  ll p;
};

Ship ship[nax];
int easiest_base[100];

struct Edge {
  int end;
  ll cap;
};
vector<Edge> edges;
vector<int> node[nax];
void addEdge(int a, int b, ll w) {
  node[a].push_back(edges.size());
  edges.push_back({b,w});
  node[b].push_back(edges.size());
  edges.push_back({a,0});
}

int done[nax];
ll maxFlow(int p, int sink, ll ma = 1e18) {
  if (p == sink) return ma;
  if (ma == 0 || done[p]++) return 0;
  for (int ei : node[p]) {
    Edge&e = edges[ei];
    ll flow;
    if (e.cap && (flow=maxFlow(e.end, sink, min(ma,e.cap)))) {
      edges[ei].cap -= flow;
      edges[ei^1].cap += flow;
      return flow;
    }
  }
  return 0;
}

int has_edge[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dist[i][j] = i==j ? 0 : 1e9;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    dist[a][b] = dist[b][a] = 1;
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
  int ships, bases, deps;
  cin >> ships >> bases >> deps;
  for (int i = 0; i < ships; i++) {
    cin >> ship[i].x >> ship[i].a >> ship[i].f >> ship[i].p;
    ship[i].x--;
  }
  fill_n(easiest_base, n, 1e9+10);
  for (int i = 0; i < bases; i++) {
    int x, d, g;
    cin >> x >> d >> g;
    x--;
    base[x].push_back({d,g});
    easiest_base[x] = min(easiest_base[x], d);
  }
  for (int i = 0; i < n; i++) {
    sort(base[i].begin(), base[i].end());
    vector<pair<int,int>> comp = {{0,0}};
    for (auto p : base[i]) {
      if (p.second <= comp.back().second) continue;
      if (p.first == comp.back().first)
	comp.pop_back();
      comp.push_back(p);
    }
    base[i] = comp;
  }

  int source = ships, sink = ships+1, N = ships+2;
  ll sum = 0;

  for (int i = 0; i < deps; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    addEdge(a, b, 1e18);
    has_edge[a] = has_edge[b] = 1;
  }

  for (int i = 0; i < ships; i++) {
    int most_gold = -1;
    for (int j = 0; j < n; j++) {
      if (easiest_base[j] > ship[i].a || dist[ship[i].x][j] > ship[i].f) continue;
      int gold = prev(upper_bound(base[j].begin(), base[j].end(), make_pair(ship[i].a,(int)2e9)))->second;
      most_gold = max(most_gold, gold);
    }
    if (!has_edge[i]) {
      sum += max(most_gold-ship[i].p, 0ll);
      continue;
    }

    if (most_gold == -1)
      ship[i].p = 1e15;
    else {
      addEdge(source, i, most_gold);
      sum += most_gold;
    }
    addEdge(i, sink, ship[i].p);
    //cout << i << ' ' << ship[i].p << ' ' << max(most_gold,0) << endl;
  }

  ll flow = 0;
  while (1) {
    fill_n(done, N, 0);
    ll newflow = maxFlow(source, sink);
    if (!newflow) break;
    flow += newflow;
  }
  //cout << sum << ' ' << flow << endl;
  cout << sum-flow << endl;
}