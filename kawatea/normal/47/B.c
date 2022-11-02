#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return *((int *)a) - *((int *)b);
}

int main()
{
     char s[3][5];
     int i, j;
     int a[3] = {0};
     int b[3];

     for (i = 0; i < 3; i++) scanf("%s", s[i]);

     for (i = 0; i < 3; i++) {
	  if (s[i][1] == '<') {
	       a[s[i][0] - 'A']++;
	  } else {
	       a[s[i][2] - 'A']++;
	  }
     }

     for (i = 0; i < 3; i++) b[i] = a[i];

     qsort(b, 3, sizeof(int), cmp);

     if (b[0] == 1) {
	  puts("Impossible");
     } else {
	  for (i = 2; i >= 0; i--) {
	       for (j = 0; j < 3; j++) {
		    if (a[j] == i) printf("%c", 'A' + j);
	       }
	  }
	  puts("");
     }

     return 0;
}