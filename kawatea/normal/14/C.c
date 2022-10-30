#include <stdio.h>

int main()
{
     int f = 0, n = 0, i, j;
     int x1[4], y1[4], x2[4], y2[4];
     int p[8][3];

     for (i = 0; i < 4; i++) {
	  scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
     }

     for (i = 0; i < 4; i++) {
	  if ((x1[i] != x2[i] && y1[i] != y2[i]) || (x1[i] == x2[i] && y1[i] == y2[i])) {
	       puts("NO");

	       return 0;
	  }

	  if (x1[i] == x2[i]) f++;

	  for (j = 0; j < n; j++) {
	       if (p[j][0] == x1[i] && p[j][1] == y1[i]) {
		    p[j][2]++;

		    break;
	       }
	  }

	  if (j == n) {
	       p[n][0] = x1[i];
	       p[n][1] = y1[i];
	       p[n++][2] = 1;
	  }

	  for (j = 0; j < n; j++) {
	       if (p[j][0] == x2[i] && p[j][1] == y2[i]) {
		    p[j][2]++;

		    break;
	       }
	  }

	  if (j == n) {
	       p[n][0] = x2[i];
	       p[n][1] = y2[i];
	       p[n++][2] = 1;
	  }
     }

     for (i = 0; i < n; i++) {
	  if (p[i][2] != 2) break;
     }

     if (f != 2 || n != 4 || i < n) {
	  puts("NO");

	  return 0;
     }

     puts("YES");

     return 0;
}