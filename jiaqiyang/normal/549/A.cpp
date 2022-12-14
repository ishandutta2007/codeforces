#include <cstdio>

const int N = 50 + 10;

int n, m;
int mask[N][N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    static char s[N];
    scanf(" %s", s);
    for (int j = 0; j < m; ++j) {
      switch (s[j]) {
        case 'f':
          mask[i][j] = 1;
          break;
        case 'a':
          mask[i][j] = 2;
          break;
        case 'c':
          mask[i][j] = 4;
          break;
        case 'e':
          mask[i][j] = 8;
          break;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i + 1 < n; ++i)
    for (int j = 0; j + 1 < m; ++j)
      ans += (mask[i][j] | mask[i][j + 1] | mask[i + 1][j] | mask[i + 1][j + 1]) == 15;
  printf("%d\n", ans);
  return 0;
}