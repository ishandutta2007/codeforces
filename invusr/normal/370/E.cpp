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

const int MaxN = 200000;

int n;
int col[MaxN + 1];

struct state
{
	int x, l;
	state() {}
	state(const int &_x, const int &_l)
		: x(_x), l(_l) {}

	friend inline bool operator<(const state &lhs, const state &rhs)
	{
		if (lhs.x != rhs.x)
			return lhs.x < rhs.x;
		return lhs.l < rhs.l;
	}
};
state lower[MaxN + 1], upper[MaxN + 1];

int used[MaxN + 1];

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		col[i] = getint();

	if (col[1] > 1)
	{
		printf("-1\n");
		return 0;
	}

	lower[1] = state(1, 1);
	upper[1] = state(1, 1);
	for (int i = 2; i <= n; ++i)
	{
		lower[i] = lower[i - 1];
		if (++lower[i].l > 5)
			++lower[i].x, lower[i].l = 1;

		upper[i] = upper[i - 1];
		if (++upper[i].l > 2)
			++upper[i].x, upper[i].l = 1;

		if (col[i] > 0)
		{
			state l(col[i], 1);
			state r(col[i], 5);
			lower[i] = max(lower[i], l);
			upper[i] = min(upper[i], r);

			if (lower[i].x > col[i] || upper[i].x < col[i])
			{
				printf("-1\n");
				return 0;
			}
		}
	}

	state res = upper[n];
	if (res.l == 1)
		res.l = 5, --res.x;
	if (res < lower[n])
	{
		printf("-1\n");
		return 0;
	}

	used[col[n] = res.x] = 1;
	for (int i = n - 1; i >= 1; --i)
	{
		col[i] = min(col[i + 1], upper[i].x);
		col[i] -= used[col[i]] == 5;
		++used[col[i]];
	}

	printf("%d\n", res.x);
	for (int i = 1; i <= n; ++i)
		printf("%d ", col[i]);

	return 0;
}