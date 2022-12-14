#include <bits/stdc++.h>
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

const int MaxN = 2002;
const int MaxM = 2002;
const int MaxNK = 2002;
const int MaxNL = 2002;
const int MaxNQ = 1000005;

int n, m, nK, q;
int len[MaxNK];
int vx[MaxNK][MaxNL], vy[MaxNK][MaxNL];
int vw[MaxNK][MaxNL];

int type[MaxNQ], tot = 0;
int qxL[MaxN], qyL[MaxN];
int qxR[MaxN], qyR[MaxN];

s64 f[MaxN][MaxN];

inline void bit_add(int x, int y, int w)
{
	for (int i = x; i <= n; i += i & -i)
		for (int j = y; j <= m; j += j & -j)
			f[i][j] += w;
}
inline s64 bit_query(int x, int y)
{
	s64 res = 0;
	for (int i = x; i; i ^= i & -i)
		for (int j = y; j; j ^= j & -j)
			res += f[i][j];
	return res;
}

bool used[MaxNK];

s64 sum[MaxNK][MaxN];

int main()
{
	n = getint(), m = getint(), nK = getint();
	for (int i = 1; i <= nK; ++i)
	{
		len[i] = getint();
		for (int j = 1; j <= len[i]; ++j)
		{
			vx[i][j] = getint(), vy[i][j] = getint();
			vw[i][j] = getint();
		}
	}

	q = getint();
	for (int i = 1; i <= q; ++i)
	{
		char c;
		while ((c = getchar()) != 'A' && c != 'S');

		if (c == 'S')
			type[i] = getint();
		else
		{
			++tot;
			qxL[tot] = getint(), qyL[tot] = getint();
			qxR[tot] = getint(), qyR[tot] = getint();
			type[i] = 0;
		}
	}

	for (int i = 1; i <= nK; ++i)
	{
		for (int j = 1; j <= len[i]; ++j)
			bit_add(vx[i][j], vy[i][j], vw[i][j]);
		for (int j = 1; j <= tot; ++j)
		{
			sum[i][j] += bit_query(qxR[j], qyR[j]);
			sum[i][j] -= bit_query(qxL[j] - 1, qyR[j]);
			sum[i][j] -= bit_query(qxR[j], qyL[j] - 1);
			sum[i][j] += bit_query(qxL[j] - 1, qyL[j] - 1);
		}
		for (int j = 1; j <= len[i]; ++j)
			bit_add(vx[i][j], vy[i][j], -vw[i][j]);
	}

	tot = 0;
	for (int i = 1; i <= q; ++i)
	{
		if (type[i])
			used[type[i]] = !used[type[i]];
		else
		{
			s64 res = 0;

			++tot;
			for (int j = 1; j <= nK; ++j)
			{
				if (used[j])
					continue;
				res += sum[j][tot];
			}
			printf("%I64d\n", res);
		}
	}

	return 0;
}