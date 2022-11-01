#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 2e5 + 5;
int n, m, c[N], f[N];
ll v[N], tag[N];
vector<int> e[N];
vector<pair<int, int> > edges;
int getf(int x) { return f[x] == x ? x : f[x] = getf(f[x]); }
void dfs(int u, int p) {
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (v == p) continue;
    c[v] = c[u] ^ 1;
    dfs(v, u);
  }
  if (p) {
    v[p] += tag[u] - v[u];
    v[u] = tag[u];
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &tag[i]);
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i <= n; i++) f[i] = i;
    edges.clear();
    for (int i = 1; i <= m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      if (getf(u) != getf(v)) {
        f[getf(u)] = getf(v);
        e[u].push_back(v);
        e[v].push_back(u);
      }
      edges.push_back(mp(u, v));
    }
    c[1] = 2;
    dfs(1, 0);
    if (v[1] == tag[1])
      printf("YES\n");
    else {
      bool flag = false;
      for (int i = 0; i < edges.size(); i++) {
        flag |= c[edges[i].first] == c[edges[i].second];
      }
      printf(flag && ((tag[1] - v[1]) % 2 + 2) % 2 == 0 ? "YES\n" : "NO\n");
    }
  }
}