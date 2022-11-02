#include <stdio.h>

int max(int a, int b)
{
     if (a > b) {
	  return a;
     } else {
	  return b;
     }
}

int min(int a, int b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     char s[4][3];
     int p, q, i, j, k;
     int a[8][8] = {0};
     int b[2][2];

     for (i = 0; i < 4; i++) scanf("%s", s[i]);

     p = s[2][0] - 'a';
     q = s[2][1] - '1';

     for (i = p - 1; i <= p + 1; i++) {
	  for (j = q - 1; j <= q + 1; j++) {
	       if (i >= 0 && i < 8 && j >= 0 && j < 8) a[i][j] = 1;
	  }
     }

     for (i = 0; i < 2; i++) {
	  b[i][0] = s[i][0] - 'a';
	  b[i][1] = s[i][1] - '1';

	  for (j = b[i][0]; j >= 0; j--) {
	       a[j][b[i][1]]++;

	       if (j == p && b[i][1] == q) break;
	  }

	  for (j = b[i][0] + 1; j < 8; j++) {
	       a[j][b[i][1]]++;

	       if (j == p && b[i][1] == q) break;
	  }

	  for (j = b[i][1] - 1; j >= 0; j--) {
	       a[b[i][0]][j]++;

	       if (b[i][0] == p && j == q) break;
	  }

	  for (j = b[i][1] + 1; j < 8; j++) {
	       a[b[i][0]][j]++;

	       if (b[i][0] == p && j == q) break;
	  }
     }

     p = s[3][0] - 'a';
     q = s[3][1] - '1';

     if (a[p][q] == 0) {
	  puts("OTHER");

	  return 0;
     }

     for (i = p - 1; i <= p + 1; i++) {
	  for (j = q - 1; j <= q + 1; j++) {
	       if (i >= 0 && i < 8 && j >= 0 && j < 8) {
		    if (a[i][j] == 0) {
			 puts("OTHER");

			 return 0;
		    }

		    for (k = 0; k < 2; k++) {
			 if (i == b[k][0] && j == b[k][1]) {
			      if (a[i][j] == 1) {
				   puts("OTHER");

				   return 0;
			      }
			 }
		    }
	       }
	  }
     }

     puts("CHECKMATE");

     return 0;
}