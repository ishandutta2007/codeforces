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

const int MaxN = 3005;

int n, a[MaxN];
int m, b[MaxN];
s64 f[MaxN][MaxN];

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = getint() - i;
		b[i] = a[i];
	}

	sort(b + 1, b + n + 1);
	m = unique(b + 1, b + n + 1) - b - 1;

	f[1][1] = abs(a[1] - b[1]);
	for (int j = 2; j <= m; ++j)
		f[1][j] = min(f[1][j - 1], (s64)abs(a[1] - b[j]));
	for (int i = 2; i <= n; ++i)
	{
		f[i][1] = f[i - 1][1] + abs(a[i] - b[1]);
		for (int j = 2; j <= m; ++j)
			f[i][j] = min(f[i][j - 1], f[i - 1][j] + abs(a[i] - b[j]));
	}

	cout << f[n][m] << endl;

	return 0;
}