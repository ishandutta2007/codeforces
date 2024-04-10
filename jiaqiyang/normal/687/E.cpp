#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 5000 + 10;

int n, m, x[N], y[N];

bool flag[N];

int dfn[N], low[N], id[N];

std::vector<int> adj[N], scc[N];

void tarjan(int a) {
  static int stk[N], top, tot;
  dfn[a] = low[a] = ++tot;
  flag[stk[++top] = a] = true;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (!dfn[b]) tarjan(b);
    if (flag[b]) low[a] = std::min(low[a], low[b]);
  }
  if (low[a] == dfn[a]) {
    for (int b; (b = stk[top]) != a; --top) scc[id[b] = a].push_back(b), flag[b] = false;
    scc[id[a] = a].push_back(a);
    flag[a] = false;
    --top;
  }
}

int bfs(int s) {
  static int q[N], tag[N], dep[N], cnt;
  ++cnt;
  tag[q[1] = s] = ++cnt;
  dep[s] = 1;
  for (int f = 1, r = 1; f <= r; ++f) {
    int a = q[f];
    for (int i = 0; i < adj[a].size(); ++i) {
      int b = adj[a][i];
      if (b == s) return dep[a];
      if (tag[b] != cnt) tag[q[++r] = b] = cnt, dep[b] = dep[a] + 1;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &x[i], &y[i]), adj[x[i]].push_back(y[i]);
  for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i);
  static int deg[N];
  int ans = n;
  for (int i = 1; i <= m; ++i) if (id[x[i]] != id[y[i]]) ++deg[id[x[i]]];
  for (int i = 1; i <= n; ++i) {
    if (id[i] != i || deg[i] || scc[i].size() == 1) continue;
    ++ans;
    int cur = scc[i].size();
    for (int j = 0; j < scc[i].size(); ++j) cur = std::min(cur, bfs(scc[i][j]));
    ans += 998 * cur;
  }
  printf("%d\n", ans);
  return 0;
}