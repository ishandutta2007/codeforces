#include <stdio.h>
#include <string.h>

int main()
{
     char s[1000001];
     int n, f = -1, i;
     int a[100000] = {0};

     scanf("%s", s);

     n = strlen(s);

     if (n % 2 == 1) {
	  for (i = 0; i < n / 2 + 1; i++) putchar('4');
	  for (i = 0; i < n / 2 + 1; i++) putchar('7');
	  puts("");

	  return 0;
     }

     for (i = 0; i < n; i++) {
	  if (s[i] == '4') {
	       f = i;
	       continue;
	  } else if (s[i] < '4') {
	       for (; i < n; i++) s[i] = '4';

	       break;
	  } else if (s[i] < '7') {
	       s[i] = '7';

	       for (i++; i < n; i++) s[i] = '4';

	       break;
	  } else if (s[i] > '7') {
	       if (f == -1) {
		    for (i = 0; i < n / 2 + 1; i++) putchar('4');
		    for (i = 0; i < n / 2 + 1; i++) putchar('7');
		    puts("");

		    return 0;
	       } else {
		    s[f] = '7';

		    for (i = f + 1; i < n; i++) s[i] = '4';
	       }
	  }
     }

     f = 0;

     for (i = 0; i < n; i++) {
	  if (s[i] == '4') f++;

	  a[i] = i + 1 - f;
     }

     if (f * 2 > n) {
	  for (i = n - 1; i >= 0; i--) {
	       if (s[i] == '4') {
		    s[i] = '7';

		    f--;

		    if (f * 2 == n) break;
	       }
	  }
     } else if (f * 2 < n) {
	  for (i = n - 1; i >= 0; i--) {
	       if (s[i] == '4' && a[i] < n / 2) {
		    int x = a[i];

		    s[i] = '7';

		    for (i++; i < n / 2 + x + 1; i++) s[i] = '4';
		    for (; i < n; i++) s[i] = '7';

		    break;
	       }
	  }

	  if (i < 0) {
	       for (i = 0; i < n / 2 + 1; i++) putchar('4');
	       for (i = 0; i < n / 2 + 1; i++) putchar('7');
	       puts("");

	       return 0;
	  }
     }

     printf("%s\n", s);

     return 0;
}