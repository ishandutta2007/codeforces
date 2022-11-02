#include <stdio.h>
#include <string.h>

int main()
{
     int n, p, max = 0, f = 0, i, j;
     char s[20];

     scanf("%s", s);

     n = strlen(s);

     for (i = 0; i < n; i++) {
	  if (s[i] == ':') break;
     }

     p = i;

     if (s[p - 1] >= 'O') {
	  puts("0");

	  return 0;
     }

     for (i = 0; i < p - 1; i++) {
	  if (s[i] != '0') break;
     }

     if (i == p - 1) {
	  for (i = p + 1; i < n; i++) {
	       if (s[i] != '0') break;
	  }

	  if (i >= n - 1) {
	       puts("-1");

	       return 0;
	  }
     }

     for (i = 0; i < n; i++) {
	  if (i == p) continue;

	  if (s[i] >= '0' && s[i] <= '9') {
	       if (s[i] - '0' > max) max = s[i] - '0';
	  } else {
	       if (s[i] - 'A' + 10 > max) max = s[i] - 'A' + 10;
	  }
     }

     for (i = max + 1; ; i++) {
	  int x = 0, y = 0;

	  for (j = 0; j < p; j++) {
	       x *= i;

	       if (s[j] >= '0' && s[j] <= '9') {
		    x += s[j] - '0';
	       } else {
		    x += s[j] - 'A' + 10;
	       }
	  }

	  for (j = p + 1; j < n; j++) {
	       y *= i;

	       if (s[j] >= '0' && s[j] <= '9') {
		    y += s[j] - '0';
	       } else {
		    y += s[j] - 'A' + 10;
	       }
	  }

	  if (x >= 24 || y >= 60) break;

	  f = 1;

	  printf("%d ", i);
     }

     if (f == 0) {
	  puts("0");
     } else {
	  puts("");
     }

     return 0;
}