#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
     int x;
     int y;
} count;

int par[1000];

int find(int x)
{
     if (par[x] == x) {
	  return x;
     } else {
	  return par[x] = find(par[x]);
     }
}

void unite(int x, int y)
{
     x = find(x);
     y = find(y);

     if (x == y) return;

     par[x] = y;
}

int cmp(const void *a, const void *b)
{
     return ((count *)b)->x - ((count *)a)->x;
}

int main()
{
     char s1[1001], s2[1001];
     int n, i, j, k;
     int a[26] = {0};
     int b[1001] = {0};
     count c[1001];

     scanf("%s", s1);

     n = strlen(s1);

     for (i = 0; i < n; i++) a[s1[i] - 'a']++;

     for (i = 0; i < n; i++) par[i] = i;

     for (i = 2; i < n; i++) {
	  if (b[i] == 0) {
	       for (j = i * 2; j <= n; j += i) b[j] = 1;

	       for (j = 2; j <= n / i; j++) unite(i - 1, i * j - 1);
	  }
     }

     for (i = 0; i < n; i++) {
	  c[i].x = 0;
	  c[i].y = i;
     }

     for (i = 0; i < n; i++) c[find(i)].x++;

     qsort(c, n, sizeof(count), cmp);

     for (i = 0; i < n; i++) {
	  if (c[i].x == 0) break;

	  for (j = 0; j < 26; j++) {
	       if (a[j] >= c[i].x) break;
	  }

	  if (j == 26) {
	       puts("NO");

	       return 0;
	  }

	  for (k = 0; k < n; k++) {
	       if (find(k) == c[i].y) {
		    s2[k] = 'a' + j;

		    a[j]--;
	       }
	  }
     }

     s2[n] = '\0';

     puts("YES");

     printf("%s\n", s2);

     return 0;
}