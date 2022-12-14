#include <cstdio>

const int N = 150 + 10, M = 30 + 5;
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool ans[2 * N][2 * N];
bool flag[2 * N][2 * N][M][10];

int n, t[M];

void dfs(int x, int y, int a, int b) {
  if (a == n) return;
  if (flag[x][y][a][b]) return;
  flag[x][y][a][b] = true;
  for (int i = t[a]; i--;) ans[x += dx[b]][y += dy[b]] = true;
  int p = (b + 1) & 7, q = (b + 7) & 7;
  dfs(x, y, a + 1, p);
  dfs(x, y, a + 1, q);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
  dfs(N, N, 0, 0);
  int cnt = 0;
  for (int i = 0; i < 2 * N; ++i)
    for (int j = 0; j < 2 * N; ++j)
      cnt += ans[i][j];
  printf("%d\n", cnt);
  return 0;
}