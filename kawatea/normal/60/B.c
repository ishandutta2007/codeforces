#include <stdio.h>

int k, n, m, sum = 0;
int d[6][3] = {0, 0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 0};

void dfs(int z, int x, int y, char s[10][10][11])
{
     int p, q, r, i;

     s[z][x][y] = '#';
     sum++;

     for (i = 0; i < 6; i++) {
	  p = z + d[i][0]; q = x + d[i][1]; r = y + d[i][2];

	  if (p >= 0 && p < k && q >= 0 && q < n && r >= 0 && r < m && s[p][q][r] == '.') {
	       dfs(p, q, r, s);
	  }
     }
}

int main()
{
     int x, y, i, j;
     char s[10][10][11];

     scanf("%d %d %d", &k, &n, &m);

     for (i = 0; i < k; i++) {
	  for (j = 0; j < n; j++) {
	       scanf("%s", s[i][j]);
	  }
     }

     scanf("%d %d", &x, &y);

     x--; y--;

     dfs(0, x, y, s);

     printf("%d\n", sum);

     return 0;
}