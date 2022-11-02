#include <stdio.h>
#include <string.h>

int main()
{
     int n, i;
     char s[11];
     char c[2][11];
     int a[2] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
      scanf("%s", s);

      if (a[0] == 0) {
           strcpy(c[0], s);

           a[0]++;
      } else {
           if (strcmp(s, c[0]) == 0) {
            a[0]++;
           } else {
            if (a[1] == 0) strcpy(c[1], s);

            a[1]++;
           }
      }
     }

     if (a[0] > a[1]) {
      printf("%s\n", c[0]);
     } else {
      printf("%s\n", c[1]);
     }

     return 0;
}