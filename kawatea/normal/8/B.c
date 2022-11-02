#include <stdio.h>
#include <string.h>

int main()
{
     char s[101];
     int a[205][205] = {0};
     int x = 102, y = 102, i;

     a[x][y] = 1;

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) {
	  int m;

	  switch(s[i]) {
	  case 'L' : x--; break;
	  case 'R' : x++; break;
	  case 'U' : y++; break;
	  case 'D' : y--; break;
	  }

	  if (a[x][y] == 1) {
	       puts("BUG");

	       return 0;
	  }

	  m = a[x - 1][y] + a[x + 1][y] + a[x][y - 1] + a[x][y + 1];

	  if (m > 1) {
	       puts("BUG");

	       return 0;
	  }

	  a[x][y] = 1;
     }

     puts("OK");

     return 0;
}