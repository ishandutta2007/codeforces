#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10;
int n, m;

vector <int> e[maxn];

void chkmin(int& x, int y) {
  if (x > y) x = y;
}

bool vis[maxn];
int now, tot, top, st[maxn], sz[maxn], bl[maxn], dfn[maxn], low[maxn], val[maxn];

void tarjan(int u) {
  dfn[u] = low[u] = ++now;
  st[++top] = u, vis[u] = 1;
  for (int v : e[u]) {
    if (!dfn[v]) {
      tarjan(v);
      chkmin(low[u], low[v]);
    } else if (vis[v]) {
      chkmin(low[u], low[v]);
    }
  }
  if (dfn[u] == low[u]) {
    for (tot++; st[top + 1] != u; top--) {
      sz[tot]++;
      vis[st[top]] = 0;
      bl[st[top]] = tot;
    }
  }
}

vector <int> ans[2];

void solve() {
  now = tot = top = 0;
  memset(bl, 0, (n + 1) << 2);
  memset(sz, 0, (n + 1) << 2);
  memset(st, 0, (n + 1) << 2);
  memset(dfn, 0, (n + 1) << 2);
  memset(low, 0, (n + 1) << 2);
  memset(vis, 0, (n + 1) << 2);
  memset(val, 0, (n + 1) << 2);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    e[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u != v) {
      e[u].push_back(v);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  if (sz[bl[1]] == n) {
    puts("No"); return;
  }
  for (int i = 1; i <= n; i++) {
    for (int x : e[i]) {
      if (bl[i] != bl[x]) ++val[bl[i]];
    }
  }
  for (int i = 1; i <= tot; i++) {
    if (val[i]) continue;
    puts("Yes");
    ans[0].clear(), ans[1].clear();
    for (int j = 1; j <= n; j++) {
      ans[bl[j] == i].push_back(j);
    }
    printf("%d %d\n", (int) ans[1].size(), (int) ans[0].size());
    for (int x : ans[1]) printf("%d ", x); puts("");
    for (int x : ans[0]) printf("%d ", x); puts("");
    return;
  }
  puts("No");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}