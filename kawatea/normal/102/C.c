#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
     int x;
     int i;
} character;

int cmp(const void *a, const void *b)
{
     return ((character *)a)->x - ((character *)b)->x;
}

int main()
{
     char s[100005];
     int n, k, m = 0, i;
     int a[26][2] = {0};
     character b[26];

     for (i = 0; i < 26; i++) {
	  b[i].x = 0;
	  b[i].i = i;
     }

     scanf("%s", s);
     scanf("%d", &k);

     n = strlen(s);

     for (i = 0; i < n; i++) {
	  a[s[i] - 'a'][0]++;
	  b[s[i] - 'a'].x++;
     }

     qsort(b, 26, sizeof(character), cmp);

     for (i = 0; i < 26; i++) {
	  k -= b[i].x;

	  if (k < 0) {
	       m = 26 - i;
	       break;
	  } else {
	       a[b[i].i][1] = 1;
	  }
     }

     printf("%d\n", m);

     for (i = 0; i < n; i++) {
	  if (a[s[i] - 'a'][1] == 0) {
	       putchar(s[i]);
	  }
     }
     puts("");

     return 0;
}