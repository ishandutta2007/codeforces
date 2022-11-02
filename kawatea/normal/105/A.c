#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
     char s[21];
     int num;
} skill;

int cmp(const void *a, const void *b)
{
     return strcmp(((skill *)a)->s, ((skill *)b)->s);
}

int main()
{
     int n, m, k, z = 0, i, j;
     char s1[20][21], s2[20][21];
     int a[20];
     skill c[40];

     scanf("%d %d %*d.%d", &n, &m, &k);

     for (i = 0; i < n + m; i++) c[i].num = 0;

     for (i = 0; i < n; i++) scanf("%s %d", s1[i], &a[i]);

     for (i = 0; i < m; i++) scanf("%s", s2[i]);

     for (i = 0; i < n; i++) {
	  int x = a[i] * k / 100;

	  if (x >= 100) {
	       strcpy(c[z].s, s1[i]);

	       c[z++].num = x;
	  }
     }

     for (i = 0; i < m; i++) {
	  for (j = 0; j < z; j++) {
	       if (strcmp(s2[i], c[j].s) == 0) break;
	  }

	  if (j == z) strcpy(c[z++].s, s2[i]);
     }

     qsort(c, z, sizeof(skill), cmp);

     printf("%d\n", z);
     for (i = 0; i < z; i++) printf("%s %d\n", c[i].s, c[i].num);

     return 0;
}