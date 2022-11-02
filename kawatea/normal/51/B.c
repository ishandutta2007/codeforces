#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     int n, p = 0, q = 0, i, j;
     char c[10][5001];
     char s[5001] = "";
     int a[5000] = {0};
     int b[5000];

     for (i = 0; i < 10; i++) {
	  if (scanf("%s", c[i]) == EOF) break;
     }

     n = i;

     for (i = 0; i < n; i++) strcat(s, c[i]);

     for (i = 0; i < strlen(s); i++) {
	  char ss[10];

	  for (j = i; ; j++) {
	       ss[j - i] = s[j];

	       if (s[j] == '>') break;
	  }

	  ss[j - i + 1] = '\0';

	  if (strcmp(ss, "<table>") == 0) {
	       p++;
	  } else if (strcmp(ss, "</table>") == 0) {
	       b[q++] = a[p];
	       a[p--] = 0;
	  } else if (strcmp(ss, "</td>") == 0) {
	       a[p]++;
	  }

	  i = j;
     }

     qsort(b, q, sizeof(int), cmp);

     for (i = 0; i < q; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", b[i]);
     }
     puts("");

     return 0;
}