#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool vis[maxn], flg[maxn];
int n, m, top, scc, st[maxn], bl[maxn], par[maxn], sum[maxn], dfn[maxn], low[maxn];

vector <int> e[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void tarjan(int u) {
  static int now;
  dfn[u] = low[u] = ++now;
  vis[u] = 1, st[++top] = u;
  for (int v : e[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (vis[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    for (scc++; st[top + 1] != u; top--) {
      int x = st[top];
      vis[x] = 0, bl[x] = scc, sum[scc]++;
    }
    flg[scc] = sum[scc] > 1;
  }
}

void rebuild() {
  for (int u = 1; u <= n; u++) {
    for (int v : e[u]) {
      int p = find(bl[u]), q = find(bl[v]);
      if (p != q) {
        par[q] = p, sum[p] += sum[q], flg[p] |= flg[q];
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d %d", &u, &v);
    e[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= scc; i++) {
    par[i] = i;
  }
  rebuild();
  int ans = 0;
  for (int i = 1; i <= scc; i++) {
    if (par[i] == i) ans += sum[i] - (!flg[i]);
  }
  printf("%d", ans);
  return 0;
}