#include <cstdio>
#include <vector>

using namespace std;

vector <pair<int, int> > v[100000];
int f[100000];
int g[300000][3];

void dfs(int x)
{
     int i;

     f[x] = 1;

     for (i = 0; i < v[x].size(); i++) {
	  int y = v[x][i].first;
	  int p = 1;

	  if (x > y) p = 2;

	  if (g[v[x][i].second][0] == 0) {
	       g[v[x][i].second][0] = p;

	       if (f[y] == 0) dfs(y);
	  }
     }
}

int dfs2(int x)
{
     int sum = 1, i;

     f[x] = 1;

     for (i = 0; i < v[x].size(); i++) {
	  int y = v[x][i].first;
	  int p = 1;

	  if (x > y) p = 2;

	  if (g[v[x][i].second][0] != p && f[y] == 0) sum += dfs2(y);
     }

     return sum;
}

int main()
{
     int n, m, i;

     scanf("%d %d", &n, &m);

     for (i = 0; i < m; i++) {
	  int x, y;

	  scanf("%d %d", &x, &y);

	  if (x > y) {
	       int tmp = x;
	       x = y;
	       y = tmp;
	  }

	  g[i][1] = x--;
	  g[i][2] = y--;

	  v[x].push_back(make_pair(y, i));
	  v[y].push_back(make_pair(x, i));
     }

     dfs(0);

     for (i = 0; i < n; i++) f[i] = 0;

     if (dfs2(0) < n) {
	  puts("0");

	  return 0;
     }

     for (i = 0; i < m; i++) {
	  if (g[i][0] == 1) {
	       printf("%d %d\n", g[i][1], g[i][2]);
	  } else {
	       printf("%d %d\n", g[i][2], g[i][1]);
	  }
     }

     return 0;
}