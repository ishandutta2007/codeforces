#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 10;
int n, m, h[maxn];

struct edges {
  int nxt, to, w;
} e[maxn << 1];

void addline(int u, int v) {
  static int cnt = 1;
  e[++cnt] = edges{h[u], v, 0}, h[u] = cnt;
}

int col[maxn];

bool dfs(int u, int c) {
  col[u] = c;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (col[v] == c || (col[v] == -1 && !dfs(v, c ^ 1))) {
      return 0;
    }
    e[i].w = col[u], e[i ^ 1].w = col[u] ^ 1;
  }
  return 1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    addline(u, v), addline(v, u);
  }
  memset(col, -1, (n + 1) << 2);
  for (int i = 1; i <= n; i++) {
    if (col[i] == -1 && !dfs(i, 0)) {
      return puts("NO"), 0;
    }
  }
  puts("YES");
  for (int i = 2; i <= m * 2; i += 2) {
    printf("%d", e[i].w);
  }
  return 0;
}