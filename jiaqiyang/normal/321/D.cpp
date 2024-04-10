#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

const int N = 50 + 10, INF = 0x3f3f3f3f;

int n, x;
int a[N][N];

int col[N];

inline int sgn(int u) { return u ? -1 : 1; }

int mem[N][N][2][2][2];

int Test(int u, int v) {
  int w = v ^ col[x - 1], res = sgn(v) * a[u][x - 1] + sgn(w) * a[u + x][x - 1];
  for (int i = 0; i + 1 < x; ++i) {
    int &cur = mem[u][i][col[x - 1]][v][col[i]];
    if (cur != INF) {
      if (cur == -INF) return -INF;
      res += cur;
      continue;
    }
    static int temp[2];
    for (int p = 0; p < 2; ++p) {
      int q = p ^ v, r = p ^ col[i];
      if ((r ^ w) != (q ^ col[i + x])) {
        temp[p] = -INF;
        continue;
      }
      int s = r ^ w;
      temp[p] = sgn(p) * a[u][i];
      temp[p] += sgn(q) * a[u][i + x];
      temp[p] += sgn(r) * a[u + x][i];
      temp[p] += sgn(s) * a[u + x][i + x];
    }
    cur = std::max(temp[0], temp[1]);
    if (cur == -INF) return -INF;
    res += cur;
  }
  return res;
}

int Greedy(int s) {
  for (int i = 0; i < x; ++i) col[i] = (s >> i & 1);
  for (int i = x; i < n; ++i) col[i] = col[i - x] ^ col[x - 1];
  int res = 0;
  for (int i = 0; i < n; ++i) res += sgn(col[i]) * a[x - 1][i];
  for (int i = 0; i + 1 < x; ++i) {
    int t = std::max(Test(i, 0), Test(i, 1));
    if (t == -INF) return -INF;
    res += t;
  }
  return res;
}

int main() {
  memset(mem, 0x3f, sizeof mem);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &a[i][j]);
  x = (n + 1) / 2;
  int ans = -INF;
  for (int s = 0; s < (1 << x); ++s) ans = std::max(ans, Greedy(s));
  printf("%d\n", ans);
  return 0;
}