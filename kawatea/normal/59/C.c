#include <stdio.h>
#include <string.h>

int main()
{
     int k, n, p = 0, q = 0, i, j;
     char s1[101], s2[102];
     int a[26] = {0};

     scanf("%d", &k);

     scanf("%s", s1);

     n = strlen(s1);

     for (i = 0; i < n; i++) {
	  s2[n - i - 1] = s1[i];
     }

     for (i = 0; i < (n + 1) / 2; i++) {
	  if (s1[i] == '?') {
	       if (s2[i] == '?') {
		    p++;
	       } else {
		    if (a[s2[i] - 'a']++ == 0) q++;

		    s1[i] = s2[i];
	       }
	  } else {
	       if (s2[i] == '?') {
		    if (a[s1[i] - 'a']++ == 0) q++;

		    s1[n - i - 1] = s1[i];
	       } else {
		    if (s1[i] == s2[i]) {
			 if (a[s1[i] - 'a']++ == 0) q++;
		    } else {
			 puts("IMPOSSIBLE");

			 return 0;
		    }
	       }
	  }
     }

     if (p + q < k) {
	  puts("IMPOSSIBLE");

	  return 0;
     }

     for (i = 0; i < (n + 1) / 2; i++) {
	  if (s1[i] == '?') {
	       if (p + q > k) {
		    s1[i] = s1[n - i - 1] = 'a';

		    if (a[0]++ == 0) q++;
	       } else {
		    for (j = 0; j < 26; j++) {
			 if (a[j] == 0) break;
		    }

		    s1[i] = s1[n - i - 1] = 'a' + j;

		    a[j]++;

		    q++;
	       }

	       p--;
	  }
     }

     printf("%s\n", s1);

     return 0;
}