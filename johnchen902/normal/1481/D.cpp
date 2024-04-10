#include <algorithm>
#include <stdio.h>
#include <vector>

char s[1000][1001];

void solve(int n, int m) {
  for (int i = 0; i < n && i < 3; i++)
    for (int j = i + 1; j < n && j < 3; j++)
      if (s[i][j] == s[j][i]) {
        puts("YES");
        for (int k = 0; k <= m; k++)
          printf("%d%c", ((k & 1) ? i : j) + 1, k == m ? '\n' : ' ');
        return;
      }

  if (m % 2 == 1) {
    puts("YES");
    for (int k = 0; k <= m; k++)
      printf("%d%c", ((k & 1) ? 1 : 2), k == m ? '\n' : ' ');
    return;
  }

  if (n == 2) {
    puts("NO");
    return;
  }

  for (int i = 0; i < 3; i++) {
    int j = (i + 1) % 3;
    int k = (j + 1) % 3;
    if (s[i][j] == s[j][k]) {
      puts("YES");
      for (int l = 0; l <= m; l++) {
        int x;
        if (m % 4 == 2) {
          switch (l % 4) {
            case 0: x = i; break;
            case 1: x = j; break;
            case 2: x = k; break;
            case 3: x = j; break;
            default: __builtin_unreachable();
          }
        } else {
          switch (l % 4) {
            case 0: x = j; break;
            case 1: x = k; break;
            case 2: x = j; break;
            case 3: x = i; break;
            default: __builtin_unreachable();
          }
        }
        printf("%d%c", x + 1, l == m ? '\n' : ' ');
      }
      return;
    }
  }

  __builtin_unreachable();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%s", s[i]);
    solve(n, m);
  }
}