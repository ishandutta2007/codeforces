#include <stdio.h>
#include <string.h>

int main()
{
     char s1[10001], s2[1000001];
     int num = 1, x = -1, i;
     int d[26][10000], a[26] = {0};

     scanf("%s %s", s1, s2);

     for (i = 0; i < strlen(s1); i++) {
	  d[s1[i] - 'a'][a[s1[i] - 'a']++] = i;
     }

     for (i = 0; i < strlen(s2); i++) {
	  int p = s2[i] - 'a', l = -1, r = a[p], u = (l + r) / 2;

	  if (a[p] == 0) {
	       puts("-1");

	       return 0;
	  }

	  while (r - l > 1) {
	       if (d[p][u] <= x) {
		    l = u;
		    u = (l + r) / 2;
	       } else {
		    r = u;
		    u = (l + r) / 2;
	       }
	  }

	  if (r < a[p]) {
	       x = d[p][r];
	  } else {
	       num++;
	       x = d[p][0];
	  }
     }

     printf("%d\n", num);

     return 0;
}