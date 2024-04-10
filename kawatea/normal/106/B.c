#include <stdio.h>

int main()
{
     int n, min = 10000, num = 0, i, j;
     int s[100], r[100], h[100], c[100], t[100] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d %d %d %d", &s[i], &r[i], &h[i], &c[i]);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < n; j++) {
	       if (s[i] < s[j] && r[i] < r[j] && h[i] < h[j]) {
		    t[i] = 1;

		    break;
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  if (t[i] == 0) {
	       if (c[i] < min) {
		    min = c[i];
		    num = i;
	       }
	  }
     }

     printf("%d\n", num + 1);

     return 0;
}