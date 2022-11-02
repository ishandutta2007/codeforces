#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     char s[2][3];
     int x1, y1, x2, y2, n, i;

     scanf("%s %s", s[0], s[1]);

     x1 = s[0][0] - 'a'; y1 = s[0][1] - '1';
     x2 = s[1][0] - 'a'; y2 = s[1][1] - '1';

     n = maximum(abs(x1 - x2), abs(y1 - y2));

     printf("%d\n", n);

     for (i = 0; i < n; i++) {
	  if (x1 < x2) {
	       if (y1 < y2) {
		    x1++; y1++;
		    puts("RU");
	       } else if (y1 == y2) {
		    x1++;
		    puts("R");
	       } else {
		    x1++; y1--;
		    puts("RD");
	       }
	  } else if (x1 == x2) {
	       if (y1 < y2) {
		    y1++;
		    puts("U");
	       } else {
		    y1--;
		    puts("D");
	       }
	  } else {
	       if (y1 < y2) {
		    x1--; y1++;
		    puts("LU");
	       } else if (y1 == y2) {
		    x1--;
		    puts("L");
	       } else {
		    x1--; y1--;
		    puts("LD");
	       }
	  }
     }

     return 0;
}