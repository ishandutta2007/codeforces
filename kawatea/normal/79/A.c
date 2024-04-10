#include <stdio.h>

int main()
{
     int x, y;

     scanf("%d %d", &x, &y);

     while (1) {
	  if (x * 100 + y * 10 < 220 || y < 2) {
	       puts("Hanako");
	       break;
	  }

	  if (x >= 2) {
	       x -= 2; y -= 2;
	  } else if (x == 1) {
	       x--; y -= 12;
	  } else {
	       y -= 22;
	  }

	  if (x * 100 + y * 10 < 220 || y < 2) {
	       puts("Ciel");
	       break;
	  }

	  if (y >= 22) {
	       y -= 22;
	  } else if (y >= 12) {
	       x--; y -= 12;
	  } else {
	       x -= 2; y -= 2;
	  }
     }

     return 0;
}