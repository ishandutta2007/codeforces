#include <stdio.h>
#include <string.h>

int main()
{
     int n1, n2, i, j;
     char s[100001], t[100001];
     int a[10] = {0};

     scanf("%s", s);
     scanf("%s", t);

     n1 = strlen(s);
     n2 = strlen(t);

     for (i = 0; i < n2; i++) a[t[i] - '0']++;

     for (i = 0; i < n1; i++) {
	  for (j = 9; j >= 0; j--) {
	       if (a[j] == 0) continue;

	       if (s[i] - '0' >= j) break;

	       s[i] = j + '0';

	       a[j]--;
	  }
     }

     printf("%s\n", s);

     return 0;
}