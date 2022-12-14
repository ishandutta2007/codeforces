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

const int MaxN = 10005;

int n, m;
int p[MaxN], s[MaxN];
s64 f[2][MaxN];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		p[i] = getint();
	for (int i = 1; i <= n; ++i)
		s[i] = getint();

	for (int i = 1; i <= n; ++i)
	{
		int u = i & 1, v = !u;
		f[u][0] = f[v][0] + p[i];
		f[u][i] = f[v][i - 1] + s[i];
		for (int j = 1; j < i; ++j)
			f[u][j] = min(f[v][j - 1] + s[i], f[v][j] + p[i] + (s64)j * m);
	}

	cout << *min_element(f[n & 1], f[n & 1] + n + 1);
	cout << endl;

	return 0;
}