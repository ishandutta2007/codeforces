#include <cstdio>
#include <iostream>
using namespace std;
const int n = 8;
char s[n][n + 1];
char solve() {
  for (int i = 0; i < n; i++)
    if (s[i][0] == 'R') {
      bool flg = true;
      for (int j = 1; j < n; j++)
        if (s[i][j] != s[i][0]) flg = false;
      if (flg) return s[i][0];
    }
  for (int i = 0; i < n; i++)
    if (s[0][i] == 'B') {
      bool flg = true;
      for (int j = 1; j < n; j++)
        if (s[j][i] != s[0][i]) flg = false;
      if (flg) return s[0][i];
    }
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    printf("%c\n", solve());
  }
  return 0;
}