#include <stdio.h>
#include <string.h>

int a[1000005];

int main()
{
     char s[1000005];
     int x = 0, y = 0, n, i;

     scanf("%s", s);

     n = strlen(s);

     for (i = 0; i < n; i++) {
	  int p = 0;

	  a[0] = i;

	  for (; i < n; i++) {
	       if (s[i] == '(') {
		    p++;
		    a[p] = i + 1;
	       } else {
		    p--;

		    if (p >= 0) {
			 if (i - a[p] + 1 > x) {
			      x = i - a[p] + 1; y = 1;
			 } else if (i - a[p] + 1 == x) {
			      y++;
			 }
		    } else {
			 break;
		    }
	       }
	  }
     }

     if (x == 0) {
	  puts("0 1");
     } else {
	  printf("%d %d\n", x, y);
     }

     return 0;
}