#include <stdio.h>
#include <string.h>

int main()
{
     char s[100001];
     char c1[101], c2[101];
     char *c;
     int n, f1 = 0, f2 = 0, i;

     scanf("%s %s %s", s, c1, c2);

     c = strstr(s, c1);

     if (c != NULL) {
	  c = strstr(c + strlen(c1), c2);

	  if (c != NULL) f1 = 1;
     }

     n = strlen(s);

     for (i = 0; i < n / 2; i++) {
	  char tmp = s[i];
	  s[i] = s[n - i - 1];
	  s[n - i - 1] = tmp;
     }

     c = strstr(s, c1);

     if (c != NULL) {
	  c = strstr(c + strlen(c1), c2);

	  if (c != NULL) f2 = 1;
     }

     if (f1 == 0) {
	  if (f2 == 0) {
	       puts("fantasy");
	  } else {
	       puts("backward");
	  }
     } else {
	  if (f2 == 0) {
	       puts("forward");
	  } else {
	       puts("both");
	  }
     }

     return 0;
}