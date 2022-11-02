#include <stdio.h>

int main()
{
     int n, m, sum = 0, i, j;
     int l[100], r[100], t[100], c[100];

     scanf("%d %d", &n, &m);

     for (i = 0; i < m; i++) {
	  scanf("%d %d %d %d", &l[i], &r[i], &t[i], &c[i]);
     }

     for (i = 1; i <= n; i++) {
	  int min = 2000, num = 200;

	  for (j = 0; j < m; j++) {
	       if (l[j] <= i && r[j] >= i) {
		    if (t[j] < min) {
			 min = t[j]; num = j;
		    }
	       }
	  }

	  if (num < 200) sum += c[num];
     }

     printf("%d\n", sum);

     return 0;
}