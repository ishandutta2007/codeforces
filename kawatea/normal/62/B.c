#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int d[26][100000];

int minimum(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, k, i, j;
     int a[26] = {0};
     char s[200001];

     scanf("%d %d%*c", &n, &k);

     for (i = 0; i < k; i++) {
	  char c;

	  scanf("%c", &c);

	  d[c - 'a'][a[c - 'a']++] = i;
     }

     scanf("%*c");

     for (i = 0; i < n; i++) {
	  long long sum = 0;
	  int m;

	  scanf("%s", s);

	  m = strlen(s);

	  for (j = 0; j < m; j++) {
	       int p = s[j] - 'a';

	       if (a[p] == 0) {
		    sum += m;
	       } else {
		    int l = -1, r = a[p], u = (l + r) / 2;

		    while (r - l > 1) {
			 if (d[p][u] < j) {
			      l = u; u = (l + r) / 2;
			 } else {
			      r = u; u = (l + r) / 2;
			 }
		    }

		    if (r == a[p]) {
			 sum += abs(d[p][r - 1] - j);
		    } else if (r > 0) {
			 sum += minimum(abs(d[p][r] - j), abs(d[p][r - 1] - j));
		    } else {
			 sum += abs(d[p][r] - j);
		    }
	       }
	  }

	  printf("%I64d\n", sum);
     }

     return 0;
}