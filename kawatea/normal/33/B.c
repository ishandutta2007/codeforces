#include <stdio.h>
#include <string.h>

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     char s[100005], t[100005];
     int n, p, q, sum = 0, i, j, k;
     int d[26][26];

     for (i = 0; i < 26; i++) {
	  for (j = 0; j < 26; j++) {
	       if (i == j) {
		    d[i][j] = 0;
	       } else {
		    d[i][j] = 1e9;
	       }
	  }
     }

     scanf("%s %s", s, t);

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  char c1[2], c2[2];
	  int x;

	  scanf("%s %s %d", c1, c2, &x);

	  d[c1[0] - 'a'][c2[0] - 'a'] = min(d[c1[0] - 'a'][c2[0] - 'a'], x);
     }

     for (i = 0; i < 26; i++) {
	  for (j = 0; j < 26; j++) {
	       for (k = 0; k < 26; k++) {
		    d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
	       }
	  }
     }

     p = strlen(s); q = strlen(t);

     if (p != q) {
	  puts("-1");

	  return 0;
     }

     for (i = 0; i < p; i++) {
	  int c = 1e9, num = -1;

	  for (j = 0; j < 26; j++) {
	       if (c > d[s[i] - 'a'][j] + d[t[i] - 'a'][j]) {
		    c = d[s[i] - 'a'][j] + d[t[i] - 'a'][j];
		    num = j;
	       }
	  }

	  if (num == -1) {
	       puts("-1");

	       return 0;
	  }

	  s[i] = 'a' + num;

	  sum += c;
     }

     printf("%d\n", sum);
     printf("%s\n", s);

     return 0;
}