#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[222222];
int a[222222];

int r = 0;

int f(int x, int y)
{
	int i, t = 0;
	for (i = 0; i < g[x].size(); i++) if (g[x][i] != y) t += f(g[x][i], x);
	if (x == y)
	{
		if (t < 3) return 0;
		r += t - 2;
		return 0;
	}
	if (t < 2) return 1;
	r += t - 1;
	return 0;
}

int main()
{
	int i, j, k, n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	if (n == 2)
	{
		printf("%d", x);
		return 0;
	}
	for (i = 1; i < n; i++)
	{
		scanf("%d%d", &j, &k);
		g[j].push_back(k);
		g[k].push_back(j);
		a[j]++;
		a[k]++;
	}
	if (x < y)
	{
		f(1, 1);
		printf("%I64d", (long long)(n - 1)*x + (long long)r*(y - x));
		return 0;
	}
	j = 0;
	for (i = 1; i <= n; i++) if (a[i] == n - 1) j = 1;
	printf("%I64d", (long long)(n - 1)*y + (long long)j*(x - y));
}