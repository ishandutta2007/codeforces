#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5, m = 20;
vector<int> e[maxn];
vector<pair<int, int>> q;
int b[maxn];
int f[maxn];
int a[maxn][m];
int d[maxn];
int ff(int u) { return f[u] == u ? u : f[u] = ff(f[u]); }
void comb(int u, int v) {
  u = ff(u);
  v = ff(v);
  f[u] = v;
}
void dfs1(int u, int f) {
  a[u][0] = f;
  d[u] = d[f] + 1;
  for (int i = 1; i < m; i++) a[u][i] = a[a[u][i - 1]][i - 1];
  for (auto v : e[u])
    if (v != f) dfs1(v, u);
}
int getf(int u, int dep) {
  for (int i = 0; i < m; i++)
    if (dep - d[u] >> i & 1) u = a[u][i];
  return u;
}
bool is_parent(int u, int v) {
  if (d[u] < d[v]) swap(u, v);
  for (int i = 0; i < m; i++)
    if (d[v] - d[u] >> i & 1) u = a[u][i];
  return u == v;
}
void dfs2(int u, int f) {
  for (auto v : e[u])
    if (v != f) {
      b[v] += b[u];
      dfs2(v, u);
    }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) e[i].clear();
  for (int i = 1; i <= n; i++) f[i] = i;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (ff(u) != ff(v)) {
      e[u].push_back(v);
      e[v].push_back(u);
      comb(u, v);
    } else {
      q.push_back({u, v});
    }
  }
  d[1] = 0;
  dfs1(1, 1);
  for (auto pr : q) {
    int u = pr.first, v = pr.second;
    if (d[u] < d[v]) swap(u, v);
    if (is_parent(v, u)) {
      int w = getf(u, d[v] + 1);
      b[w]++;
      b[u]--;
    } else {
      b[1]++;
      b[u]--;
      b[v]--;
    }
  }
  dfs2(1, 1);
  for (int i = 1; i <= n; i++) putchar(b[i] ? '0' : '1');
  puts("");
  return 0;
}