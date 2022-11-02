#include <stdio.h>

int main()
{
     int n, m = 1e9, i;

     scanf("%d", &n);

     for (i = 1; i <= n; i++) {
	  int p = n, q = i, c = 0;

	  while (1) {
	       if (p == q) {
		    if (p > 1) c = -1;

		    break;
	       }

	       if (p > q) {
		    if (q == 1) {
			 c += p - 1;

			 break;
		    }

		    p -= q;
	       } else {
		    if (p == 1) {
			 c += q - 1;

			 break;
		    }

		    q -= p;
	       }

	       c++;
	  }

	  if (c >= 0 && c < m) m = c;
     }

     printf("%d\n", m);

     return 0;
}