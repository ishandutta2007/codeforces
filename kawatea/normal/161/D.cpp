#include <cstdio>
#include <vector>

using namespace std;

vector <int> g[50000];
int f[50000];
long long sum;
int k;

vector <int> dfs(int x, vector <int> v)
{
     int i, j;
     vector <int> w = v;

     f[x] = 1;

     sum += v[k - 1];

     for (i = k - 1; i > 0; i--) w[i] = w[i - 1];

     w[0] = 1;

     for (i = 0; i < g[x].size(); i++) {
	  if (f[g[x][i]] == 0) {
	       vector <int> p = dfs(g[x][i], w);

	       for (j = 1; j < k; j++) w[j] += p[j - 1];
	  }
     }

     for (i = 1; i < k; i++) w[i] -= v[i - 1];

     return w;
}

int main()
{
     int n, i;
     vector <int> v;

     scanf("%d %d", &n, &k);

     for (i = 0; i < n - 1; i++) {
	  int x, y;

	  scanf("%d %d", &x, &y);

	  x--;
	  y--;

	  g[x].push_back(y);
	  g[y].push_back(x);
     }

     for (i = 0; i < k; i++) v.push_back(0);

     for (i = 0; i < n; i++) {
	  if (g[i].size() == 1) break;
     }

     dfs(i, v);

     printf("%I64d\n", sum);

     return 0;
}