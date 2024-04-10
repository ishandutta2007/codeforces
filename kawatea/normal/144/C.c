#include <stdio.h>
#include <string.h>

int main()
{
     int n, m, sum = 0, i, j;
     char s1[100001], s2[100001];
     int a[26] = {0};

     scanf("%s", s1);
     scanf("%s", s2);

     n = strlen(s1);
     m = strlen(s2);

     if (n < m) {
	  puts("0");

	  return 0;
     }

     for (i = 0; i < m; i++) {
	  a[s2[i] - 'a']++;

	  if (s1[i] != '?') a[s1[i] - 'a']--;
     }

     for (i = 0; i < 26; i++) {
	  if (a[i] < 0) break;
     }

     if (i == 26) sum++;

     for (i = 0; i < n - m; i++) {
	  if (s1[i] != '?') a[s1[i] - 'a']++;

	  if (s1[i + m] != '?') a[s1[i + m] - 'a']--;

	  for (j = 0; j < 26; j++) {
	       if (a[j] < 0) break;
	  }

	  if (j == 26) sum++;
     }

     printf("%d\n", sum);

     return 0;
}