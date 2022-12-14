#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <iostream>

const int N = 3000 + 10, E = N * 2;

int n, x[N], y[N];

int adj[N];
int to[E], next[E], cnt;

int col[N], dep[N], tag[N], size[N];

bool flag[N], forbid[N];

inline void link(int a, int b) {
  to[cnt] = b;
  next[cnt] = adj[a];
  adj[a] = cnt++;
}

int fa[N];

int DFS(int a, int e = -1) {
  flag[a] = true;
  for (int it = adj[a]; it; it = next[it]) {
    if (it == (e ^ 1)) continue;
    int b = to[it];
    if (!flag[b]) {
      fa[b] = a;
      int res = DFS(b, it);
      if (~res) return res;
    } else {
      for (int i = a; i != b; i = fa[i]) ++size[tag[i] = b];
      return b;
    }
  }
  flag[a] = false;
  return -1;
}

double Solve(int a, int dep = 1) {
  flag[a] = true;
  double res = 1.0 / dep;
  for (int it = adj[a]; it; it = next[it]) {
    int b = to[it];
    if (!flag[b]) res += Solve(b, dep + 1);
  }
  flag[a] = false;
  return res;
}

void Paint(int a) {
  for (int it = adj[a]; it; it = next[it]) {
    int b = to[it];
    if (!~col[b] && tag[b] != tag[a]) {
      col[b] = col[a];
      dep[b] = dep[a] + 1;
      Paint(b);
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  scanf("%d", &n);
  cnt = 2;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", x + i, y + i);
    link(x[i], y[i]);
    link(y[i], x[i]);
  }
  for (int i = 0; i < n; ++i) tag[i] = i, size[i] = 1;
  double ans = 0.0;
  for (int i = 0; i < n; ++i) ans += Solve(i);
  std::fill(fa, fa + n, -1);
  int root = DFS(0);
  std::fill(col, col + n, -1);
  for (int i = 0; i < n; ++i) if (tag[i] == root) col[i] = i, Paint(i);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (col[i] == col[j]) continue;
      ans -= 1.0 / (size[root] + dep[i] + dep[j]);
    }
  }
  printf("%.10f\n", ans);
  return 0;
}