#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxN = 55;
const int M = 1000000007;
const int I2 = M + 1 >> 1;

inline int modpow(int a, const int &n)
{
	int res = 1;
	for (int i = n; i; i >>= 1)
	{
		if (i & 1)
			res = (s64)res * a % M;
		a = (s64)a * a % M;
	}
	return res;
}

int n;
int d[MaxN];

int f[MaxN][MaxN][MaxN];
int g[MaxN][MaxN];

int fact[MaxN];
int rfact[MaxN];

inline int binom(int n, int m)
{
	return (s64)fact[n] * rfact[m] % M * rfact[n - m] % M;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> d[i];

	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = (s64)fact[i - 1] * i % M;
	rfact[n] = modpow(fact[n], M - 2);
	for (int i = n; i >= 1; --i)
		rfact[i - 1] = (s64)rfact[i] * i % M;

	f[0][0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 2; j < i; ++j)
			f[0][0][i] = (f[0][0][i] + (s64)f[0][0][i - j - 1] * binom(i - 1, j) % M * fact[j] % M * I2) % M;

	for (int i = 1; i <= n; ++i)
		for (int j = i == 0; j <= n - i; ++j)
		{
			if (i >= 2)
				f[0][i][j] = (f[0][i][j] + (s64)(i - 1) * f[0][i - 2][j]) % M;
			if (j >= 1)
				f[0][i][j] = (f[0][i][j] + (s64)j * f[0][i][j - 1]) % M;
		}

	for (int i = 1; i < n; ++i)
		for (int s = 0; s < n - i; ++s)
			for (int k = 0; k <= s; ++k)
			{
				int j = s - k;
				if (j >= 1)
					f[i][j][k] = (f[i][j][k] + (s64)j * f[i - 1][j - 1][k]) % M;
				if (k >= 1)
					f[i][j][k] = (f[i][j][k] + (s64)k * f[i - 1][j + 1][k - 1]) % M;
			}

	g[d[1] + 1][d[1]] = 1;
	for (int i = d[1] + 2; i <= n; ++i)
		for (int j = 1; j <= i - d[1] - 1; ++j)
		{
			int c2 = 0, c3 = 0;
			for (int k = 1; k < i - j; ++k)
			{
				d[i - j - k + 1] == 2 ? ++c2 : ++c3;
				g[i][j] = (g[i][j] + (s64)g[i - j][k] * f[j][c2][c3]) % M;
			}
		}

	int res = 0, c2 = 0, c3 = 0;
	for (int i = 1; i < n; ++i)
	{
		d[n - i + 1] == 2 ? ++c2 : ++c3;
		res = (res + (s64)g[n][i] * f[0][c2][c3]) % M;
	}

	cout << res << endl;

	return 0;
}