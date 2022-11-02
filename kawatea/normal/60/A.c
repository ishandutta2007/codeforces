#include <stdio.h>

int max(int a, int b)
{
     if (a > b) {
      return a;
     } else {
      return b;
     }
}

int min(int a, int b)
{
     if (a < b) {
      return a;
     } else {
      return b;
     }
}

int main()
{
     int n, m, l, r, x, i, j;
     char s[30];

     scanf("%d %d%*c", &n, &m);

     l = 1; r = n;

     for (i = 0; i < m; i++) {
      int f = 0;

      fgets(s, 30, stdin);

      if (s[7] == 'r') f = 1;

      for (j = 0; ; j++) {
           if (s[j] >= '0' && s[j] <= '9') break;
      }

      x = atoi(&s[j]);

      if (f == 0) {
           if (x <= l) {
            puts("-1");

            return 0;
           }

           r = min(r, x - 1);
      } else {
           if (x >= r) {
            puts("-1");

            return 0;
           }

           l = max(l, x + 1);
      }
     }

     printf("%d\n", r - l + 1);

     return 0;
}