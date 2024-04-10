#include <stdio.h>

int r[1000][1000][2];
int p[1000];
int b[1000];

void dfs(int x, int y)
{
     int i;

     for (i = 0; i < p[x]; i++) {
	  if (b[r[x][i][0]] == -1) {
	       if (r[x][i][1] <= y) {
		    b[r[x][i][0]] = y - r[x][i][1];

		    dfs(r[x][i][0], y - r[x][i][1]);
	       }
	  } else {
	       if (r[x][i][1] <= y && b[r[x][i][0]] < y - r[x][i][1]) {
		    b[r[x][i][0]] = y - r[x][i][1];

		    dfs(r[x][i][0], y - r[x][i][1]);
	       }
	  }
     }
}

long long min(long long a, long long b)
{
     if (a < b) {
	  return a;
     } else {
	  return b;
     }
}

int main()
{
     int n, m, x, y, i, j;
     int t[1000], c[1000], f[1000] = {0};
     long long a[1000];

     scanf("%d %d", &n, &m);
     scanf("%d %d", &x, &y);

     for (i = 0; i < n; i++) a[i] = 1e18;

     x--; y--;

     for (i = 0; i < m; i++) {
	  int u, v, w;

	  scanf("%d %d %d", &u, &v, &w);

	  u--; v--;

	  for (j = 0; j < p[u]; j++) {
	       if (r[u][j][0] == v) {
		    r[u][j][1] = min(r[u][j][1], w);

		    break;
	       }
	  }

	  if (j == p[u]) {
	       r[u][p[u]][0] = v;
	       r[u][p[u]++][1] = w;
	  }

	  for (j = 0; j < p[v]; j++) {
	       if (r[v][j][0] == u) {
		    r[v][j][1] = min(r[v][j][1], w);

		    break;
	       }
	  }

	  if (j == p[v]) {
	       r[v][p[v]][0] = u;
	       r[v][p[v]++][1] = w;
	  }
     }

     for (i = 0; i < n; i++) scanf("%d %d", &t[i], &c[i]);

     a[x] = 0;

     for (i = 0; ; i++) {
	  long long minimum = 1e18;
	  int num = -1;

	  for (j = 0; j < n; j++) b[j] = -1;

	  for (j = 0; j < n; j++) {
	       if (f[j] == 0 && a[j] < minimum) {
		    minimum = a[j];
		    num = j;
	       }
	  }

	  if (num == -1) break;

	  f[num] = 1;
	  b[num] = t[num];

	  dfs(num, t[num]);

	  for (j = 0; j < n; j++) {
	       if (b[j] >= 0) a[j] = min(a[j], a[num] + c[num]);
	  }
     }

     if (a[y] == 1e18) {
	  puts("-1");
     } else {
	  printf("%I64d\n", a[y]);
     }

     return 0;
}