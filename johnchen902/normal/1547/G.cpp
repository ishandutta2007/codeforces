#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> adj[400'000];
int color[400'000];
int ans[400'000];

void dfs(int v) {
  color[v] = 1;
  ans[v] = 1;
  for (int c : adj[v])
    switch (color[c]) {
      case 0:
        dfs(c);
        break;
      case 1:
        ans[c] = -1;
        break;
      case 2:
        if (ans[c] == 1)
          ans[c] = 2;
        break;
    }
  color[v] = 2;
}

void propagate1(int v) {
  for (int c : adj[v])
    if (ans[c] != -1) {
      ans[c] = -1;
      propagate1(c);
    }
}

void propagate2(int v) {
  for (int c : adj[v])
    if (ans[c] != -1 && ans[c] != 2) {
      ans[c] = 2;
      propagate2(c);
    }
}

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
  }

  dfs(0);
  for (int i = 0; i < n; i++)
    switch (ans[i]) {
      case -1:
        propagate1(i);
        break;
      case 2:
        propagate2(i);
        break;
    }

  for (int i = 0; i < n; i++)
    printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

  for (int i = 0; i < n; i++)
    adj[i].clear();
  std::fill_n(color, n, 0);
  std::fill_n(ans, n, 0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}