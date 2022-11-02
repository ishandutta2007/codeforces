#include <stdio.h>
#include <string.h>

int main()
{
     int n, a = 0, b = 0, c = 0, i;
     char s[100001];

     scanf("%s", s);

     n = strlen(s);

     for (i = 0; i < n; i++) {
	  if (s[i] == '0') {
	       a++;
	  } else if (s[i] == '1') {
	       b++;
	  } else {
	       c++;
	  }
     }

     if (b <= (n - 1) / 2) puts("00");

     if (b + c > (n - 1) / 2 && a + c > (n - 2) / 2) {
	  if (s[n - 1] == '1' || (s[n - 1] == '?' && a + c - 1 > (n - 2) / 2)) {
	       puts("01");
	  }

	  if (s[n - 1] == '0' || (s[n - 1] == '?' && b + c - 1 > (n - 1) / 2)) {
	       puts("10");
	  }
     }

     if (a <= (n - 2) / 2) puts("11");

     return 0;
}