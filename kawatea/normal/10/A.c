#include <stdio.h>

int main()
{
     int n, p1, p2, p3, t1, t2, sum = 0, i;
     int l[100], r[100];

     scanf("%d %d %d %d %d %d", &n, &p1, &p2, &p3, &t1, &t2);

     for (i = 0; i < n; i++) {
      scanf("%d %d", &l[i], &r[i]);

      sum += (r[i] - l[i]) * p1;
     }

     for (i = 0; i < n - 1; i++) {
      int x = l[i + 1] - r[i];

      if (x > t1) {
           sum += p1 * t1;
           x -= t1;
      } else {
           sum += p1 * x;
           continue;
      }

      if (x > t2) {
           sum += p2 * t2;
           x -= t2;
      } else {
           sum += p2 * x;
           continue;
      }

      sum += p3 * x;
     }

     printf("%d\n", sum);

     return 0;
}