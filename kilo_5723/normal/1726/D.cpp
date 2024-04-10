#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 2e5 + 5;
int f[maxn];
vector<int> e[maxn];
vector<int> k[maxn];
int c[maxn];
struct edge {
  int u, v, i;
};
vector<edge> a;
int ff(int u) { return u == f[u] ? u : f[u] = ff(f[u]); }
bool dfs(int s, int f, int t) {
  if (s == t) return true;
  for (auto v : e[s])
    if (v != f && dfs(v, s, t)) return true;
  return false;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    a.clear();
    for (int i = 1; i <= n; i++) {
      f[i] = i;
      e[i].clear();
      k[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      if (ff(u) == ff(v)) {
        c[i] = 0;
        a.push_back({min(u, v), max(u, v), i});
        continue;
      }
      c[i] = 1;
      f[ff(u)] = ff(v);
      e[u].push_back(v);
      e[v].push_back(u);
      k[u].push_back(i);
      k[v].push_back(i);
    }
    sort(a.begin(), a.end(), [](edge a, edge b) {
      if (a.u != b.u) return a.u < b.u;
      if (a.v != b.v) return a.v < b.v;
      return false;
    });
    if (a.size() == 3 && a[0].u == a[1].u && a[0].v == a[2].u &&
        a[1].v == a[2].v) {
      c[a[2].i] = 1;
      int u = a[2].u, v = a[2].v;
      for (int i = 0; i < e[u].size(); i++)
        if (dfs(e[u][i], u, v)) {
          c[k[u][i]] = 0;
          break;
        }
    }
    for (int i = 0; i < m; i++) putchar('0' + c[i]);
    puts("");
  }
  return 0;
}