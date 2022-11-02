#include <stdio.h>

int main()
{
     char s[100][2][15];
     int n, i;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
      scanf("%s %s", s[i][0], s[i][1]);

      if (s[i][1][0] == 'r') printf("%s\n", s[i][0]);
     }

     for (i = 0; i < n; i++) {
      if (s[i][1][0] == 'w' || (s[i][1][0] == 'c' && s[i][1][1] == 'h')) {
           printf("%s\n", s[i][0]);
      }
     }

     for (i = 0; i < n; i++) {
      if (s[i][1][0] == 'm') printf("%s\n", s[i][0]);
     }

     for (i = 0; i < n; i++) {
      if (s[i][1][0] == 'c' && s[i][1][1] == 'a') printf("%s\n", s[i][0]);
     }

     return 0;
}