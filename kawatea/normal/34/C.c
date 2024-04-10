#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
     char s[1000];
     int a[1000] = {0};
     int f = 0, i, j;

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) {
	  int x = atoi(&s[i]);

	  a[x - 1]++;

	  while (s[i] >= '0' && s[i] <= '9') i++;
     }

     for (i = 0; i < 1000; i++) {
	  if (a[i] == 0) continue;

	  if (f == 1) putchar(',');

	  for (j = i + 1; j < 1000; j++) {
	       if (a[j] == 0) break;
	  }

	  if (i + 1 == j) {
	       printf("%d", i + 1);
	  } else {
	       printf("%d-%d", i + 1, j);
	  }

	  f = 1;

	  i = j;
     }
     puts("");

     return 0;
}