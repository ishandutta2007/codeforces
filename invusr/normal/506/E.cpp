#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

#define optimized __attribute__((optimize("-O2")))
#define inline __inline__ __attribute__((always_inline))

const int M = 10007;
const int MaxNL = 200;

int n, nL, m, nR, nG, nB, len;
char s[MaxNL + 5];

int f[MaxNL + 1][MaxNL + 1][MaxNL + 1];

optimized int solve(const int &nR, const int &l, const int &r)
{
	if (nR < 0)
		return 0;
	int &res = f[nR][l][r];
	if (res != -1)
		return res;
	if (l == r || (r == l + 1 && s[l] == s[r]))
		res = nR == 0;
	else if (s[l] == s[r])
		res = solve(nR, l + 1, r - 1);
	else
	{
		int wL = solve(nR - 1, l + 1, r);
		int wR = solve(nR - 1, l, r - 1);
		if ((res = wL + wR) >= M)
			res -= M;
	}
	return res;
}

struct matrix
{
	int a[MaxNL * 2][MaxNL * 2];

	optimized inline void init()
	{
		for (int i = 1; i <= m; ++i)
		{
			fill(a[i] + 1, a[i] + m + 1, 0);
			a[i][i] = 1;
		}
	}

	optimized friend inline matrix operator*(const matrix &lhs, const matrix &rhs)
	{
		matrix res;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= m; ++j)
			{
				s64 w = 0;
				for (int k = i; k <= j; ++k)
					w += lhs.a[i][k] * rhs.a[k][j];
				res.a[i][j] = w % M;
			}
		return res;
	}

	optimized inline void operator=(const matrix &rhs)
	{
		for (int i = 1; i <= m; ++i)
			copy(rhs.a[i] + 1, rhs.a[i] + m + 1, a[i] + 1);
	}
};
matrix adj, u, v;

optimized inline matrix matpow(matrix a, const int &n)
{
	int k, t = 233333;
	for (int l = 2; l <= 64; ++l)
	{
		int time = 0;
		for (int i = n; i; i /= l)
			time += l - 1 + (i % l != 0);
		if (time < t)
			t = time, k = l;
	}

	matrix res;
	res.init();
	for (int i = n; i; i /= k)
	{
		matrix powT = a;
		for (int j = 2; j <= k; ++j)
		{
			powT = powT * a;
			if (j == i % k)
				res = res * powT;
		}
		if (i % k == 1)
			res = res * a;
		a = powT;
	}
	return res;
}

optimized int main()
{
	scanf("%s%d", s, &n);
	n += (nL = strlen(s));
	nR = nL - 1, nG = nB = nL + 1 >> 1;
	m = nR + nG + nB;
	len = n + 1 >> 1;

	for (int i = 0; i <= nR; ++i)
		for (int j = 0; j < nL; ++j)
			fill(f[i][j] + j, f[i][j] + nL, -1);

	for (int i = 1; i <= nR; ++i)
		adj.a[i][i] = 24;
	for (int i = nR + 1; i <= nR + nG; ++i)
		adj.a[i][i] = 25;
	for (int i = nR + nG + 1; i <= m; ++i)
		adj.a[i][i] = 26;
	for (int i = 1; i < nR + nG; ++i)
		adj.a[i][i + 1] = 1;
	for (int i = nR + 1; i <= nR + nG; ++i)
		adj.a[i][i + nG] = 1;

	u = matpow(adj, len - 1);
	v = u * adj;

	s64 outcome = 0;
	for (int nR = 0; nR <= ::nR; ++nR)
	{
		int nG = (nL - nR + 1) >> 1;
		int nB = len - nR - nG;
		if (nB < 0)
			continue;
		int w = solve(nR, 0, nL - 1);
		outcome += w * v.a[::nR - nR + 1][::nR + ::nG + nG];
		if ((n & 1) && (nL - nR & 1 ^ 1))
			outcome -= w * u.a[::nR - nR + 1][::nR + nG];
	}

	cout << (outcome % M + M) % M;

	return 0;
}