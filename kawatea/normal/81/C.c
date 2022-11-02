#include <stdio.h>

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, a, b, x = 0, y = 0, i;
     int t[100000];
     int p[5] = {0};

     scanf("%d %d %d", &n, &a, &b);

     for (i = 0; i < n; i++) {
	  scanf("%d", &t[i]);

	  p[t[i] - 1]++;
     }

     if (a == b) {
	  for (i = 0; i < a; i++) {
	       if (i > 0) putchar(' ');
	       putchar('1');
	  }
	  for (i = 0; i < b; i++) {
	       putchar(' ');
	       putchar('2');
	  }
	  puts("");
     } else {
	  int m = min(a, b);

	  for (i = 4; i >= 0; i--) {
	       if (m > p[i]) {
		    m -= p[i];
	       } else {
		    x = i + 1;
		    y = p[i] - m;

		    break;
	       }
	  }

	  for (i = 0; i < n; i++) {
	       if (i > 0) putchar(' ');

	       if (t[i] > x) {
		    if (a < b) {
			 putchar('1');
		    } else {
			 putchar('2');
		    }
	       } else if (t[i] < x) {
		    if (a > b) {
			 putchar('1');
		    } else {
			 putchar('2');
		    }
	       } else {
		    if (a > b) {
			 if (y > 0) {
			      putchar('1');
			      y--;
			 } else {
			      putchar('2');
			 }
		    } else {
			 if (m > 0) {
			      putchar('1');
			      m--;
			 } else {
			      putchar('2');
			 }
		    }
	       }
	  }
	  puts("");
     }

     return 0;
}