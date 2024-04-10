#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int a;
     char s[1001];
     int i;
} word;

int cmp(const void *a, const void *b)
{
     return ((word *)a)->a - ((word *)b)->a;
}

int cmp2(const void *a, const void *b)
{
     return ((word *)a)->i - ((word *)b)->i;
}

int main()
{
     int n, p = 0, i, j;
     word w[1000];
     char s[1001] = "";

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%d", &w[i].a);

	  w[i].i = i;
     }

     qsort(w, n, sizeof(word), cmp);

     for (i = 0; i < n; i++) {
	  if (p > 0) {
	       for (j = p - 1; j >= 0; j--) {
		    if (s[j] == '1') {
			 s[j] = '0';
		    } else {
			 s[j] = '1';

			 break;
		    }
	       }

	       if (j < 0) {
		    puts("NO");

		    return 0;
	       }
	  }

	  while (p < w[i].a) s[p++] = '0';

	  for (j = 0; j < p; j++) w[i].s[j] = s[j];
	  w[i].s[j] = '\0';
     }

     qsort(w, n, sizeof(word), cmp2);

     puts("YES");

     for (i = 0; i < n; i++) printf("%s\n", w[i].s);

     return 0;
}