//This problem can't be more strange!!
#include <bits/stdc++.h>
const int N = 512;
int n, m;
char s[N][N];
int main() {
  int test; scanf("%d", &test);
  while(test --) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
    if(m == 1) {
      for(int i = 1; i <= n; i ++)
        puts("X");
      continue ;
    }
    for(int j = 2; j <= m; j += 3) {
      for(int i = 1; i <= n; i ++) s[i][j] = 'X';
      if(j > 2) {
        bool tag = 0;
        int row = 1;
        for(int i = 1; i <= n; i ++) {
          if(s[i][j - 1] == 'X' && s[i][j - 2] == 'X') {
            tag = 1; break ;
          }
          if(s[i][j - 1] == 'X' || s[i][j - 2] == 'X') {
            row = i;
          }
        }
        if(!tag) s[row][j - 2] = s[row][j - 1] = 'X';
      }
    }
    if(m % 3 == 1) {
      for(int i = 1; i <= n; i ++)
        if(s[i][m] == 'X') s[i][m - 1] = 'X';
    }
    for(int i = 1; i <= n; i ++)
      puts(s[i] + 1);
  }
  return 0;
}