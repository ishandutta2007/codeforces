#include <stdio.h>

int main()
{
     char s[3][10];
     int i;
     int a[3];

     for (i = 0; i < 3; i++) {
	  scanf("%s", s[i]);

	  if (s[i][0] == 'r') {
	       a[i] = 0;
	  } else if (s[i][0] == 'p') {
	       a[i] = 1;
	  } else {
	       a[i] = 2;
	  }
     }

     if ((a[0] == 0 && a[1] == 2 && a[2] == 2) || (a[0] == 1 && a[1] == 0 && a[2] == 0) || (a[0] == 2 && a[1] == 1 && a[2] == 1)) {
	  puts("F");
     } else if ((a[0] == 0 && a[1] == 1 && a[2] == 0) || (a[0] == 1 && a[1] == 2 && a[2] == 1) || (a[0] == 2 && a[1] == 0 && a[2] == 2)) {
	  puts("M");
     } else if ((a[0] == 0 && a[1] == 0 && a[2] == 1) || (a[0] == 1 && a[1] == 1 && a[2] == 2) || (a[0] == 2 && a[1] == 2 && a[2] == 0)) {
	  puts("S");
     } else {
	  puts("?");
     }

     return 0;
}