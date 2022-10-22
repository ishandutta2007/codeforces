#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;
int n, m;
char a[maxn][maxn];

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool check(int x, int y) {
  static bool flg[maxn][maxn];
  for (int k = 0; k < 4; k++) {
    int i = x, j = y;
    while (i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] == '*') {
      flg[i][j] = 1, i += dx[k], j += dy[k];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!flg[i][j] && a[i][j] == '*') {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.') continue;
      bool f = 1;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        f &= x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '*';
      }
      if (!f) continue;
      if (check(i, j)) {
        return puts("YES"), 0;
      } else {
        return puts("NO"), 0;
      }
    }
  }
  puts("NO");
  return 0;
}