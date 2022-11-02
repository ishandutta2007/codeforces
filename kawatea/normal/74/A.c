#include <stdio.h>

int main()
{
     int n, num = 0, i;
     int sum[50];
     char s[50][21];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int p, m, a, b, c, d, e;
	  scanf("%s", s[i]);

	  scanf("%d %d %d %d %d %d %d", &p, &m, &a, &b, &c, &d, &e);

	  sum[i] = p * 100 - m * 50 + a + b + c + d + e;
     }

     for (i = 0; i < n; i++) {
	  if (sum[num] < sum[i]) num = i;
     }

     printf("%s\n", s[num]);

     return 0;
}