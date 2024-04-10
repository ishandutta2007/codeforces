#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 200000 + 10;

int n;
std::vector<int> adj[N];

int dep[N], anc[21][N], *fa = anc[0];

int lca(int x, int y) {
  if (dep[x] < dep[y]) std::swap(x, y);
  for (int i = 20; i >= 0; --i) if (dep[anc[i][x]] >= dep[y]) x = anc[i][x];
  if (x == y) return x;
  for (int i = 20; i >= 0; --i) if (anc[i][x] != anc[i][y]) x = anc[i][x], y = anc[i][y];
  return fa[x];
}

inline int dist(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }

struct Info {
  int x, y, z;
  Info() {}
  Info(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
  inline bool operator< (const Info &rhs) const { return z < rhs.z; }
};

int main() {
  scanf("%d", &n);
  dep[1] = 1;
  for (int i = 2; i <= n; ++i) scanf("%d", &fa[i]), dep[i] = dep[fa[i]] + 1;
  for (int i = 1; i < 21; ++i)
    for (int j = 1; j <= n; ++j)
      anc[i][j] = anc[i - 1][anc[i - 1][j]];
  Info cur(1, 1, 0);
  for (int i = 2; i <= n; ++i) {
    Info p(cur.x, i, dist(cur.x, i));
    Info q(cur.y, i, dist(cur.y, i));
    cur = std::max(cur, std::max(p, q));
    printf("%d ", cur.z);
  }
  return 0;
}