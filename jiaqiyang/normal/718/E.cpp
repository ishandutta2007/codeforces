#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10, S = 8, INF = 0x3f3f3f3f;

int n;
char s[N];

int f[S][N];

void bfs(int c) {
  static int q[N + S], g[N];
  memset(g, 0x3f, sizeof g);
  g[c] = -1;
  q[1] = -c;
  for (int i = 1, r = 1; i <= r; ++i) {
    int x = q[i];
    if (x > 0) {
      int v = f[c][x];
      for (int j = -1; j <= 1; ++j) {
        int y = x + j;
        if (0 < y && y <= n) {
          if (f[c][y] == INF) f[c][q[++r] = y] = v + 1;
          if (g[s[y]] == INF) g[s[y]] = v + 1, q[++r] = -s[y];
        }
      }
    } else {
      x = -x;
      for (int j = 1; j <= n; ++j) if (s[j] == x && f[c][j] == INF) f[c][q[++r] = j] = g[x] + 1;
    }
  }
}

int g[S][S];

int mask[N];

int p;
i64 q;

inline void update(int x, int y) {
  if (!y) return;
  if (x > p) p = x, q = y; else if (x == p) q += y;
}

void solve() {
  static int cnt[S][1 << S];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < S && i - j > 0; ++j) {
      int d = j;
      for (int c = 0; c < S; ++c) d = std::min(d, f[c][i] + f[c][i - j] + 1);
      update(d, 1);
    }
    int j = i - S;
    if (j > 0) {
      ++cnt[s[j]][mask[j]];
      for (int a = 0; a < S; ++a) {
        for (int b = 0; b < (1 << S); ++b) {
          if (!cnt[a][b]) continue;
          int d = N;
          for (int c = 0; c < S; ++c) d = std::min(d, f[c][i] + g[a][c] + 1 + (b >> c & 1));
          update(d, cnt[a][b]);
        }
      }
    }
  }
}

int main() {
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i <= n; ++i) s[i] -= 'a';
  memset(f, 0x3f, sizeof f);
  for (int i = 0; i < S; ++i) bfs(i);
  memset(g, 0x3f, sizeof g);
  for (int j = 0; j < S; ++j)
    for (int i = 1; i <= n; ++i)
      g[s[i]][j] = std::min(g[s[i]][j], f[j][i]);
  for (int j = 0; j < S; ++j)
    for (int i = 1; i <= n; ++i)
      mask[i] |= (f[j][i] - g[j][s[i]]) << j;
  solve();
  std::reverse(s + 1, s + n + 1);
  std::reverse(mask + 1, mask + n + 1);
  for (int i = 0; i < S; ++i) std::reverse(f[i] + 1, f[i] + n + 1);
  solve();
  printf("%d %lld\n", p, q / 2);
  return 0;
}