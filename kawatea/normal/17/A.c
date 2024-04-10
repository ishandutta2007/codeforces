#include <stdio.h>

int main()
{
     int n, k, s = 0, i, j, l;
     int a[1001] = {0};

     a[0] = 1;
     a[1] = 1;
     for (i = 2; i <= 1000; i++) {
      if (a[i] == 0) {
           for (j = 2; i * j <= 1000; j++) a[i * j] = 1;
      }
     }

     scanf("%d %d", &n, &k);

     for (i = 2; i <= n; i++) {
      if (a[i] == 0) {
           for (j = 0; j <= (i - 1) / 2; j++) {
            if (a[j] == 0 && a[i - j - 1] == 0) {
             for (l = j + 1; l < i - j - 1; l++) {
                  if (a[l] == 0) break;
             }

             if (l == i - j - 1) s++;
            }
           }
      }
     }

     if (s >= k) {
      puts("YES");
     } else {
      puts("NO");
     }

     return 0;
}