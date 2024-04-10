#include <stdio.h>
#include <string.h>

int main()
{
     char s[81];
     char c[10][11];
     int i, j;

     scanf("%s", s);

     for (i = 0; i < 10; i++) scanf("%s", c[i]);

     for (i = 0; i < 8; i++) {
	  for (j = 0; j < 10; j++) {
	       if (strncmp(&s[i * 10], c[j], 10) == 0) {
		    printf("%d", j);

		    break;
	       }
	  }
     }
     puts("");

     return 0;
}