#include <stdio.h>
#include <string.h>

int main()
{
     char s[101], c[101];
     int p = 0, f = 0, i;

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) {
	  if (p > 0 && f == 0 && strncmp(&s[i], "at", 2) == 0) {
	       c[p++] = '@';

	       i++;

	       f = 1;
	  } else if (p > 0 && strncmp(&s[i], "dot", 3) == 0) {
	       c[p++] = '.';

	       i += 2;
	  } else {
	       c[p++] = s[i];
	  }
     }

     if (c[p - 1] == '.') {
	  c[p - 1] = 'd';
	  c[p] = 'o';
	  c[p + 1] = 't';

	  p += 2;
     }

     c[p] = '\0';

     printf("%s\n", c);

     return 0;
}