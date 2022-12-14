#include <cctype>
#include <stdio.h>
#include <algorithm>

const int N = 1000 + 10, S = 12;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, m, a[N][N], sum[N][N];

int query(int x1, int x2, int y1, int y2) {
  return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

bool query(int x, int y, int z) {
  return query(x, x + z - 1, y, y + z - 1) == z * z;
}

int f[N][N];

int mem[N];
short dp[N][N][S][S];

void init() {
  mem[0] = -1;
  for (int i = 1; i < N; ++i) mem[i] = 31 - __builtin_clz(i);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      dp[i][j][0][0] = f[i][j];
  for (int i = 0; i <= mem[n]; ++i) {
    for (int x = 1; x + (1 << i) - 1 <= n; ++x) {
      for (int j = 0; j <= mem[m]; ++j) {
        if (!i && !j) continue;
        for (int y = 1; y + (1 << j) - 1 <= m; ++y) {
          if (i)
            dp[x][y][i][j] = std::max(dp[x][y][i - 1][j], dp[x + (1 << (i - 1))][y][i - 1][j]);
          else
            dp[x][y][i][j] = std::max(dp[x][y][i][j - 1], dp[x][y + (1 << (j - 1))][i][j - 1]);
        }
      }
    }
  }
}

int rmq(int x1, int y1, int x2, int y2) {
  int k1 = mem[x2 - x1 + 1], k2 = mem[y2 - y1 + 1];
  x2 = x2 - (1 << k1) + 1;
  y2 = y2 - (1 << k2) + 1;
  return std::max(std::max(dp[x1][y1][k1][k2], dp[x1][y2][k1][k2]), std::max(dp[x2][y1][k1][k2], dp[x2][y2][k1][k2]));
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      a[i][j] = nextInt();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int l = 0, r = std::min(n - i + 1, m - j + 1);
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (query(i, j, mid)) l = mid; else r = mid - 1;
      }
      f[i][j] = l;
    }
  }
  init();
  for (int tcase = nextInt(); tcase--;) {
    int x1 = nextInt();
    int y1 = nextInt();
    int x2 = nextInt();
    int y2 = nextInt();
    int l = 0, r = std::min(x2 - x1 + 1, y2 - y1 + 1);
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (rmq(x1, y1, x2 - mid + 1, y2 - mid + 1) >= mid) l = mid; else r = mid - 1;
    }
    printf("%d\n", l);
  }
  return 0;
}