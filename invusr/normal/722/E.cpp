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

const int MaxN = 100005;
const int MaxM = 100005;
const int MaxNK = 2005;
const int MaxNT = 21;
const int M = 1000000007;

inline int modpow(int a, const int &n)
{
	int res = 1;
	for (int i = n; i; i >>= 1)
	{
		if (i & 1)
			res = (s64)res * a % M;
		a = (s64) a * a % M;
	}
	return res;
}

int n, m, nK, w;

struct point
{
	int x, y;

	friend inline bool operator<(const point &lhs, const point &rhs)
	{
		if (lhs.x != rhs.x)
			return lhs.x < rhs.x;
		return lhs.y < rhs.y;
	}
};
point po[MaxNK];

int fact[MaxN * 2];
int rfact[MaxN * 2];

int f[MaxNK][MaxNT];
int ways[MaxNK][MaxNK];

inline void init(const int &n)
{
	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = (s64)fact[i - 1] * i % M;
	rfact[n] = modpow(fact[n], M - 2);
	for (int i = n; i; --i)
		rfact[i - 1] = (s64)rfact[i] * i % M;
}

inline int get_binom(int n, int m)
{
	return (s64)fact[n] * rfact[m] % M * rfact[n - m] % M;
}

int main()
{
	init(200000);

	cin >> n >> m >> nK >> w;
	for (int i = 0; i < nK; ++i)
		po[i].x = getint(), po[i].y = getint();
	po[nK].x = 1, po[nK++].y = 1;
	po[nK].x = n, po[nK++].y = m;

	sort(po, po + nK);

	for (int i = 0; i < nK; ++i)
		for (int j = i + 1; j < nK; ++j)
		{
			int u = po[j].x - po[i].x;
			int v = po[j].y - po[i].y;
			if (u >= 0 && v >= 0)
				ways[i][j] = get_binom(u + v, u);
		}

	f[0][0] = 1;
	for (int i = 1; i < nK; ++i)
		for (int j = 0; j <= 20; ++j)
		{
			f[i][j] = ways[0][i];
			for (int k = 0; k < j; ++k)
				f[i][j] = (f[i][j] + M - f[i][k]) % M;
			for (int k = 0; k < i; ++k)
				if (f[k][j] && ways[k][i])
					f[i][j] = ((f[i][j] - (s64)f[k][j] * ways[k][i]) % M + M) % M;
		}

	int res = 0;
	int sum = ways[0][nK - 1];
	for (int i = 1; i <= 20; ++i)
	{
		res = (res + (s64)w * f[nK - 1][i]) % M;
		sum = (sum + M - f[nK - 1][i]) % M;
		w = w + 1 >> 1;
	}
	res = (res + sum) % M;
	res = (s64)res * modpow(ways[0][nK - 1], M - 2) % M;

	cout << res << endl;

	return 0;
}