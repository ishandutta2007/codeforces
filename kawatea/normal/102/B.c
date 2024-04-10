#include <stdio.h>
#include <string.h>

int main()
{
     char s[100005];
     int n = 1, sum = 0, i;

     scanf("%s", s);

     if (strlen(s) == 1) {
	  puts("0");

	  return 0;
     }

     for (i = 0; i < strlen(s); i++) sum += s[i] - '0';

     while (sum / 10 > 0) {
	  int p = 0;

	  while (sum) {
	       p += sum % 10;
	       sum /= 10;
	  }

	  sum = p;
	  n++;
     }

     printf("%d\n", n);

     return 0;
}