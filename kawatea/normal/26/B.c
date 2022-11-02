#include <stdio.h>
#include <string.h>

int main()
{
     char s[1000001];
     int n = 0, p = 0, i;

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) {
	  if (s[i] == '(') {
	       p++;
	  } else if (p > 0) {
	       p--;
	       n += 2;
	  }
     }

     printf("%d\n", n);

     return 0;
}