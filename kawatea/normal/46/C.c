#include <stdio.h>

int main()
{
     int n, min = 10000, i;
     char s[2001];

     scanf("%d", &n);
     scanf("%s", s);

     for (i = 0; i < n; i++) {
	  int p = i, q, sum = 0;

	  for (q = n + i - 1; q >= p; q--) {
	       if (s[q] != s[i]) break;
	  }

	  while (1) {
	       for (; p < q; p++) {
		    if (s[p] != s[i]) break;
	       }

	       for (; q > p; q--) {
		    if (s[q] == s[i]) break;
	       }

	       if (p < q) {
		    p++;
		    q--;

		    sum++;
	       } else {
		    break;
	       }
	  }

	  if (sum < min) min = sum;

	  s[n + i] = s[i];
     }

     printf("%d\n", min);

     return 0;
}