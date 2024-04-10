#include <stdio.h>
#include <ctype.h>

int main()
{
     int n, c = 0, f = 0, i = 0, j;
     char s[10005];
     int a[10000];
 
     scanf("%d%*c", &n);

     fgets(s, 10005, stdin);

     while (s[i] != '\n') {
	  int d = 0;
	  while (1) {
	       while (isalpha(s[i])) {
		    d++; i++;
	       }

	       if (s[i] == '.' || s[i] == '?' || s[i] =='!') {
		    d++; break;
	       }

	       d++; i++;
	  }

	  if (d > n) {
	       f = 1;
	       puts("Impossible");
	       break;
	  }

	  a[c++] = d; i++;

	  if (s[i] == ' ') i++;
     }

     if (f == 0) {
	  for (i = 0; i < c - 1; i++) {
	       if (a[i] + a[i + 1] + 1 <= n) {
		    a[i] += a[i + 1] + 1;

		    for (j = i + 1; j < c - 1; j++) a[j] = a[j + 1];

		    c--; i--;
	       }
	  }

	  printf("%d\n", c);
     }

     return 0;
}