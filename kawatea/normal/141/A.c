#include <stdio.h>
#include <string.h>

int main()
{
     char s[101];
     int a[26] = {0};
     int i, j;

     for (i = 0; i < 2; i++) {
	  scanf("%s", s);

	  for (j = 0; j < strlen(s); j++) {
	       a[s[j] - 'A']++;
	  }
     }

     scanf("%s", s);

     for (i = 0; i < strlen(s); i++) a[s[i] - 'A']--;

     for (i = 0; i < 26; i++) {
	  if (a[i] != 0) {
	       puts("NO");

	       return 0;
	  }
     }

     puts("YES");

     return 0;
}