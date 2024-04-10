#include <stdio.h>

int main()
{
     int n, x, p = 0, i, j;
     int a[100000];
     char s[5];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%s", s);

	  if (s[0] == 's') {
	       long long sum = 0;

	       for (j = 2; j < p; j += 5) sum += a[j];

	       printf("%I64d\n", sum);
	  } else {
	       scanf("%d", &x);

	       if (s[0] == 'a') {
		    int l = -1, r = p, m = (l + r) / 2;

		    while (r - l > 1) {
			 if (a[m] > x) {
			      r = m;
			      m = (l + r) / 2;
			 } else {
			      l = m;
			      m = (l + r) / 2;
			 }
		    }

		    for (j = p; j > r; j--) a[j] = a[j - 1];

		    a[r] = x;

		    p++;
	       } else {
		    int l = -1, r = p, m = (l + r) / 2;

		    while (r - l > 1) {
			 if (a[m] > x) {
			      r = m;
			      m = (l + r) / 2;
			 } else if (a[m] == x) {
			      r = m;

			      break;
			 } else {
			      l = m;
			      m = (l + r) / 2;
			 }
		    }

		    for (j = r; j < p; j++) a[j] = a[j + 1];

		    p--;
	       }
	  }
     }

     return 0;
}