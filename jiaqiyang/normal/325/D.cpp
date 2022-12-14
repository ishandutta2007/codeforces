#include <cstdio>
#include <cstring>
#include <vector>

const int N = 3000 + 10, SZ = 8;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;

int anc[N * N * 2], tag[N * N * 2];
bool flag[N][N * 2];

inline int pos(int x, int y) { return x * m * 2 + y; }

inline int Find(int p) { return anc[p] == p ? p : (anc[p] = Find(anc[p])); }

inline void Union(int u, int v) {
  u = Find(u), v = Find(v);
  if (u != v) anc[u] = v;
}

int main() {
  scanf("%d%d", &n, &m);
  if (m == 1) {
    puts("0");
    return 0;
  }
  int tcase;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < 2 * m; ++y) {
      int p = pos(x, y);
      anc[p] = p;
    }
  }
  memset(tag, 0x3f, sizeof tag);
  int ans = 0;
  for (scanf("%d", &tcase); tcase--;) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    for (int k = 0; k < SZ; ++k) {
      int a = x + dx[k], b = (y + dy[k] + 2 * m) % (2 * m);
      if (0 <= a && a < n && flag[a][b]) tag[Find(pos(a, b))] = tcase;
    }
    bool cur = true;
    for (int k = 0; k < SZ; ++k) {
      int a = x + dx[k], b = (y + dy[k] + 3 * m) % (2 * m);
      if (0 <= a && a < n && flag[a][b]) cur &= (tag[Find(pos(a, b))] != tcase);
    }
    if (cur) {
      ++ans;
      flag[x][y] = flag[x][y + m] = true;
      for (int gap = 0; gap <= m; gap += m) {
        for (int k = 0; k < SZ; ++k) {
          int a = x + dx[k], b = (y + dy[k] + gap + 2 * m) % (2 * m);
          if (0 <= a && a < n && flag[a][b]) Union(pos(x, y + gap), pos(a, b));
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}