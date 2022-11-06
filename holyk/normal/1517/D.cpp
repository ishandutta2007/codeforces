#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;
const std::array<int, 2> D[] = {
  {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

int n, m, k;
int e[505][505][4];
int bd[22][505][505], sd[22][505][505];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      int x;
      std::cin >> x;
      e[i][j][3] = e[i][j + 1][1] = x;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      std::cin >> x;
      e[i][j][2] = e[i + 1][j][0] = x;
    }
  }
  memset(bd, 0x3f, sizeof bd);
  memset(bd[0], 0, sizeof bd[0]);
  for (int f = 2; f <= k; f += 2) {
    // memset(sd[f], 0x3f, sizeof sd[f]);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int u = 0; u < 4; u++) {
          int tx = D[u][0] + i, ty = D[u][1] + j;
          if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
          if (f >= 2) smin(bd[f][i][j], bd[f - 2][tx][ty] + 2 * e[i][j][u]);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int t = bd[k][i][j];
      std::cout << (t >= 1e9 ? - 1 : t) << " \n"[j == m];
    }
  }
  return 0;
}