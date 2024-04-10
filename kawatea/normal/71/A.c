#include <stdio.h>
#include <string.h>

int main()
{
     int n, i;
     char s[105];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%s", s);

	  if (strlen(s) > 10) {
	       printf("%c%d%c\n", s[0], strlen(s) - 2, s[strlen(s) - 1]);
	  } else {
	       printf("%s\n", s);
	  }
     }

     return 0;
}