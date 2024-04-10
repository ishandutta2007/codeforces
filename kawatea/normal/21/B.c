#include <stdio.h>

int main()
{
     int a1, b1, c1, a2, b2, c2;

     scanf("%d %d %d", &a1, &b1, &c1);
     scanf("%d %d %d", &a2, &b2, &c2);

     if ((a1 == 0 && b1 == 0 && c1 != 0) || (a2 == 0 && b2 == 0 && c2 != 0)) {
	  puts("0");
     } else if ((a1 == 0 && b1 == 0) || (a2 == 0 && b2 == 0)) {
	  puts("-1");
     } else if (a1 * b2 != a2 * b1) {
	  puts("1");
     } else {
	  if (a1 == 0) {
	       if (b1 * c2 == b2 * c1) {
		    puts("-1");
	       } else {
		    puts("0");
	       }
	  } else {
	       if (a1 * c2 == a2 * c1) {
		    puts("-1");
	       } else {
		    puts("0");
	       }
	  }
     }

     return 0;
}