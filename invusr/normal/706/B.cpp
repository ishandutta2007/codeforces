#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100005;

int n, q, a[MaxN];

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		a[i] = getint();

	sort(a + 1, a + n + 1);

	q = getint();
	while (q--)
	{
		int x = getint();
		printf("%d\n", upper_bound(a + 1, a + n + 1, x) - a - 1);
	}

	return 0;
}