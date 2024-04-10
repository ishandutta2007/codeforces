#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int n, m, a[maxn], f[maxn][3][3];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x), a[x]++;
  }
  for (int i = 1; i <= m; i++) {
    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
          if (x + y + z <= a[i] && x + y <= a[i + 1] && x <= a[i + 2]) {
            f[i][x][y] = max(f[i][x][y], f[i - 1][y][z] + x + (a[i] - x - y - z) / 3);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ans = max(ans, f[m][i][j]);
    }
  }
  printf("%d", ans);
  return 0;
}