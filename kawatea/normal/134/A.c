#include <stdio.h>

int main()
{
     int n, sum = 0, p = 0, i;
     int a[200001], b[200001];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &a[i]);

	  sum += a[i];
     }

     if (sum % n != 0) {
	  puts("0");
     } else {
	  sum /= n;

	  for (i = 0; i < n; i++) {
	       if (a[i] == sum) b[p++] = i + 1;
	  }

	  printf("%d\n", p);

	  for (i = 0; i < p; i++) {
	       if (i > 0) putchar(' ');

	       printf("%d", b[i]);
	  }

	  if (p > 0) puts("");
     }

     return 0;
}