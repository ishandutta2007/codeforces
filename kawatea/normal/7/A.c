#include <stdio.h>

int main()
{
     char s[8][9];
     int n = 0, i, j;

     for (i = 0; i < 8; i++) scanf("%s", s[i]);

     for (i = 0; i < 8; i++) {
	  for (j = 0; j < 8; j++) {
	       if (s[i][j] == 'W') break;
	  }

	  if (j == 8) {
	       for (j = 0; j < 8; j++) s[i][j] = 'W';

	       n++;
	  }
     }

     for (i = 0; i < 8; i++) {
	  for (j = 0; j < 8; j++) {
	       if (s[j][i] == 'B') break;
	  }

	  if (j < 8) n++;
     }

     printf("%d\n", n);

     return 0;
}