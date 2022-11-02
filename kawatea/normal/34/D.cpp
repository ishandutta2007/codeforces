#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[50001];
int p[50001];

void dfs(int x, int y)
{
     int i;

     p[x] = y;

     for (i = 0; i < v[x].size(); i++) {
	  if (v[x][i] == y) continue;

	  dfs(v[x][i], x);
     }
}

int main()
{
     int n, r1, r2, x, f = 0, i;

     scanf("%d %d %d", &n, &r1, &r2);

     for (i = 1; i < n; i++) {
	  scanf("%d", &x);

	  if (i < r1) {
	       v[i].push_back(x);
	       v[x].push_back(i);
	  } else {
	       v[i + 1].push_back(x);
	       v[x].push_back(i + 1);
	  }
     }

     dfs(r2, r2);

     for (i = 1; i <= n; i++) {
	  if (i == r2) continue;

	  if (f == 1) putchar(' ');

	  printf("%d", p[i]);

	  f = 1;
     }
     puts("");

     return 0;
}