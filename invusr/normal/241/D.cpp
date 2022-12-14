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

const int MaxN = 50005;
const int MaxM = 50005;
const int MaxTN = 32;

int n, m, tn;
int a[MaxN], b[MaxTN];
bool del[MaxN];

bool f[MaxTN][MaxTN][MaxM];

inline void solve()
{
	int u = 0, v = 0;
	for (int i = tn; i >= 1; --i)
	{
		int x = a[b[i]];

		bool ok = false;
		for (int k = 0; k < m; ++k)
			if (f[i - 1][u ^ x][k] && (k * (x < 10 ? 10 : 100) + x) % m == v)
			{
				v = k, u ^= x;
				ok = true;
				break;
			}
		if (ok)
			continue;

		if (f[i - 1][u][v])
			del[b[i]] = true;
		else
		{
			puts("No");
			return;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		cnt += !del[i];
	if (!cnt)
	{
		puts("No");
		return;
	}

	printf("Yes\n%d\n", cnt);
	for (int i = 1; i <= n; ++i)
		if (!del[i])
			printf("%d ", i);
}

int main()
{
	n = getint(), m = getint();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = getint();
		if (a[i] < 32)
			b[++tn] = i;
		else
			del[i] = true;
	}

	f[0][0][0] = true;
	for (int i = 1; i <= tn; ++i)
	{
		int x = a[b[i]];
		for (int j = 0; j < 32; ++j)
			for (int k = 0; k < m; ++k)
			{
				int u = j ^ x;
				int v = (k * (x < 10 ? 10 : 100) + x) % m;
				if (f[i - 1][j][k])
					f[i][u][v] = f[i][j][k] = true;
			}
	}

	solve();

	return 0;
}