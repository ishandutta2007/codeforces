#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int buf_dp[maxn], *dp[maxn], *it = buf_dp;
int n, m, h[maxn], len[maxn], son[maxn], ans[maxn];

struct edges {
  int nxt, to;
} e[maxn << 1];

void addline(int u, int v) {
  static int cnt;
  e[++cnt] = edges{h[u], v}, h[u] = cnt;
}

void dfs(int u, int f) {
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v != f) {
      dfs(v, u);
      if (len[son[u]] < len[v]) son[u] = v;
    }
  }
  len[u] = len[son[u]] + 1;
}

void DP(int u, int f) {
  *dp[u] = 1;
  if (son[u]) {
    dp[son[u]] = dp[u] + 1;
    DP(son[u], u), ans[u] = ans[son[u]] + 1;
  }
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v != f && v != son[u]) {
      dp[v] = it, it += len[v], DP(v, u);
      for (int j = 1; j <= len[v]; j++) {
        dp[u][j] += dp[v][j - 1];
        if (dp[u][j] > dp[u][ans[u]] || (dp[u][j] == dp[u][ans[u]] && j < ans[u])) {
          ans[u] = j;
        }
      }
    }
  }
  if (dp[u][ans[u]] == 1) ans[u] = 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    addline(u, v), addline(v, u);
  }
  dfs(1, 0);
  dp[1] = it, it += len[1];
  DP(1, 0);
  for (int i = 1; i <= n; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}