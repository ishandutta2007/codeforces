#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

const int maxn = 2e5 + 10;
int n, b[maxn], c[maxn];

int h[maxn], deg[maxn];

struct edges {
  int nxt, to;
} e[maxn];

void addline(int u, int v) {
  static int cnt = 1;
  e[++cnt] = edges{h[u], v}, h[u] = cnt, deg[u]++;
}

int tot, data[maxn];

void discretize() {
  rep(i, 1, n - 1) data[++tot] = b[i];
  rep(i, 1, n - 1) data[++tot] = c[i];
  sort(data + 1, data + tot + 1);
  tot = unique(data + 1, data + tot + 1) - data - 1;
  rep(i, 1, n - 1) {
    b[i] = lower_bound(data + 1, data + tot + 1, b[i]) - data;
    c[i] = lower_bound(data + 1, data + tot + 1, c[i]) - data;
  }
}

bool vis[maxn];
int now, path[maxn];

void dfs(int u) {
  for (int &i = h[u]; i; i = e[i].nxt) {
    if (!vis[i]) {
      vis[i ^ 1] = vis[i] = 1, dfs(e[i].to);
    }
  }
  path[++now] = data[u];
}

int main() {
  n = read();
  rep(i, 1, n - 1) b[i] = read();
  rep(i, 1, n - 1) c[i] = read();
  discretize();
  rep(i, 1, n - 1) {
    if (b[i] > c[i]) {
      return puts("-1"), 0;
    }
    int u = b[i], v = c[i];
    addline(u, v), addline(v, u);
  }
  int start = 1, cnt = 0;
  rep(i, 1, tot) {
    if (deg[i] & 1) {
      start = i, cnt++;
    }
  }
  if (cnt != 0 && cnt != 2) {
    return puts("-1"), 0;
  }
  dfs(start);
  if (now != n) {
    return puts("-1"), 0;
  }
  rep(i, 1, now) printf("%d ", path[i]);
  return 0;
}