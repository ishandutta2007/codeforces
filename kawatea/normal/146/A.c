#include <stdio.h>

int main()
{
     int n, i;
     int a[2] = {0};
     char s[51];

     scanf("%d", &n);
     scanf("%s", s);

     for (i = 0; i < n / 2; i++) {
	  if (s[i] != '4' && s[i] != '7') {
	       puts("NO");

	       return 0;
	  }

	  if (s[n - i - 1] != '4' && s[n - i - 1] != '7') {
	       puts("NO");

	       return 0;
	  }

	  a[0] += s[i] - '0';
	  a[1] += s[n - i - 1] - '0';
     }

     if (a[0] == a[1]) {
	  puts("YES");
     } else {
	  puts("NO");
     }

     return 0;
}