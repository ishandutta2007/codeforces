#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _list {
     char s[101];
     struct _list* a[100];
     int p;
     int q;
} list;

void add(list *l, char *s)
{
     int i;
     char *c = strstr(s, "\\");

     if (c == NULL) {
	  l->q++;
     } else {
	  *c = '\0';

	  for (i = 0; i < l->p; i++) {
	       if (strcmp(l->a[i]->s, s) == 0) {
		    add(l->a[i], c + 1);

		    return;
	       }
	  }

	  l->a[i] = malloc(sizeof(list));

	  strcpy(l->a[i]->s, s);
	  l->a[i]->p = l->a[i]->q = 0;

	  l->p++;

	  add(l->a[i], c + 1);
     }
}

int sub(list *l)
{
     int x = 0, i;

     for (i = 0; i < l->p; i++) {
	  x += sub(l->a[i]);
     }

     return l->p + x;
}

int file(list *l)
{
     int x = 0, i;

     for (i = 0; i < l->p; i++) {
	  x += file(l->a[i]);
     }

     return l->q + x;
}

int maximum(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     list* l[5];
     char s[101];
     int p = 0, q = 0, i, j;

     for (i = 0; i < 5; i++) {
	  l[i] = malloc(sizeof(list));

	  l[i]->p = l[i]->q = 0;
     }

     while (scanf("%s", s) != EOF) {
	  add(l[s[0] - 'C'], s + 3);
     }

     for (i = 0; i < 5; i++) {
	  for (j = 0; j < l[i]->p; j++) {
	       p = maximum(p, sub(l[i]->a[j]));
	       q = maximum(q, file(l[i]->a[j]));
	  }
     }

     printf("%d %d\n", p, q);

     return 0;
}