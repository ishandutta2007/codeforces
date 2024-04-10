#include <stdio.h>

int main()
{
     char s[3][4];
     int f = 0, i;

     for (i = 0; i < 3; i++) scanf("%s", s[i]);

     if (s[0][0] != s[2][2]) f = 1;
     if (s[0][1] != s[2][1]) f = 1;
     if (s[0][2] != s[2][0]) f = 1;
     if (s[1][0] != s[1][2]) f = 1;

     if (f == 0) {
      puts("YES");
     } else {
      puts("NO");
     }

     return 0;
}