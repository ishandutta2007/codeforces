#include <stdio.h>

int main()
{
     int a, x, y;

     scanf("%d %d %d", &a, &x, &y);

     if (y % a == 0) {
	  puts("-1");
     } else {
	  y /= a;

	  if (y == 0) {
	       if (x >= 0 && a > x * 2 || x <= 0 && a > - x * 2) {
		    puts("1");
	       } else {
		    puts("-1");
	       }
	  } else if (y % 2 == 0) {
	       if (x > 0 && a > x) {
		    printf("%d\n", 3 * y / 2 + 1);
	       } else if (x < 0 && a > -x) {
		    printf("%d\n", 3 * y / 2);
	       } else {
		    puts("-1");
	       }
	  } else {
	       if (x >= 0 && a > x * 2 || x <= 0 && a > - x * 2) {
		    printf("%d\n", 3 * y / 2 + 1);
	       } else {
		    puts("-1");
	       }
	  }
     }

     return 0;
}