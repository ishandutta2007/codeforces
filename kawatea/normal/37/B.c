#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int pow;
     int dmg;
     int i;
     int f;
} scroll;

int cmp(const void *a, const void *b)
{
     if (((scroll *)a)->dmg != ((scroll *)b)->dmg) {
	  return ((scroll *)b)->dmg - ((scroll *)a)->dmg;
     } else {
	  return ((scroll *)b)->pow - ((scroll *)a)->pow;
     }
}

int main()
{
     int n, m, reg, x, d = 0, t, p = 0, i;
     scroll s[1000];
     int a[1000][2];

     scanf("%d %d %d", &n, &m, &reg);

     x = m;

     for (i = 0; i < n; i++) {
	  scanf("%d %d", &s[i].pow, &s[i].dmg);

	  s[i].i = i + 1;
	  s[i].f = 0;
     }

     qsort(s, n, sizeof(scroll), cmp);

     for (t = 0; ; t++) {
	  x -= d;

	  x += reg;

	  if (x > m) x = m;

	  if (x <= 0) break;

	  for (i = 0; i < n; i++) {
	       if (s[i].f == 0 && s[i].pow * m >= x * 100) break;
	  }

	  if (i == n) {
	       if (d <= reg) {
		    puts("NO");

		    return 0;
	       }
	  } else {
	       s[i].f = 1;
	       d += s[i].dmg;

	       a[p][0] = t;
	       a[p++][1] = s[i].i;
	  }
     }

     puts("YES");
     printf("%d %d\n", t, p);

     for (i = 0; i < p; i++) {
	  printf("%d %d\n", a[i][0], a[i][1]);
     }

     return 0;
}