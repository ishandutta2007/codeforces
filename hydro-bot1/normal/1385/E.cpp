// Hydro submission #6308974545cdc66f60ca2f94@1661507398565
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 200005;
int n, m;
vector<int> G[MAXN];
int c[MAXN], topo[MAXN], id[MAXN], t, bn, x[MAXN], y[MAXN];
bool dfs(int u) {
  c[u] = -1;
  for (auto v : G[u]) {
    if (c[v] < 0)
      return false;
    else if (c[v] == 0 && !dfs(v))
      return false;
  }
  c[u] = 1;
  topo[--t] = u;
  id[u] = t;
  return true;
}
bool toposort() {
  t = n;
  memset(c, 0, sizeof(c));
  memset(id, 0x3f, sizeof(id));
  memset(topo, 0, sizeof(topo));
  for (int i = 1; i <= n; i++)
    if (!c[i])
      if (!dfs(i)) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) G[i].clear();
    bn = 0;
    for (int i = 0; i < m; i++) {
      int ti, tx, ty;
      cin >> ti >> tx >> ty;
      if (ti == 0) {  // 
        x[++bn] = tx;
        y[bn] = ty;
      } else {
        G[tx].push_back(ty);
      }
    }
    if (!toposort()) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 1; i <= bn; i++) {
      if (id[x[i]] <= id[y[i]])
        cout << x[i] << " " << y[i] << endl;
      else
        cout << y[i] << " " << x[i] << endl;
    }
    for (int i = 1; i <= n; i++) {
      for (auto j : G[i]) { cout << i << " " << j << endl; }
    }
  }
  return 0;
}