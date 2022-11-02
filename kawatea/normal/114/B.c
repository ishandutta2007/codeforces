#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
     char s[11];
} name;

int cmp(const void *a, const void *b)
{
     return strcmp(((name *)a)->s, ((name *)b)->s);
}

int main()
{
     int n, m, max = 0, num = 0, i, j, k;
     name s[16];
     char c1[11], c2[11];
     int a[16][16] = {0};

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) scanf("%s", s[i].s);

     qsort(s, n, sizeof(name), cmp);

     for (i = 0; i < m; i++) {
	  scanf("%s %s", c1, c2);

	  for (j = 0; j < n; j++) {
	       if (strcmp(s[j].s, c1) == 0) break;
	  }

	  for (k = 0; k < n; k++) {
	       if (strcmp(s[k].s, c2) == 0) break;
	  }

	  a[j][k] = a[k][j] = 1;
     }


     for (i = 0; i < (1 << n); i++) {
	  int f = 0;

	  for (j = 0; j < n; j++) {
	       for (k = 0; k < n; k++) {
		    if ((i >> j) & 1 && (i >> k) & 1) {
			 if (a[j][k] == 1) {
			      f = 1; j = n; break;
			 }
		    }
	       }
	  }

	  if (f == 0) {
	       int c = 0;

	       for (j = 0; j < n; j++) {
		    if ((i >> j) & 1) c++;
	       }

	       if (c > max) {
		    max = c;
		    num = i;
	       }
	  }
     }

     printf("%d\n", max);

     for (i = 0; i < n; i++) {
	  if ((num >> i) & 1) {
	       printf("%s\n", s[i].s);
	  }
     }

     return 0;
}