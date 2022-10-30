#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int> > v[100000];
int f[100000];
int d[100000];

void dfs(int x)
{
     int i;

     for (i = 0; i < v[x].size(); i++) {
	  if (f[v[x][i].first] == 0) {
	       d[v[x][i].first] = d[x] + v[x][i].second;
	       f[v[x][i].first] = 1;

	       dfs(v[x][i].first);
	  }
     }
}

int main()
{
     int n, i, j;
     long long sum = 0;

     scanf("%d", &n);

     for (i = 0; i < n - 1; i++) {
	  int x, y, w;

	  scanf("%d %d %d", &x, &y, &w);

	  v[x - 1].push_back(make_pair(y - 1, w));
	  v[y - 1].push_back(make_pair(x - 1, w));

	  sum += w * 2;
     }

     f[0] = 1;

     dfs(0);

     sort(d, d + n);

     sum -= d[n - 1];

     printf("%I64d\n", sum);

     return 0;
}