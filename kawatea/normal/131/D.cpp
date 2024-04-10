#include <cstdio>
#include <vector>

using namespace std;

vector <int> a[3000];
int v[3000];
int p[3000];
int f[3000];
int d[3000];

int dfs(int x, int y)
{
     int i;

     if (v[x] == 1) {
	  int tmp = y;

	  f[x] = 1;

	  while (tmp != x) {
	       f[tmp] = 1;

	       tmp = p[tmp];
	  }

	  return 1;
     }

     v[x] = 1;
     p[x] = y;

     for (i = 0; i < a[x].size(); i++) {
	  if (a[x][i] == y) continue;

	  if (dfs(a[x][i], x) == 1) return 1;
     }

     return 0;
}

int dfs2(int x, int y)
{
     int tmp, i;

     if (d[x] >= 0) return d[x];

     if (f[x] == 1) return d[x] = 0;

     for (i = 0; i < a[x].size(); i++) {
	  if (a[x][i] == y) continue;

	  tmp = dfs2(a[x][i], x);

	  if (tmp >= 0) return d[x] = tmp + 1;
     }

     return -1;
}

int main()
{
     int n, i;

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  int x, y;

	  scanf("%d %d", &x, &y);

	  x--;
	  y--;

	  a[x].push_back(y);
	  a[y].push_back(x);
     }

     dfs(0, -1);

     for (i = 0; i < n; i++) d[i] = -1;

     for (i = 0; i < n; i++) {
	  if (d[i] < 0) dfs2(i, -1);
     }

     for (i = 0; i < n; i++) {
	  if (i > 0) putchar(' ');

	  printf("%d", d[i]);
     }

     puts("");

     return 0;
}