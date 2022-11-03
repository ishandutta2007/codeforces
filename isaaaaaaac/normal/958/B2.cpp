#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5 + 50;

struct edge {
  int nxt, to;
} e[N << 1];
int fir[N], cnt = 0, n;
int dep[N], fa[N], deg[N], rt, fix[N], id[N];
bool vis[N];

inline void addedge(int x, int y) {
  e[++ cnt] = (edge) { fir[x], y }; fir[x] = cnt;
}

inline void Dfs(int x, int f) {
  if (dep[x] > dep[rt]) rt = x;
  for (int i = fir[x]; i; i = e[i].nxt)
    if (e[i].to != f) {
      dep[e[i].to] = dep[x] + 1;
      Dfs(e[i].to, x);
    }
}

inline void Dfs1(int x, int f) {
  fa[x] = f;
  for (int i = fir[x]; i; i = e[i].nxt)
    if (e[i].to != f) {
      dep[e[i].to] = dep[x] + 1;
      Dfs1(e[i].to, x);
    }
}

inline bool cmp(int x, int y) {
  return dep[x] > dep[y];
}

int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i ++) {
    scanf("%d%d", &x, &y);
    addedge(x, y); addedge(y, x);
    deg[x] ++; deg[y] ++; id[i] = i;
  }
  id[n] = n;
  Dfs(1, 0);
  dep[rt] = 0;
  Dfs1(rt, 0);
  vis[rt] = 1;
  int tot = 0, cur = 1;
  sort(id + 1, id + n + 1, cmp);
  for (int i = 1; i < n; i ++)
    if (deg[id[i]] == 1) {
      int c = 0, x = id[i];
      while (!vis[x]) {
        vis[x] = 1; c ++; x = fa[x];
      }
      fix[++ tot] = c;
    }
  sort(fix + 1, fix + tot + 1, greater <int> ());
  for (int i = 0; i < n; i ++) {
    cur += fix[i];
    printf("%d ", cur);
  }
  puts("");
  return 0;
}