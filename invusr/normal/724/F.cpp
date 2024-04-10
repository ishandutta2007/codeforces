#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxN = 1005;
const int MaxD = 11;

int n, d, mod;
int inv[MaxN];

int f[MaxN][MaxD][MaxN];

int main()
{
	cin >> n >> d >> mod;
	if (n <= 2)
	{
		puts("1");
		return 0;
	}

	inv[1] = 1;
	for (int i = 2; i <= n; ++i)
		inv[i] = (s64)(mod - mod / i) * inv[mod % i] % mod;

	f[1][0 + 0][0] = 1;
	f[1][d - 1][0] = 1;
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j <= d; ++j)
			for (int k = 1; k < i; ++k)
			{
				f[i][j][k] = f[i][j][k - 1];
				int coe = 1;
				int now = f[k][d - 1][k - 1] - 1;
				for (int t = 1; t * k < i && t <= j; ++t)
				{
					coe = (s64)coe * ++now % mod * inv[t] % mod;
					f[i][j][k] += (s64)coe * f[i - t * k][j - t][min(k - 1, i - t * k - 1)] % mod;
					if (f[i][j][k] >= mod)
						f[i][j][k] -= mod;
				}
			}

	int res = f[n][d][(n + 1) / 2 - 1];
	if (~n & 1)
	{
		int l = f[n / 2][d - 1][n / 2 - 1];
		res = (res + (s64)l * (l + 1) / 2) % mod;
	}

	cout << res << endl;

	return 0;
}