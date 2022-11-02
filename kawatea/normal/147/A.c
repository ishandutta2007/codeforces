#include <stdio.h>
#include <string.h>

int main()
{
     int n, p = 0, f = 0, i;
     char s1[10010], s2[20000];

     fgets(s1, 10010, stdin);

     n = strlen(s1);

     s1[--n] = '\0';

     for (i = 0; i < n; i++) {
	  if (s1[i] >= 'a' && s1[i] <= 'z') {
	       if (f == 1) s2[p++] = ' ';
	       s2[p++] = s1[i];
	       f = 0;
	  } else if (s1[i] == ' ') {
	       f = 1;
	  } else {
	       s2[p++] = s1[i];
	       f = 1;
	  }
     }

     s2[p] = '\0';

     printf("%s\n", s2);

     return 0;
}