#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const int MaxN = 1000;
const int M = 1000000007;

int n, k;
char s[MaxN + 2];

int bin[MaxN + 1][MaxN + 1];

inline void init_binom(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		bin[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			bin[i][j] = (bin[i - 1][j] + bin[i - 1][j - 1] ) % M;
	}
}

int f[MaxN + 1];
int g[MaxN + 1];

int main()
{
	cin >> s + 1 >> k;
	n = strlen(s + 1);

	init_binom(n);

	g[0] = 0;
	for (int i = 1; i <= n; ++i)
		g[i] = g[i >> 1] + (i & 1);

	f[1] = 0;
	for (int i = 2; i <= n; ++i)
		f[i] = f[g[i]] + 1;

	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (f[i] != k - 1)
			continue;

		for (int j = 1, x = 0; j <= n && x <= i; ++j)
			if (s[j] == '1')
				res = (res + bin[n - j][i - x++]) % M;
	}

	if (f[count(s + 1, s + n + 1, '1')] == k - 1)
		++res;
	if (k <= 1)
		res += k ? -1 : 1;

	cout << res << endl;

	return 0;
}