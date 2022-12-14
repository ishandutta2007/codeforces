#include <cstdio>

const int N = 100 + 10;

int n, m;

int main() {
  scanf("%d%d", &n, &m);
  static int val[N][N];
  for (int i = 1; i <= n; ++i) {
    static char s[N];
    scanf(" %s", s + 1);
    for (int j = 1; j <= m; ++j) val[i][j] = (s[j] == 'B' ? -1 : 1);
  }
  static int cur[N][N];
  int ans = 0;
  for (int i = n; i > 0; --i) {
    for (int j = m; j > 0; --j) {
      if (val[i][j] == cur[i][j]) continue;
      ++ans;
      int det = val[i][j] - cur[i][j];
      for (int x = 1; x <= i; ++x)
        for (int y = 1; y <= j; ++y)
          cur[x][y] += det;
    }
  }
  printf("%d\n", ans);
  return 0;
}