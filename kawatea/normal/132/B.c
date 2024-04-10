#include <stdio.h>
#include <string.h>

typedef struct {
     int x;
     int y;
     int dp;
     int cp;
} point;

point p[50][50][4][2];

int main()
{
     int m, n, w, h, x, y, dp, cp, i, j, k, l;
     char s[52][52];
     int d1[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
     int d2[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};

     for (i = 0; i <= 51; i++) {
	  for (j = 0; j <= 51; j++) {
	       s[i][j] = '0';
	  }
     }

     scanf("%d %d", &m, &n);

     for (i = 1; i <= m; i++) scanf("%s", &s[i][1]);

     w = m;
     h = strlen(s[1]) - 1;

     for (i = 1; i <= w; i++) s[i][h + 1] = '0';

     for (i = 0; i < w; i++) {
	  for (j = 0; j < h; j++) {
			 if (s[i + 1][j + 1] == '0') continue;

			 for (k = 0; k < 4; k++) {
			      for (l = 0; l < 2; l++) {
				   x = i + 1;
				   y = j + 1;

				   while (s[x + d1[k][0]][y + d1[k][1]] == s[i + 1][j + 1]) {
					x += d1[k][0];
					y += d1[k][1];
				   }

				   while (s[x + d2[(k + l * 2) % 4][0]][y + d2[(k + l * 2) % 4][1]] == s[i + 1][j + 1]) {
					x += d2[(k + l * 2) % 4][0];
					y += d2[(k + l * 2) % 4][1];
				   }

				   x += d1[k][0];
				   y += d1[k][1];

				   if (s[x][y] == '0') {
					p[i][j][k][l].x = i;
					p[i][j][k][l].y = j;

					if (l == 0) {
					     p[i][j][k][l].dp = k;
					     p[i][j][k][l].cp = 1;
					} else {
					     p[i][j][k][l].dp = (k + 1) % 4;
					     p[i][j][k][l].cp = 0;
					}
				   } else {
					p[i][j][k][l].x = x - 1;
					p[i][j][k][l].y = y - 1;
					p[i][j][k][l].dp = k;
					p[i][j][k][l].cp = l;
				   }
			      }
			 }
	  }
     }

     x = 0;
     y = 0;
     dp = 2;
     cp = 0;

     for (i = 0; i < n; i++) {
	  point tmp = p[x][y][dp][cp];

	  x = tmp.x;
	  y = tmp.y;
	  dp = tmp.dp;
	  cp = tmp.cp;
     }

     printf("%d\n", s[x + 1][y + 1] - '0');

     return 0;
}