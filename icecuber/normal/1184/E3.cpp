#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int a, b, c, i;
};

Edge edge[1000000];
int par[100000];
int myfind(int p) {
  return par[p] = p == par[p] ? p : myfind(par[p]);
}

vector<pair<int,int>> node[100000];
int pa[20][100000];
int ma[20][100000];
int mi[20][100000];
int depth[100000];

void dfs(int p, int d = 0, int par = -1) {
  depth[p] = d;
  for (auto e : node[p]) {
    int i = e.first, w = e.second;
    if (i == par) continue;
    dfs(i,d+1,p);
    pa[0][i] = p;
    ma[0][i] = w;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> edge[i].a >> edge[i].b >> edge[i].c;
    edge[i].a--, edge[i].b--;
    edge[i].i = i;
  }
  for (int i = 0; i < n; i++)
    par[i] = i;
  sort(edge, edge+m, [&](const Edge&a, const Edge&b) {return a.c < b.c;});
  for (int i = 0; i < m; i++) {
    int a = myfind(edge[i].a), b = myfind(edge[i].b);
    if (a != b) {
      par[a] = b;
      node[edge[i].a].push_back({edge[i].b,edge[i].c});
      node[edge[i].b].push_back({edge[i].a,edge[i].c});
      edge[i].c = -1;
    }
  }
  dfs(0);
  for (int l = 0; l+1 < 20; l++) {
    for (int i = 0; i < n; i++) {
      int p = pa[l][i];
      pa[l+1][i] = pa[l][p];
      ma[l+1][i] = max(ma[l][i],ma[l][p]);
    }
  }
  for (int l = 0; l < 20; l++)
    for (int i = 0; i < n; i++)
      mi[l][i] = 1e9;
  sort(edge, edge+m, [&](const Edge&a, const Edge&b) {return a.i < b.i;});
  vector<int> ans(m);
  for (int i = 0; i < m; i++) {
    int a = edge[i].a, b = edge[i].b, c = edge[i].c;
    if (c == -1) continue;
    if (depth[a] < depth[b]) swap(a,b);
    int high = 0;
    for (int l = 19; l >= 0; l--) {
      if (depth[pa[l][a]] >= depth[b]) {
	high = max(high, ma[l][a]);
	mi[l][a] = min(mi[l][a], c);
	a = pa[l][a];
      }
    }
    assert(depth[a] == depth[b]);
    for (int l = 19; l >= -1; l--) {
      if (l == -1 && a != b || l > -1 && pa[l][a] != pa[l][b]) {
	l = max(l,0);
	high = max(high, ma[l][a]);
	high = max(high, ma[l][b]);
	mi[l][a] = min(mi[l][a], c);
	mi[l][b] = min(mi[l][b], c);
	a = pa[l][a];
	b = pa[l][b];
      }
    }
    assert(a==b);
    ans[i] = high;
  }
  for (int l = 18; l >= 0; l--) {
    for (int i = 0; i < n; i++) {
      int p = pa[l][i];
      mi[l][i] = min(mi[l][i], mi[l+1][i]);
      mi[l][p] = min(mi[l][p], mi[l+1][i]);
    }
  }
  for (int i = 0; i < m; i++) {
    if (edge[i].c == -1) {
      int a = edge[i].a, b = edge[i].b;
      if (pa[0][a] == b)
	ans[i] = mi[0][a];
      else
	ans[i] = mi[0][b];
    }
    cout << ans[i] << '\n';
  }
}