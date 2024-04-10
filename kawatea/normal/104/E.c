#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int a;
     int b;
     int i;
} scenario;

scenario s[300000];
int w[300000];
long long a[300000];
long long sum[300000];

int cmp(const void *a, const void *b)
{
     return ((scenario *)a)->b - ((scenario *)b)->b;
}

int main()
{
     int n, p, i, j;

     scanf("%d", &n);

     for (i = 0; i < n; i++) scanf("%d", &w[i]);

     scanf("%d", &p);

     for (i = 0; i < p; i++) {
	  scanf("%d %d", &s[i].a, &s[i].b);

	  s[i].a--;

	  s[i].i = i;
     }

     qsort(s, p, sizeof(scenario), cmp);

     for (i = 0; i < p; i++) {
	  if (s[i].b > 300) {
	       long long x = 0;

	       for (j = s[i].a; j < n; j += s[i].b) x += w[j];

	       a[s[i].i] = x;
	  } else {
	       if (i == 0 || s[i].b != s[i - 1].b) {
		    for (j = n - 1; j >= 0; j--) {
			 if (j + s[i].b >= n) {
			      sum[j] = w[j];
			 } else {
			      sum[j] = w[j] + sum[j + s[i].b];
			 }
		    }
	       }

	       a[s[i].i] = sum[s[i].a];
	  }
     }

     for (i = 0; i < p; i++) printf("%I64d\n", a[i]);

     return 0;
}