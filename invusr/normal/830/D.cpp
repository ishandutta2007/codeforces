#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const int MaxN = 400;
const int M = 1000000007;

int n;
int f[MaxN + 1][MaxN + 1];

int main()
{
	cin >> n;

	f[1][0] = f[1][1] = 1;
	for (int i = 2; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			for (int k = 0; j + k <= n; ++k)
			{
				int l = j + k;
				int v = (s64)f[i - 1][j] * f[i - 1][k] % M;
				f[i][l] = (f[i][l] + (s64)v * (l * 2 + 1)) % M;
				if (l > 0)
					f[i][l - 1] = (f[i][l - 1] + (s64)v * l % M * (l - 1)) % M;
				if (l < n)
					f[i][l + 1] = (f[i][l + 1] + v) % M;
			}

	cout << f[n][1] << endl;

	return 0;
}