#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;
using u32 = unsigned;

const int MaxN = 200;
const int MaxD = MaxN - 1;

int n, d;
u32 m;

u32 f[MaxN + 1][MaxD + 1];
u32 g[MaxN + 1][MaxD + 1];

u32 bin[MaxN + 1][MaxN + 1];

int main()
{
	cin >> n >> d >> m;

	for (int i = 0; i <= n; ++i)
	{
		bin[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			bin[i][j] = (bin[i - 1][j] + bin[i - 1][j - 1]) % m;
	}

	f[1][0] = 1;
	for (int i = 0; i <= d; ++i)
		g[1][i] = 1;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= d; ++j)
			for (int k = 1; k < i; ++k)
				f[i][j] = (f[i][j] + (u64)bin[i - 2][k - 1] * f[i - k][j - 1] % m * g[k][d - 1]) % m;

		for (int j = 1; j <= d; ++j)
			g[i][j] = (g[i][j - 1] + f[i][j]) % m;
	}

	u32 res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= d; ++j)
			for (int k = 0; j + k <= d; ++k)
				if (k != 1)
					res = (res + (u64)f[i + 1][j] * f[n - i][k]) % m;

	cout << 2ull * n * (n - 1) % m * res % m << endl;

	return 0;
}