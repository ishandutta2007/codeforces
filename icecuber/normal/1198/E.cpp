#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 50;
#define x0 skfdgjh
#define x1 skfdgjhhg
#define y0 skfdgjhgoern
#define y1 skfdgjhre

int x0[nax],y0[nax],x1[nax],y1[nax];

struct Edge {
  int end;
  ll cap;
};
vector<Edge> edges;
vector<int> node[1000];

set<pair<int,int>> added;
void addEdge(int a, int b, ll c) {
  if (added.count({a,b})) return;
  added.insert({a,b});
  node[a].push_back(edges.size());
  edges.push_back({b,c});
  node[b].push_back(edges.size());
  edges.push_back({a,0});
}

int done[1000];
ll maxflow(int p, int sink, ll ma) {
  if (p == sink) return ma;
  if (done[p]++ || ma == 0) return 0;
  for (int ei : node[p]) {
    Edge&e = edges[ei];
    ll f;
    if (e.cap && (f = maxflow(e.end, sink, min(ma,e.cap)))) {
      e.cap -= f;
      edges[ei^1].cap += f;
      return f;
    }
  }
  return 0;
}

int x[1000], y[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int tmp, n;
  cin >> tmp >> n;
  if (!n) {
    cout << 0 << endl;
    return 0;
  }
  map<int,int> xma, yma;
  for (int i = 0; i < n; i++) {
    cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
    x1[i]++, y1[i]++;
    xma[x0[i]], xma[x1[i]];
    yma[y0[i]], yma[y1[i]];
  }
  int cx = 0, cy = 0;
  for (auto&p : xma) {
    x[cx] = p.first;
    p.second = cx++;
  }
  for (auto&p : yma) {
    y[cy] = p.first;
    p.second = cy++;
  }
  int source = cx-1, sink = cx+cy-1;
  for (int i = 1; i < cx; i++)
    addEdge(source, i-1, x[i]-x[i-1]);
  for (int i = 1; i < cy; i++)
    addEdge(i-1+cx, sink, y[i]-y[i-1]);

  int N = cx+cy;

  for (int i = 0; i < n; i++) {
    for (int xi = xma[x0[i]]; xi < xma[x1[i]]; xi++) {
      for (int yi = yma[y0[i]]; yi < yma[y1[i]]; yi++) {
	//cout << xi << ' ' << yi << ' ' << x[xi] << ' ' << x[xi+1] << ' ' << y[yi] << ' ' << y[yi+1] << endl;
	addEdge(xi, yi+cx, 2e9);
      }
    }
  }
  ll flow = 0;
  while (1) {
    fill_n(done, N, 0);
    ll f = maxflow(source, sink, 2e9);
    if (!f) break;
    flow += f;
  }
  cout << flow << endl;
}