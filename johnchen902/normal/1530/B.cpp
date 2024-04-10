#include <stdio.h>
#include <string.h>
#include <algorithm>

char s[20][21];

void check(int i, int j, int n, int m) {
  for (int ii = i - 1; ii <= i + 1; ii++)
    for (int jj = j - 1; jj <= j + 1; jj++)
      if (ii >= 0 && ii < n && jj >= 0 && jj < m && s[ii][jj] != '0')
        return;
  s[i][j] = '1';
}

void solve(int n, int m) {
  for (int i = 0; i < n; i++) {
    std::fill_n(s[i], m, '0');
    s[i][m] = '\0';
  }

  for (int i = 0; i < m; i++)
    check(0, i, n, m);
  for (int i = 0; i < n; i++)
    check(i, m - 1, n, m);
  for (int i = 0; i < m; i++)
    check(n - 1, m - 1 - i, n, m);
  for (int i = 0; i < n; i++)
    check(n - 1 - i, 0, n, m);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int h, w;
    scanf("%d%d", &h, &w);
    solve(h, w);
    for (int i = 0; i < h; i++)
      printf("%s\n", s[i]);
  }
}