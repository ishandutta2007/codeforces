#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 102;
const int MaxM = 102;
const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int n, m, k, col[MaxN];
int cost[MaxN][MaxM];

s64 val[MaxN][MaxN][MaxM];
s64 pre[MaxN][MaxN][MaxM];
s64 suf[MaxN][MaxN][MaxM];

inline s64 get_value(int i, int j, int k)
{
	s64 u = pre[i - 1][j - 1][k - 1];
	s64 v = suf[i - 1][j - 1][k + 1];
	s64 w = val[i - 1][j][k];
	return val[i][j][k] = min(min(u, v), w) + cost[i][k];
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		col[i] = getint();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cost[i][j] = getint();

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			for (int k = 0; k <= m + 1; ++k)
			{
				val[i][j][k] = INF;
				pre[i][j][k] = INF;
				suf[i][j][k] = INF;
			}
	val[0][0][0] = suf[0][0][0] = 0;
	for (int i = 0; i <= m; ++i)
		pre[0][0][i] = 0;

	for (int i = 1; i <= n; ++i)
	{
		int up_to = min(i, k);
		for (int j = 1, c; j <= up_to; ++j)
		{
			if ((c = col[i]) > 0)
			{
				get_value(i, j, c);
				val[i][j][c] -= cost[i][c];
			}
			else
			{
				for (int k = 1; k <= m; ++k)
					get_value(i, j, k);
			}

			pre[i][j][0] = INF;
			for (int k = 1; k <= m; ++k)
				pre[i][j][k] = min(val[i][j][k], pre[i][j][k - 1]);
			suf[i][j][m + 1] = INF;
			for (int k = m; k > 0; --k)
				suf[i][j][k] = min(val[i][j][k], suf[i][j][k + 1]);
		}
	}

	cout << (pre[n][k][m] >= INF ? -1 : pre[n][k][m]);

	return 0;
}