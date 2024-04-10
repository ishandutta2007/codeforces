#include <stdio.h>

int main()
{
     int n, x, i, j;
     int c[1001] = {0};

     scanf("%d %d", &n, &x);

     for (i = 0; i < n; i++) {
	  int a, b;

	  scanf("%d %d", &a, &b);

	  if (a > b) {
	       int tmp = a; a = b; b = tmp;
	  }

	  for (j = a; j <= b; j++) c[j]++;
     }

     for (i = 0; i <= 1000; i++) {
	  if (c[i] == n) break;
     }

     if (i > 1000) {
	  puts("-1");

	  return 0;
     }

     for (j = i + 1; j <= 1000; j++) {
	  if (c[j] < n) break;
     }

     if (x < i) {
	  printf("%d\n", i - x);
     } else if (x < j) {
	  puts("0");
     } else {
	  printf("%d\n", x - j + 1);
     }

     return 0;
}