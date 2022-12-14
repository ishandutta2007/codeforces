#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef double r32;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 1005;

int n, m;
int init[MaxN];

r32 pro[MaxN][MaxN];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		init[i] = getint();

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			pro[i][j] = init[i] > init[j];

	while (m--)
	{
		int u = getint(), v = getint();

		pro[u][v] = pro[v][u] = 0.5;
		for (int i = 1; i <= n; ++i)
		{
			if (i == u || i == v)
				continue;
			pro[i][u] = pro[i][v] = (pro[i][u] + pro[i][v]) * 0.5;
			pro[u][i] = pro[v][i] = (pro[u][i] + pro[v][i]) * 0.5;
		}
	}

	r32 res = 0.0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			res += pro[i][j];

	printf("%.16f\n", res);

	return 0;
}