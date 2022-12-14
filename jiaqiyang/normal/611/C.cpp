#include <cstdio>

const int N = 500 + 10;

int n, m;

char map[N][N];
int cnt[2][N][N];

inline int query(int id, int l, int r, int p, int q) {
  if (l > r || p > q) return 0;
  return cnt[id][r][q] - cnt[id][l - 1][q] - cnt[id][r][p - 1] + cnt[id][l - 1][p - 1];
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%s", map[i] + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cnt[0][i][j] = (map[i][j] == '.' && map[i + 1][j] == '.');
      cnt[1][i][j] = (map[i][j] == '.' && map[i][j + 1] == '.');
    }
  }
  for (int id = 0; id < 2; ++id)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        cnt[id][i][j] += cnt[id][i - 1][j] + cnt[id][i][j - 1] - cnt[id][i - 1][j - 1];
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &c, &b, &d);
    printf("%d\n", query(0, a, b - 1, c, d) + query(1, a, b, c, d - 1));
  }
  return 0;
}