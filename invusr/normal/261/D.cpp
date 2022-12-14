#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

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

int t, n, m, k;
int a[MaxN], b[MaxN], l[MaxN];

int main()
{
	t = getint(), n = getint();
	m = getint(), k = getint();
	k = min(k, m);
	k = min(k, n);

	while (t--)
	{
		fill(l + 1, l + m + 1, 0);
		for (int i = 1; i <= n; ++i)
			a[i] = getint();

		int res = 0;
		for (int now = 0; now < k; ++now)
			for (int i = 1; i <= n; ++i)
			{
				int &x = l[a[i]];
				while (b[x] < a[i] && x <= res)
					++x;
				res = max(res, x), b[x] = a[i];
			}

		cout << res << endl;
	}

	return 0;
}