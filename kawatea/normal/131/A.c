#include <stdio.h>
#include <string.h>

int main()
{
     int n, i;
     char s[101];

     scanf("%s", s);

     n = strlen(s);

     if (n == 1) {
	  if (s[0] >= 'a' && s[0] <= 'z') {
	       s[0] = s[0] - 'a' + 'A';
	  } else {
	       s[0] = s[0] - 'A' + 'a';
	  }
     } else {
	  for (i = 1; i < n; i++) {
	       if (s[i] >= 'a' && s[i] <= 'z') break;
	  }

	  if (i == n) {
	       for (i = 0; i < n; i++) {
		    if (s[i] >= 'a' && s[i] <= 'z') {
			 s[i] = s[i] - 'a' + 'A';
		    } else {
			 s[i] = s[i] - 'A' + 'a';
		    }
	       }
	  }
     }

     printf("%s\n", s);

     return 0;
}