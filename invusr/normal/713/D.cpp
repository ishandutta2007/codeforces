#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 1001;
const int MaxM = 1001;
const int MaxLogN = 11;
const int MaxLogM = 11;

int n, m, nT;
int go[MaxN][MaxM][2];

int logTab[MaxN];
int st[MaxLogN][MaxLogM][MaxN][MaxM];

inline int query(int x1, int y1, int x2, int y2)
{
	int l1 = logTab[x2 - x1 + 1];
	int l2 = logTab[y2 - y1 + 1];
	int p1 = st[l1][l2][x1][y1];
	int p2 = st[l1][l2][x2 - (1 << l1) + 1][y1];
	int p3 = st[l1][l2][x1][y2 - (1 << l2) + 1];
	int p4 = st[l1][l2][x2 - (1 << l1) + 1][y2 - (1 << l2) + 1];
	return max(max(p1, p2), max(p3, p4));
}

int main()
{
	logTab[1] = 0;
	for (int i = 2; i <= 1000; ++i)
		logTab[i] = logTab[i >> 1] + 1;

	n = getint(), m = getint();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			int w = getint();
			if (!w)
				go[i][j][0] = go[i][j][1] = st[0][0][i][j] = 0;
			else
			{
				go[i][j][0] = go[i - 1][j][0] + 1;
				go[i][j][1] = go[i][j - 1][1] + 1;
				st[0][0][i][j] = min(go[i][j][0], go[i][j][1]);
				st[0][0][i][j] = min(st[0][0][i][j], st[0][0][i - 1][j - 1] + 1);
			}
		}

	for (int l1 = 0; l1 <= logTab[n]; ++l1)
		for (int l2 = 0; l2 <= logTab[m]; ++l2)
		{
			int k1 = 1 << l1, h1 = 1 << l1 - 1;
			int k2 = 1 << l2, h2 = 1 << l2 - 1;
			if (l1 == 0 && l2 == 0)
				continue;
			for (int i = 1; i + k1 - 1 <= n; ++i)
				for (int j = 1; j + k2 - 1 <= m; ++j)
				{
					if (l1 != 0)
					{
						int l = st[l1 - 1][l2][i][j];
						int r = st[l1 - 1][l2][i + h1][j];
						st[l1][l2][i][j] = max(l, r);
					}
					else
					{
						int l = st[l1][l2 - 1][i][j];
						int r = st[l1][l2 - 1][i][j + h2];
						st[l1][l2][i][j] = max(l, r);
					}
				}
		}

	nT = getint();
	while (nT--)
	{
		int x1 = getint(), y1 = getint();
		int x2 = getint(), y2 = getint();

		int l = 1, r = min(x2 - x1, y2 - y1) + 1;
		while (l <= r)
		{
			int mid = l + r >> 1;
			int x3 = x1 + mid - 1;
			int y3 = y1 + mid - 1;
			if (query(x3, y3, x2, y2) >= mid)
				l = mid + 1;
			else
				r = mid - 1;
		}
		printf("%d\n", r);
	}

	return 0;
}