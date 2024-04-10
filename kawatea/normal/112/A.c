#include <stdio.h>
#include <string.h>

int main()
{
     char s1[101], s2[101];
     int n, i;

     scanf("%s %s", s1, s2);

     for (i = 0; i < strlen(s1); i++) {
	  if (s1[i] >= 'A' && s1[i] <= 'Z') {
	       s1[i] = s1[i] - 'A' + 'a';
	  }

	  if (s2[i] >= 'A' && s2[i] <= 'Z') {
	       s2[i] = s2[i] - 'A' + 'a';
	  }
     }

     n = strcmp(s1, s2);

     if (n > 0) {
	  puts("1");
     } else if (n == 0) {
	  puts("0");
     } else {
	  puts("-1");
     }

     return 0;
}