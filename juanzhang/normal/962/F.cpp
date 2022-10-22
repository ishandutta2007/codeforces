#include <bits/stdc++.h>
using namespace std;

#define nc getchar()
const int maxn = 1e5 + 10;
int n, m, tot, top, h[maxn], dfn[maxn], low[maxn], st[maxn * 3];
struct edges {
  int nxt, to;
} e[maxn << 1];
set <int> ans, edge[maxn], node[maxn];

inline int read() {
  int x = 0; char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + c - 48, c = nc;
  return x;
}

void addline(int u, int v) {
  static int cnt = 1;
  e[++cnt] = edges{h[u], v}, h[u] = cnt;
}

void tarjan(int u, int f) {
  static int now;
  dfn[u] = low[u] = ++now;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (!dfn[v]) {
      st[++top] = i >> 1, st[++top] = u, st[++top] = v;
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (dfn[u] <= low[v]) {
        tot++;
        while (1) {
          int t1, t2;
          node[tot].insert(t1 = st[top--]);
          node[tot].insert(t2 = st[top--]);
          edge[tot].insert(st[top--]);
          if (t1 == v && t2 == u) break;
        }
      }
    } else if (dfn[v] < dfn[u] && v != f) {
      st[++top] = i >> 1, st[++top] = u, st[++top] = v;
      low[u] = min(low[u], dfn[v]);
    }
  }
}

int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    addline(u, v), addline(v, u);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i, 0);
  }
  for (int i = 1; i <= tot; i++) {
    if (edge[i].size() == node[i].size()) {
      ans.insert(edge[i].begin(), edge[i].end());
    }
  }
  printf("%d\n", (int)ans.size());
  for (int u : ans) printf("%d ", u);
  return 0;
}