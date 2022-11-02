#include <stdio.h>
#include <string.h>

int main()
{
     char s[1000][1005];
     int n = 0, max = 0, f = 0, i, j;
     int a[1000];

     while (fgets(s[n], 1005, stdin) != NULL) {
	  a[n] = strlen(s[n]) - 1;

	  s[n][a[n]] = '\0';

	  if (a[n] > max) max = a[n];

	  n++;
     }

     for (i = 0; i < max + 2; i++) putchar('*');
     puts("");

     for (i = 0; i < n; i++) {
	  int x = (max - a[i]) / 2;

	  putchar('*');

	  if ((max - a[i]) % 2 == 0) {
	       for (j = 0; j < x; j++) putchar(' ');
	       printf("%s", s[i]);
	       for (j = 0; j < x; j++) putchar(' ');
	  } else {
	       if (f == 0) {
		    for (j = 0; j < x; j++) putchar(' ');
		    printf("%s", s[i]);
		    for (j = 0; j < x + 1; j++) putchar(' ');
	       } else {
		    for (j = 0; j < x + 1; j++) putchar(' ');
		    printf("%s", s[i]);
		    for (j = 0; j < x; j++) putchar(' ');
	       }

	       f ^= 1;
	  }

	  puts("*");
     }

     for (i = 0; i < max + 2; i++) putchar('*');
     puts("");

     return 0;
}