#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxN = 4005;
const int M = 1000000009;

int n, u, v;
int binom[MaxN][MaxN];

int main()
{
	cin >> n >> u >> v;

	for (int i = 0; i <= max(max(u, v), n); ++i)
	{
		binom[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
			binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
			if (binom[i][j] >= M)
				binom[i][j] -= M;
		}
	}

	int res = 0;
	for (int i = 1; i <= n - 2; ++i)
		for (int j = i + 1; j <= n - 1; ++j)
			res = (res + (s64)binom[v - 1][j - i - 1] * binom[u - 1][n - j + i - 1]) % M;
	for (int i = 2; i <= u; ++i)
		res = (s64)res * i % M;
	for (int i = 2; i <= v; ++i)
		res = (s64)res * i % M;

	cout << res << endl;

	return 0;
}