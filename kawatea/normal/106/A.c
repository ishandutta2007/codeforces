#include <stdio.h>

int main()
{
     char s[2], s1[3], s2[3];
     char c[10] = "6789TJQKA";
     int i, j;

     scanf("%s %s %s", s, s1, s2);

     if (s1[1] == s2[1]) {
	  for (i = 0; ; i++) {
	       if (s1[0] == c[i]) break;
	  }
	  for (j = 0; ; j++) {
	       if (s2[0] == c[j]) break;
	  }

	  if (i > j) {
	       puts("YES");
	  } else {
	       puts("NO");
	  }
     } else if (s1[1] == s[0]) {
	  puts("YES");
     } else {
	  puts("NO");
     }

     return 0;
}