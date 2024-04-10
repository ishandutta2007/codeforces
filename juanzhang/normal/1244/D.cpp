#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e5 + 10;
int n, a[maxn][4];

int deg[maxn];
vector <int> e[maxn];

int c[maxn];
int ans;

void dfs(int u, int f, int v1, int v2) {
  int t;
  for (int i = 1; i <= 3; i++) {
    if (i != v1 && i != v2) t = i;
  }
  ans += a[u][t], c[u] = t;
  for (int v : e[u]) {
    if (v != f) dfs(v, u, v2, t);
  }
}

signed main() {
  scanf("%I64d", &n);
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%I64d", &a[j][i]);
    }
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%I64d %I64d", &u, &v);
    e[u].push_back(v), deg[u]++;
    e[v].push_back(u), deg[v]++;
  }
  int rt;
  for (int i = 1; i <= n; i++) {
    if (deg[i] > 2) {
      return puts("-1"), 0;
    }
    if (deg[i] == 1) {
      rt = i;
    }
  }
  int s1 = e[rt][0], s2;
  for (int v : e[s1]) {
    if (v != rt) s2 = v;
  }
  int val = 1ll << 60;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      if (i == j) continue;
      ans = 0;
      dfs(s2, s1, i, j);
      val = min(val, ans + a[rt][i] + a[s1][j]);
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      if (i == j) continue;
      ans = 0;
      dfs(s2, s1, i, j);
      ans += a[rt][i] + a[s1][j];
      c[rt] = i, c[s1] = j;
      if (ans == val) {
        printf("%I64d\n", ans);
        for (int p = 1; p <= n; p++) {
          printf("%I64d ", c[p]);
        }
        return 0;
      }
    }
  }
  return 0;
}