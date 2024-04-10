#include <cstdio>
#include <cstring>
#include <vector>

typedef long long i64;

const int N = 5000 + 10;

inline void check(i64 &lhs, i64 rhs) { lhs = (lhs < rhs ? lhs : rhs); }

int n, m, fa[N], c[N], d[N];
std::vector<int> adj[N];

i64 f[N][N], g[N][N];

int dfs(int a) {
  f[a][0] = 0, f[a][1] = c[a];
  g[a][1] = c[a] - d[a];
  int res = 1;
  for (auto b : adj[a]) {
    int s = dfs(b);
    static i64 u[N], v[N];
    memset(u, 0x3f, (res + s + 1) * sizeof(i64));
    memset(v, 0x3f, (res + s + 1) * sizeof(i64));
    for (int i = 0; i <= res; ++i) {
      for (int j = 0; j <= s; ++j) {
        check(u[i + j], f[a][i] + f[b][j]);
        check(v[i + j], g[a][i] + std::min(f[b][j], g[b][j]));
      }
    }
    res += s;
    memcpy(f[a], u, (res + 1) * sizeof(i64));
    memcpy(g[a], v, (res + 1) * sizeof(i64));
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &c[i], &d[i]);
    if (i > 1) scanf("%d", &fa[i]), adj[fa[i]].push_back(i);
  }
  memset(f, 0x3f, sizeof f);
  memset(g, 0x3f, sizeof g);
  dfs(1);
  int ans = 0;
  for (int i = 0; i <= n; ++i) if (std::min(f[1][i], g[1][i]) <= m) ans = i;
  printf("%d\n", ans);
  return 0;
}