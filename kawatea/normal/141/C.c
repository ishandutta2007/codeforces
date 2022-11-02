#include <stdio.h>
#include <stdlib.h>

typedef struct {
     char s[11];
     int a;
} people;

int cmp(const void *a, const void *b)
{
     return ((people *)a)->a - ((people *)b)->a;
}

int main()
{
     int n, i, j;
     people a[3000];
     int b[3000];

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%s %d", a[i].s, &a[i].a);

     qsort(a, n, sizeof(people), cmp);

     for (i = 0; i < n; i++) {
	  if (a[i].a > i) {
	       puts("-1");

	       return 0;
	  }

	  b[i] = a[i].a;

	  for (j = 0; j < i; j++) {
	       if (b[j] >= b[i]) b[j]++;
	  }
     }

     for (i = 0; i < n; i++) {
	  printf("%s %d\n", a[i].s, n - b[i]);
     }

     return 0;
}