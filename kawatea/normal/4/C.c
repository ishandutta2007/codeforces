#include <stdio.h>
#include <string.h>

char c[100000][33];

int main()
{
     int n, p = 0, i, j;
     int a[100000] = {0};
     char s[33];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%s", s);

	  for (j = 0; j < p; j++) {
	       if (strcmp(s, c[j]) == 0) {
		    a[j]++;
		    printf("%s%d\n", s, a[j]);

		    break;
	       }
	  }

	  if (j == p) {
	       strcpy(c[p++], s);

	       puts("OK");
	  }
     }

     return 0;
}