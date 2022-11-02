#include <stdio.h>

int main()
{
     int n, m, i, j;
     char c = 'a';
     char s[100][101];

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%s", s[i]);

     for (i = 0; i < n; i++) {
      if (s[i][0] == c) {
           puts("NO");

           return 0;
      }

      for (j = 0; j < m - 1; j++) {
           if (s[i][j] != s[i][j + 1]) {
            puts("NO");

            return 0;
           }
      }

      c = s[i][0];
     }

     puts("YES");

     return 0;
}