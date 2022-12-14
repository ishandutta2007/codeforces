#include <cstdio>
#include <cstring>
#include <bitset>

const int N = 23, M = 46;

int n, m;
int f[N][N][N][N];
char map[N][N];

bool pool[3 * N][N * N];

int dfs(int x1, int y1, int x2, int y2, int dep) {
  if (x1 > x2 || y1 > y2) return 0;
  int &res = f[x1][y1][x2][y2];
  if (~res) return res;
  const int size = (x2 - x1 + 1) * (y2 - y1 + 1) + 10;
  bool *flag = pool[dep];
  for (int i = 0; i < size; ++i) flag[i] = false;
  for (int i = x1; i <= x2; ++i) {
    for (int j = y1; j <= y2; ++j) {
      if (!map[i][j]) continue;
      int temp;
      if (map[i][j] == 'R')
        temp = (dfs(x1, y1, x2, j - 1, dep + 1) ^ dfs(x1, j + 1, x2, y2, dep + 1));
      else if (map[i][j] == 'L')
        temp = (dfs(x1, y1, i - 1, y2, dep + 1) ^ dfs(i + 1, y1, x2, y2, dep + 1));
      else
        temp = (dfs(x1, y1, i - 1, j - 1, dep + 1) ^ dfs(x1, j + 1, i - 1, y2, dep + 1) ^ dfs(i + 1, y1, x2, j - 1, dep + 1) ^ dfs(i + 1, j + 1, x2, y2, dep + 1));
      if (temp < size) flag[temp] = 1;
    }
  }
  for (int i = 0;; ++i) if (!flag[i]) return res = i;
}

int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(map, 0, sizeof map);
    static char all[M][M];
    memset(all, 0, sizeof all);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        scanf(" %c", &c);
        all[i + j][i - j + m] = c;
      }
    }
    memset(f, -1, sizeof f);
    memset(map, 0, sizeof map);
    int a = (n + m) / 2 + 1, b = a;
    for (int x = 0, i = 0; x <= n + m; x += 2, ++i)
      for (int y = m & 1, j = 0; y <= n + m; y += 2, ++j)
        map[i][j] = all[x][y];
    int ans = dfs(0, 0, a, b, 0);
    memset(f, -1, sizeof f);
    memset(map, 0, sizeof map);
    for (int x = 1, i = 0; x <= n + m; x += 2, ++i)
      for (int y = !(m & 1), j = 0; y <= n + m; y += 2, ++j)
        map[i][j] = all[x][y];
    ans ^= dfs(0, 0, a, b, 0);
    puts(ans ? "WIN" : "LOSE");
  }
  return 0;
}