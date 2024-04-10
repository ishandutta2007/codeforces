#include <stdio.h>

int main()
{
     int n, x = 0, y = 0, i;
     char s[1001];

     scanf("%d", &n);
     scanf("%s", s);

     for (i = 0; i < n; i++) {
	  if (s[i] == '0') {
	       if (i % 2 == 0) {
		    x++;
	       } else {
		    y++;
	       }
	  } else {
	       if (i % 2 == 0) {
		    y++;
	       } else {
		    x++;
	       }
	  }
     }

     if (x > y) x = y;

     printf("%d\n", x);

     return 0;
}