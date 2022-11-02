#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
     char s[11];
     int x;
} friend;

int cmp(const void *a, const void *b)
{
     if (((friend *)a)->x == ((friend *)b)->x) {
	  return strcmp(((friend *)a)->s, ((friend *)b)->s);
     } else {
	  return ((friend *)b)->x - ((friend *)a)->x;
     }
}

int main()
{
     char s[11];
     int n, p = 0, i, j, k;
     friend f[201];

     for (i = 0; i < 201; i++) f[i].x = 0;

     scanf("%s", s);
     scanf("%d", &n);

     strcpy(f[p++].s, s);

     for (i = 0; i < n; i++) {
	  char c[10], s1[11], s2[10], s3[13];

	  scanf("%s %s", s1, s2);

	  for (j = 0; j < p; j++) {
	       if (strcmp(s1, f[j].s) == 0) break;
	  }

	  if (j == p) strcpy(f[p++].s, s1);

	  if (s2[0] == 'p' || s2[0] == 'c') scanf("%*s");

	  scanf("%s", s3);

	  s3[strlen(s3) - 2] = '\0';

	  for (k = 0; k < p; k++) {
	       if (strcmp(s3, f[k].s) == 0) break;
	  }

	  if (k == p) strcpy(f[p++].s, s3);

	  if (j == 0) {
	       if (s2[0] == 'p') {
		    f[k].x += 15;
	       } else if (s2[0] == 'c') {
		    f[k].x += 10;
	       } else {
		    f[k].x += 5;
	       }
	  } else if (k == 0) {
	       if (s2[0] == 'p') {
		    f[j].x += 15;
	       } else if (s2[0] == 'c') {
		    f[j].x += 10;
	       } else {
		    f[j].x += 5;
	       }
	  }

	  fgets(c, 10, stdin);
     }

     qsort(f, p, sizeof(friend), cmp);

     for (i = 0; i < p; i++) {
	  if (strcmp(s, f[i].s) == 0) continue;
	  printf("%s\n", f[i].s);
     }

     return 0;
}