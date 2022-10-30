#include <stdio.h>

int main()
{
     int n, m, i;

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) {
	  int s, f, t;

	  scanf("%d %d %d", &s, &f, &t);

	  if (s == f) {
	       printf("%d\n", t);
	  } else if (s < f) {
	       int x = t % (2 * m - 2);
	       int y = t / (2 * m - 2);

	       if (x < s) {
		    printf("%d\n", y * (2 * m - 2) + f - 1);
	       } else {
		    printf("%d\n", (y + 1) * (2 * m - 2) + f - 1);
	       }
	  } else {
	       int x = t % (2 * m - 2);
	       int y = t / (2 * m - 2);

	       if (x < 2 * m - s) {
		    printf("%d\n", y * (2 * m - 2) + 2 * m - f - 1);
	       } else {
		    printf("%d\n", (y + 1) * (2 * m - 2) + 2 * m - f - 1);
	       }
	  }
     }

     return 0;
}