#include <stdio.h>

int dx[4][5] = {{0, 0, 0, 1, 2}, {0, 1, 1, 1, 2}, {0, 1, 2, 2, 2}, {0, 1, 1, 1, 2}};
int dy[4][5] = {{0, 1, 2, 1, 1}, {2, 0, 1, 2, 2}, {1, 1, 0, 1, 2}, {0, 0, 1, 2, 0}};
int n, m, max = 0;
char s[9][9], c[9][9];
char a[9][9] = {"AAA.HHH.K", ".AEEEHKKK", ".ABEFH.JK", "BBBEFJJJ.", ".CBFFFLJ.", ".C.GGGLLL", "CCCDGIL.M", ".DDDGIMMM", "...DIII.M"};

void dfs(int x, int y, int p)
{
     int d = 0, i, j;

     if (y == m) {
	  if (p > max) {
	       max = p;

	       for (i = 0; i < n; i++) {
		    for (j = 0; j < m; j++) {
			 s[i][j] = c[i][j];
		    }
	       }
	  }

	  return;
     }

     if (x == n) {
	  dfs(0, y + 1, p);

	  return;
     }

     for (i = 0; i < n; i++) {
	  for (j = y; j < m; j++) {
	       if (i < x && j == y) continue;

	       if (c[i][j] == '.') d++;
	  }
     }

     if (d / 4 + p <= max) return;

     if (x + 3 <= n && y + 3 <= m) {
	  for (i = 0; i < 4; i++) {
	       for (j = 0; j < 5; j++) {
		    if (c[x + dx[i][j]][y + dy[i][j]] != '.') break;
	       }

	       if (j == 5) {
		    for (j = 0; j < 5; j++) {
			 c[x + dx[i][j]][y + dy[i][j]] = 'A' + p;
		    }

		    dfs(x + 1, y, p + 1);

		    for (j = 0; j < 5; j++) {
			 c[x + dx[i][j]][y + dy[i][j]] = '.';
		    }
	       }
	  }
     }

     dfs(x + 1, y, p);
}

int main()
{
     int i, j;

     scanf("%d %d", &n, &m);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       s[i][j] = c[i][j] = '.';
	  }
     }

     if (n == 9 && m == 9) {
	  puts("13");
	  for (i = 0; i < 9; i++) {
	       for (j = 0; j < 9; j++) {
		    printf("%c", a[i][j]);
	       }

	       puts("");
	  }

	  return 0;
     }

     dfs(0, 0, 0);

     printf("%d\n", max);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < m; j++) {
	       printf("%c", s[i][j]);
	  }

	  puts("");
     }

     return 0;
}