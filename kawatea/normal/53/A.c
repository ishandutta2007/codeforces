#include <stdio.h>
#include <string.h>

int main()
{
     int n, f = 0, i;
     char s[101];
     char c[100][101];
     char ans[101];

     scanf("%s", s);
     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%s", c[i]);

     for (i = 0; i < n; i++) {
	  if (strncmp(s, c[i], strlen(s)) == 0) {
	       if (f == 0) {
		    strcpy(ans, c[i]);
		    f = 1;
	       } else {
		    if (strcmp(ans, c[i]) > 0) strcpy(ans, c[i]);
	       }
	  }
     }

     if (f == 0) {
	  printf("%s\n", s);
     } else {
	  printf("%s\n", ans);
     }

     return 0;
}