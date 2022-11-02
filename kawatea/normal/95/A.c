#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
     int n, i, j;
     char c[100][101];
     char s1[101], s2[101];
     char p[2], q;
     int a[100], b[100] = {0};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%s", c[i]);

	  for (j = 0; j < strlen(c[i]); j++) {
	       c[i][j] = tolower(c[i][j]);
	  }

	  a[i] = strlen(c[i]);
     }

     scanf("%s", s1);

     for (i = 0; i < strlen(s1); i++) {
	  s2[i] = tolower(s1[i]);
     }

     scanf("%s", p);

     if (p[0] == 'a') {
	  q = 'b';
     } else {
	  q = 'a';
     }

     for (i = 0; i < n; i++) {
	  char *x = &s2[0];

	  while (1) {
	       x = strstr(x, c[i]);

	       if (x == NULL) break;

	       for (j = x - &s2[0]; j < x - &s2[0] + a[i]; j++) b[j] = 1;

	       x++;
	  }
     }

     for (i = 0; i < strlen(s1); i++) {
	  if (b[i] == 1) {
	       if (s2[i] == p[0]) {
		    if (isupper(s1[i])) {
			 s1[i] = toupper(q);
		    } else {
			 s1[i] = q;
		    }
	       } else {
		    if (isupper(s1[i])) {
			 s1[i] = toupper(p[0]);
		    } else {
			 s1[i] = p[0];
		    }
	       }
	  }
     }

     printf("%s\n", s1);

     return 0;
}