#include <cstdio>
#include <algorithm>

#define fst first
#define snd second

typedef std::pair<int, int> Info;

const int N = 1000000 + 10, E = 4 * N;

int adj[N], to[E], next[E];

inline void link(int a, int b) {
  static int cnt = 2;
  to[cnt] = b;
  next[cnt] = adj[a];
  adj[a] = cnt++;
}

int n, m, s, a[N];

int anc[N], size[N];

int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

void meld(int x, int y) {
  x = find(x), y = find(y);
  if (size[x] > size[y]) std::swap(x, y);
  anc[x] = y;
  size[y] += size[x];
}

int main() {
  scanf("%d%d", &n, &m);
  s = n * m;
  for (int i = 0; i < s; ++i) scanf("%d", &a[i]);
  static Info sorted[N];
  for (int i = 0; i < n * m; ++i) anc[i] = i, size[i] = 1;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < m; ++j) sorted[++cnt] = Info(a[i * m + j], i * m + j);
    std::sort(sorted + 1, sorted + cnt + 1);
    for (int j = 2; j <= cnt; ++j) if (sorted[j].fst == sorted[j - 1].fst) meld(sorted[j - 1].snd, sorted[j].snd);
  }
  for (int j = 0; j < m; ++j) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) sorted[++cnt] = Info(a[i * m + j], i * m + j);
    std::sort(sorted + 1, sorted + cnt + 1);
    for (int i = 2; i <= cnt; ++i) if (sorted[i].fst == sorted[i - 1].fst) meld(sorted[i - 1].snd, sorted[i].snd);
  }
  static int deg[N];
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < m; ++j) sorted[++cnt] = Info(a[i * m + j], i * m + j);
    std::sort(sorted + 1, sorted + cnt + 1);
    for (int j = 2; j <= cnt; ++j) {
      if (sorted[j].fst != sorted[j - 1].fst) {
        int u = find(sorted[j - 1].snd), v = find(sorted[j].snd);
        link(u, v);
        ++deg[v];
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) sorted[++cnt] = Info(a[i * m + j], i * m + j);
    std::sort(sorted + 1, sorted + cnt + 1);
    for (int i = 2; i <= cnt; ++i) {
      if (sorted[i].fst != sorted[i - 1].fst) {
        int u = find(sorted[i - 1].snd), v = find(sorted[i].snd);
        link(u, v);
        ++deg[v];
      }
    }
  }
  static int ans[N], q[N];
  int r = 0;
  for (int i = 0; i < n * m; ++i) if (!deg[i] && find(i) == i) ans[q[++r] = i] = 1;
  for (int f = 1; f <= r; ++f) {
    int a = q[f];
    for (int i = adj[a]; i; i = next[i]) {
      int b = to[i];
      if (--deg[b] == 0) ans[q[++r] = b] = ans[a] + 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) printf("%d ", ans[find(i * m + j)]);
    puts("");
  }
  return 0;
}