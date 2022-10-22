#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
char a[maxn][maxn];
int n, f[maxn][maxn][maxn][maxn];

inline void chkmin(int &x, int y) {
  if (x > y) x = y;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
    for (int j = 1; j <= n; j++) {
      f[i][j][i][j] = a[i][j] == '#';
    }
  }
  for (int p1 = 1; p1 <= n; p1++) {
    for (int p2 = 1; p2 <= n; p2++) {
      if (p1 == 1 && p2 == 1) continue;
      for (int x1 = 1; p1 + x1 - 1 <= n; x1++) {
        for (int y1 = 1; p2 + y1 - 1 <= n; y1++) {
          int x2 = p1 + x1 - 1;
          int y2 = p2 + y1 - 1;
          int &res = f[x1][y1][x2][y2];
          res = max(x2 - x1 + 1, y2 - y1 + 1);
          for (int i = x1; i < x2; i++) {
            chkmin(res, f[x1][y1][i][y2] + f[i + 1][y1][x2][y2]);
          }
          for (int i = y1; i < y2; i++) {
            chkmin(res, f[x1][y1][x2][i] + f[x1][i + 1][x2][y2]);
          }
        }
      }
    }
  }
  printf("%d", f[1][1][n][n]);
  return 0;
}