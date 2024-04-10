#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
     char s[31];
     int point;
     int diff;
     int scored;
     int flag;
} team;

int cmp1(const void *a, const void *b)
{
     if (((team *)a)->point != ((team *)b)->point) {
	  return ((team *)b)->point - ((team *)a)->point;
     } else if (((team *)a)->diff != ((team *)b)->diff) {
	  return ((team *)b)->diff - ((team *)a)->diff;
     } else {
	  return ((team *)b)->scored - ((team *)a)->scored;
     }
}

int cmp2(const void *a, const void *b)
{
     return strcmp(((team *)a)->s, ((team *)b)->s);
}

int main()
{
     int n, i, j, k;
     team t[50];

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%s", t[i].s);

	  t[i].point = t[i].diff = t[i].scored = t[i].flag = 0;
     }

     for (i = 0; i < n * (n - 1) / 2; i++) {
	  char s[100], c1[31], c2[31];
	  int a, b;

	  scanf("%s %d:%d", s, &a, &b);

	  for (j = 0; j < strlen(s); j++) {
	       if (s[j] == '-') break;

	       c1[j] = s[j];
	  }

	  c1[j++] = '\0';

	  strcpy(c2, &s[j]);

	  for (j = 0; j < n; j++) {
	       if (strcmp(c1, t[j].s) == 0) break;
	  }

	  for (k = 0; k < n; k++) {
	       if (strcmp(c2, t[k].s) == 0) break;
	  }

	  if (a > b) {
	       t[j].point += 3;
	       t[j].diff += a - b;
	       t[j].scored += a;

	       t[k].diff -= a - b;
	       t[k].scored += b;
	  } else if (a == b) {
	       t[j].point++;
	       t[j].scored += a;

	       t[k].point++;
	       t[k].scored += b;
	  } else {
	       t[j].diff -= b - a;
	       t[j].scored += a;

	       t[k].point += 3;
	       t[k].diff += b - a;
	       t[k].scored += b;
	  }
     }

     qsort(t, n, sizeof(team), cmp1);

     for (i = 0; i < n / 2; i++) t[i].flag = 1;

     qsort(t, n, sizeof(team), cmp2);

     for (i = 0; i < n; i++) {
	  if (t[i].flag == 1) printf("%s\n", t[i].s);
     }

     return 0;
}