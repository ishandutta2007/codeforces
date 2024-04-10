#include <stdio.h>

int main()
{
     int n, a, b, c, sa = 0, sb = 0, sc = 0, i;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d %d %d", &a, &b, &c);

	  sa += a; sb += b; sc += c;
     }

     if (sa == 0 && sb == 0 && sc == 0) {
	  puts("YES");
     } else {
	  puts("NO");
     }

     return 0;
}