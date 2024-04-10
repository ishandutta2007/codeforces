#include <stdio.h>

int main()
{
     int a1, a2, a3, a4, i;

     scanf("%d %d %d %d", &a1, &a2, &a3, &a4);

     if (a3 > a4 + 1 || a4 > a3 + 1 || a1 < a3 || a1 < a4 || a2 < a3 || a2 < a4) {
	  puts("-1");

	  return 0;
     }

     if (a3 == a4) {
	  if (a1 == a3 && a2 == a4) {
	       puts("-1");

	       return 0;
	  }

	  if (a1 > a3) {
	       for (i = 0; i < a1 - a3 - 1; i++) {
		    putchar('4');
	       }

	       for (i = 0; i < a3; i++) {
		    putchar('4');
		    putchar('7');
	       }

	       for (i = 0; i < a2 - a3; i++) {
		    putchar('7');
	       }

	       putchar('4');
	       puts("");
	  } else {
	       for (i = 0; i < a3; i++) {
		    putchar('7');
		    putchar('4');
	       }

	       for (i = 0; i < a2 - a3; i++) {
		    putchar('7');
	       }

	       puts("");
	  }
     } else if (a3 > a4) {
	  for (i = 0; i < a1 - a3; i++) {
	       putchar('4');
	  }

	  for (i = 0; i < a3; i++) {
	       putchar('4');
	       putchar('7');
	  }

	  for (i = 0; i < a2 - a3; i++) {
	       putchar('7');
	  }

	  puts("");
     } else {
	  putchar('7');

	  for (i = 0; i < a1 - a3 - 1; i++) {
	       putchar('4');
	  }

	  for (i = 0; i < a3; i++) {
	       putchar('4');
	       putchar('7');
	  }

	  for (i = 0; i < a2 - a3 - 1; i++) {
	       putchar('7');
	  }

	  putchar('4');
	  puts("");
     }

     return 0;
}