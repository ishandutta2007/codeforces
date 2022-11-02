#include <stdio.h>
#include <string.h>

int main()
{
     int n, sum = 0, k, i, j, l;
     char s[100001];
     int a[26][26] = {0};

     scanf("%s", s);

     n = strlen(s);

     scanf("%d", &k);

     for (i = 0; i < k; i++) {
	  char c[3];

	  scanf("%s", c);

	  a[c[0] - 'a'][c[1] - 'a'] = 1;
	  a[c[1] - 'a'][c[0] - 'a'] = 1;
     }

     for (i = 0; i < n - 1; i++) {
	  if (a[s[i] - 'a'][s[i + 1] - 'a'] == 1) {
	       int x = 0, y = 0;

	       for (j = i - 1; j >= 0; j--) {
		    if (s[j] == s[i]) {
			 x++;
		    } else if (s[j] == s[i + 1]) {
			 y++;
		    } else {
			 break;
		    }
	       }

	       for (j = i; j < n; j++) {
		    if (s[j] == s[i]) {
			 x++;
		    } else if (s[j] == s[i + 1]) {
			 y++;
		    } else {
			 break;
		    }
	       }

	       if (x < y) {
		    sum += x;
	       } else {
		    sum += y;
	       }

	       i = j - 1;
	  }
     }

     printf("%d\n", sum);

     return 0;
}