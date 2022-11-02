#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, m, p = 0, x = 0, i;
     int a[10];
     char s[20];

     scanf("%d %s", &n, s);

     m = atoi(s);

     if (m > 0 && s[0] == '0') {
	  puts("WRONG_ANSWER");

	  return 0;
     }

     if (n == 0) {
	  if (m == 0 && s[1] == '\0') {
	       puts("OK");
	  } else {
	       puts("WRONG_ANSWER");
	  }

	  return 0;
     }

     while (n) {
	  a[p++] = n % 10;
	  n /= 10;
     }

     qsort(a, p, sizeof(int), cmp);

     if (a[0] == 0) {
	  for (i = 0; i < p; i++) {
	       if (a[i] > 0) {
		    a[0] = a[i];
		    a[i] = 0;

		    break;
	       }
	  }
     }

     for (i = 0; i < p; i++) {
	  x *= 10;
	  x += a[i];
     }

     if (x == m) {
	  puts("OK");
     } else {
	  puts("WRONG_ANSWER");
     }

     return 0;
}