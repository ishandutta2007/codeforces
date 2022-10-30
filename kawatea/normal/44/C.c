#include <stdio.h>

int main()
{
     int n, m, i, j;
     int p[100] = {0};

     scanf("%d %d", &n, &m);

     for (i = 0; i < m; i++) {
	  int a, b;

	  scanf("%d %d", &a, &b);

	  for (j = a - 1; j < b; j++) p[j]++;
     }

     for (i = 0; i < n; i++) {
	  if (p[i] != 1) break;
     }

     if (i == n) {
	  puts("OK");
     } else {
	  printf("%d %d\n", i + 1, p[i]);
     }

     return 0;
}