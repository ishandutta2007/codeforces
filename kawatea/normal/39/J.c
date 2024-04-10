#include <stdio.h>
#include <string.h>

int main()
{
     char s1[1000001], s2[1000001];
     int n, p = 0, q, i;

     scanf("%s %s", s1, s2);

     n = strlen(s2);

     for (i = 0; i < n; i++) {
	  if (s1[i] != s1[p]) p = i;

	  if (s1[i] != s2[i]) break;
     }

     q = i;

     if (i == n) {
	  if (s1[p] != s1[i]) p = i;
     }

     for (; i < n; i++) {
	  if (s1[i + 1] != s2[i]) break;
     }

     if (i < n) {
	  puts("0");
     } else {
	  printf("%d\n", q - p + 1);

	  for (i = p; i <= q; i++) {
	       if (i > p) putchar(' ');
	       printf("%d", i + 1);
	  }

	  puts("");
     }

     return 0;
}