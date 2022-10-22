#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 10;
int n, m, tot, par[maxn], sz[maxn], deg[maxn];

vector <int> e[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  if ((x = find(x)) != (y = find(y))) {
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x, sz[x] += sz[y], tot--;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  rep(i, 1, m) {
    int u, v;
    scanf("%d %d", &u, &v);
    e[u].push_back(v), deg[u]++;
    e[v].push_back(u), deg[v]++;
  }
  tot = n;
  int pos = -1;
  rep(i, 1, n) {
    par[i] = i, sz[i] = 1;
    if (pos == -1 || (pos > 0 && deg[i] < deg[pos])) {
      pos = i;
    }
  }
  static int vis[maxn], sum[maxn];
  for (int v : e[pos]) {
    vis[v] = 1;
  }
  rep(i, 1, n) {
    if (!vis[i]) unite(i, pos);
  }
  memset(vis, 0, sizeof vis);
  vector <int> vec;
  rep(i, 1, n) {
    if (find(i) == i) vec.push_back(i);
  }
  rep(u, 1, n) {
    for (int v : e[u]) {
      int x = find(v);
      if (vis[x] != u) {
        vis[x] = u, sum[x] = 1;
      } else {
        sum[x]++;
      }
    }
    for (int x : vec) {
      int v = find(x);
      if (vis[v] != u || (vis[v] == u && sum[v] != sz[v])) unite(u, v);
    }
  }
  printf("%d\n", tot - 1);
  return 0;
}