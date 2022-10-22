#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int n, m, pos[19][maxn];

inline void chkmax(int &x, int y) {
  if (x < y) x = y;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    chkmax(pos[0][x], y);
  }
  for (int i = 1; i < 500001; i++) {
    chkmax(pos[0][i], pos[0][i - 1]);
  }
  for (int i = 1; i < 19; i++) {
    for (int j = 0; j < 500001; j++) {
      pos[i][j] = pos[i - 1][pos[i - 1][j]];
    }
  }
  while (m--) {
    int l, r, ans = 0;
    scanf("%d %d", &l, &r);
    for (int i = 18; ~i; i--) {
      if (pos[i][l] < r) {
        ans |= 1 << i, l = pos[i][l];
      }
    }
    printf("%d\n", ans < n ? ans + 1 : -1);
  }
  return 0;
}