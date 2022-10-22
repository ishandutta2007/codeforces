#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 22 | 10;
bool flg[maxn];
int n, m, all, a[maxn];

int l, r;
int Q[maxn << 1];
bool vis[maxn << 1];

inline void add(int u) {
  if (!vis[u] && (u > all || flg[u])) vis[u] = 1, Q[++r] = u;
}

void bfs(int S) {
  l = 1, r = 1, Q[1] = S;
  while (l <= r) {
    int u = Q[l++];
    if (u <= all) {
      add(u | 1 << n);
    } else {
      add(~u & all);
      for (register int i = 0; i < n; ++i) {
        if (~u >> i & 1) add(u | 1 << i);
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", a + i), flg[a[i]] = 1;
  }
  int ans = 0;
  all = (1 << n) - 1;
  for (int i = 1; i <= m; i++) {
    if (!vis[a[i]]) ans++, bfs(a[i]);
  }
  printf("%d", ans);
  return 0;
}