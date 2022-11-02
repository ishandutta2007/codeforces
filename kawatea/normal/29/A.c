#include <stdio.h>

int main()
{
     int n, i, j;
     int a[100][2];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);

     for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
           if (i == j) continue;

           if (a[i][0] + a[i][1] == a[j][0] && a[j][0] + a[j][1] == a[i][0]) {
            puts("YES");

            return 0;
           }
      }
     }

     puts("NO");

     return 0;
}