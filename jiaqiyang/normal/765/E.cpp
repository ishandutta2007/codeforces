#include <cctype>
#include <stdio.h>
#include <vector>
#include <algorithm>

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

const int N = 200000 + 10;

int n;
std::vector<int> adj[N];

int q[N], fa[N];

int down[N], up[N], ans;

void bfs() {
  q[1] = 1;
  for (int i = 1, r = 1; i <= r; ++i) {
    int a = q[i];
    for (int j = 0; j < adj[a].size(); ++j) {
      int b = adj[a][j];
      if (b != fa[a]) fa[q[++r] = b] = a;
    }
  }
  for (int i = n; i > 0; --i) {
    int a = q[i];
    for (int j = 0; j < adj[a].size(); ++j) {
      int b = adj[a][j];
      if (b != fa[a]) down[a] = down[b] + 1;
    }
    for (int j = 0; j < adj[a].size(); ++j) {
      int b = adj[a][j];
      if (b != fa[a] && down[a] != down[b] + 1) {
        down[a] = N;
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    int a = q[i], tot = 0;
    static int cur[N];
    for (int j = 0; j < adj[a].size(); ++j) {
      int b = adj[a][j];
      if (b != fa[a]) cur[++tot] = down[b] + 1;
    }
    if (i > 1) cur[++tot] = up[a];
    static bool pre[N], suf[N];
    pre[1] = pre[2] = true;
    suf[tot - 1] = suf[tot] = true;
    for (int i = 2; i < tot; ++i) pre[i + 1] = (pre[i] && cur[i - 1] == cur[i]);
    for (int i = tot - 1; i > 1; --i) suf[i - 1] = (suf[i] && cur[i + 1] == cur[i]);
    for (int j = 0, k = 0; j < adj[a].size(); ++j) {
      int b = adj[a][j];
      if (b != fa[a]) {
        ++k;
        if (pre[k] && suf[k] && (k == 1 || k == tot || cur[k - 1] == cur[k + 1])) up[b] = cur[k > 1 ? (k - 1) : (k + 1)] + 1; else up[b] = N;
      }
    }
    std::sort(cur + 1, cur + tot + 1);
    tot = std::unique(cur + 1, cur + tot + 1) - cur - 1;
    if (tot == 1) ans = std::min(ans, cur[1]);
    if (tot == 2) ans = std::min(ans, cur[1] + cur[2]);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = n - 1; i--;) {
    int u = nextInt(), v = nextInt();
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = 2 * n;
  bfs();
  if (ans < n) while (!(ans & 1)) ans >>= 1;
  printf("%d\n", ans < n ? ans : -1);
  return 0;
}