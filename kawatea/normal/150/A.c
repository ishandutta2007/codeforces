#include <stdio.h>

int main()
{
     long long n, i;
     int p = 0, f = 0;
     long long a[10000][2] = {0};

     scanf("%I64d", &n);

     for (i = 2; i * i <= n; i++) {
	  if (n % i == 0) {
	       a[p][0] = i;

	       while (n % i == 0) {
		    a[p][1]++;
		    n /= i;
	       }

	       if (a[p][1] > 1) f = 1;

	       p++;
	  }
     }

     if (n > 1) {
	  a[p][0] = n;
	  a[p++][1] = 1;
     }

     if (p == 1) {
	  if (a[0][1] == 1) {
	       printf("1\n0\n");
	  } else if (a[0][1] == 2) {
	       puts("2");
	  } else {
	       printf("1\n%I64d\n", a[0][0] * a[0][0]);
	  }
     } else if (p == 2) {
	  if (f == 0) {
	       puts("2");
	  } else {
	       printf("1\n%I64d\n", a[0][0] * a[1][0]);
	  }
     } else {
	  printf("1\n%I64d\n", a[0][0] * a[1][0]);
     }

     return 0;
}