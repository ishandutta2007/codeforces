#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Pair;

const int N = 100000 + 10, M = 5000 + 10;

int n, m, a[N];

struct Info {
  int l, r;
  double p;
  inline bool operator< (const Info &rhs) const {
    return l < rhs.l || (l == rhs.l && r > rhs.r);
  }
} info[N];

std::vector<int> adj[M];

int fa[N], g[N], dep[N];
double f[M][M];

void build() {
  static int q[N];
  int r = 1;
  q[1] = 0;
  for (int i = 1; i <= m; ++i) {
    while (r && info[q[r]].r < info[i].l) --r;
    adj[fa[i] = q[r]].push_back(i);
    q[++r] = i;
  }
}

int anc[N];

int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

void dfs(int a) {
  dep[a] = 1;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    dfs(b);
    g[a] = std::max(g[a], g[b]);
    dep[a] = std::max(dep[a], dep[b] + 1);
  }
  for (int i = find(info[a].l); i <= info[a].r; i = find(i + 1)) {
    g[a] = std::max(g[a], ::a[i]);
    anc[find(i)] = find(info[a].r + 1);
  }
}

void solve(int a) {
  f[a][0] = 1.;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    solve(b);
    for (int j = 1; j <= dep[a]; ++j) f[a][j] += f[a][j - 1];
    for (int j = 1; j <= dep[b]; ++j) f[b][j] += f[b][j - 1];
    for (int j = 0; j <= dep[a]; ++j) f[a][j] *= f[b][std::min(dep[b], g[a] + j - g[b])];
    for (int j = dep[a]; j > 0; --j) f[a][j] -= f[a][j - 1];
  }
  for (int i = dep[a]; i > 0; --i) f[a][i] = f[a][i] * (1. - info[a].p) + f[a][i - 1] * info[a].p;
  f[a][0] *= (1. - info[a].p);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  info[0].l = 1, info[0].r = n, info[0].p = 0.;
  for (int i = 1; i <= m; ++i) scanf("%d%d%lf", &info[i].l, &info[i].r, &info[i].p);
  std::sort(info, info + m + 1);
  build();
  for (int i = 1; i <= n + 1; ++i) anc[i] = i;
  dfs(0);
  solve(0);
  double ans = g[0];
  for (int i = 1; i <= dep[0]; ++i) ans += i * f[0][i];
  printf("%.12f\n", ans);
  return 0;
}