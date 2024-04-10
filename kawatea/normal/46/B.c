#include <stdio.h>
#include <string.h>

int main()
{
     int k, x, i, j;
     int n[5];
     char s[5];
     char c[5][5] = {"S", "M", "L", "XL", "XXL"};
     int a[5][5] = {0, 1, 2, 3, 4, 1, 2, 0, 3, 4, 2, 3, 1, 4, 0, 3, 4, 2, 1, 0, 4, 3, 2, 1, 0};

     for (i = 0; i < 5; i++) scanf("%d", &n[i]);

     scanf("%d", &k);

     for (i = 0; i < k; i++) {
	  scanf("%s", s);

	  for (j = 0; j < 5; j++) {
	       if (strcmp(s, c[j]) == 0) break;
	  }

	  x = j;

	  for (j = 0; j < 5; j++) {
	       if (n[a[x][j]] > 0) {
		    n[a[x][j]]--;
		    printf("%s\n", c[a[x][j]]);

		    break;
	       }
	  }
     }

     return 0;
}