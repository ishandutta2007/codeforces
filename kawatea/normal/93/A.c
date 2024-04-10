#include <stdio.h>

int main()
{
     int n, m, a, b, p, q, r;

     scanf("%d %d %d %d", &n, &m, &a, &b);

     p = m - (a - 1) % m;
     q = m;
     r = b % m;

     if (p >= b - a + 1) {
	  puts("1");
     } else if (b - a - p + 1 <= m) {
	  if (p == m && (b - a - p + 1 == m || b == n)) {
	       puts("1");
	  } else {
	       puts("2");
	  }
     } else {
	  int c = 3;

	  if (p == q) c--;
	  if (r == 0 || b == n || p + r == m) c--;

	  printf("%d\n", c);
     }

     return 0;
}