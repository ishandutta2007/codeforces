#include <stdio.h>
#include <string.h>

int main()
{
     int n, f = 0, i;
     char s[110];

     scanf("%s", s);

     n = strlen(s);

     if (s[0] == '-') f = 1;

     for (i = 0; i < n; i++) {
	  if (s[i] == '.') break;
     }

     if (i < n - 2) {
	  s[i + 3] = '\0';
	  n = i + 3;
     } else if (i == n - 2) {
	  s[n] = '0';
	  s[n + 1] = '\0';
	  n++;
     } else {
	  s[n] = '.';
	  s[n + 1] = s[n + 2] = '0';
	  s[n + 3] = '\0';
	  n += 3;
     }

     if (f == 1) putchar('(');

     putchar('$');

     for (i = f; i < n; i++) {
	  if (i > f && (n - i) % 3 == 0 && s[i] != '.') putchar(',');

	  putchar(s[i]);
     }

     if (f == 1) putchar(')');

     puts("");

     return 0;
}