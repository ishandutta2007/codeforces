#include <stdio.h>
#include <string.h>

int main()
{
     int n, num = 0, i, j;
     char s[100][11], c[100][11];
     int f[100] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%s %s", s[i], c[i]);

     for (i = 0; i < n; i++) {
	  if (f[i] == 1) continue;

	  for (j = i + 1; j < n; j++) {
	       if (strcmp(s[i], s[j]) == 0 && strcmp(c[i], c[j]) == 0) f[j] = 1;
	  }

	  num++;
     }

     printf("%d\n", num);

     return 0;
}