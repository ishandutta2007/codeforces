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

const int MaxN = 1005;
const int INF = 0x3f3f3f3f;

int n;
int w2[MaxN][MaxN];
int w5[MaxN][MaxN];

inline void get_fac(int w, int d, int &f)
{
	if (w == 0)
		f = -1, w = 1;
	while (w % d == 0)
		++f, w /= d;
}

struct item
{
	int w1, w2;

	item() {}
	item(int _w1, int _w2)
		: w1(_w1), w2(_w2) {}

	inline int get_result() const
	{
		return w1 == -1 && w2 == -1 ? INF : min(w1, w2);
	}

	friend inline item operator+(const item &lhs, const item &rhs)
	{
		item res;
		res.w1 = lhs.w1 + rhs.w1;
		res.w2 = lhs.w2 + rhs.w2;
		return res;
	}
	friend inline bool operator<(const item &lhs, const item &rhs)
	{
		if (lhs.w1 == -1)
			return false;
		else if (rhs.w1 == -1)
			return true;

		if (lhs.w1 != rhs.w1)
			return lhs.w1 < rhs.w1;
		return lhs.w2 < rhs.w2;
	}
	friend inline bool operator==(const item &lhs, const item &rhs)
	{
		return lhs.w1 == rhs.w1 && lhs.w2 == rhs.w2;
	}
};
item f[MaxN][MaxN];

int dir[MaxN][MaxN];

item res(-1, -1);
char route[MaxN * 2];

inline void calc(int w1[][MaxN], int w2[][MaxN])
{
	item inv(-1, -1);
	for (int i = 0; i <= n; ++i)
		f[i][0] = f[0][i] = inv;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			item p(w1[i][j], w2[i][j]);
			if (p == inv)
				f[i][j] = inv, dir[i][j] = -1;
			else if (i == 1 && j == 1)
				f[i][j] = p, dir[i][j] = -1;
			else if (f[i - 1][j] == inv && f[i][j - 1] == inv)
				f[i][j] = inv, dir[i][j] = -1;
			else if (f[i - 1][j] < f[i][j - 1])
				f[i][j] = f[i - 1][j] + p, dir[i][j] = 0;
			else
				f[i][j] = f[i][j - 1] + p, dir[i][j] = 1;
		}

	bool ok = true;
	int x = n, y = n;
	static char path[MaxN * 2];
	for (int i = 1; ok && i <= n + n - 2; ++i)
	{
		if (dir[x][y] == 0)
			path[i] = 'D', --x;
		else if (dir[x][y] == 1)
			path[i] = 'R', --y;
		else
			ok = false;
	}
	if (ok && f[n][n].get_result() < res.get_result())
	{
		res = f[n][n];
		for (int i = 1; i <= n + n - 2; ++i)
			route[i] = path[n + n - i - 1];
	}

	x = -1, y = -1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (w1[i][j] == -1 && w2[i][j] == -1)
				x = i, y = j;
	if (x == -1 && y == -1)
		return;

	int t = 0;
	for (int i = 1; i < x; ++i)
		path[++t] = 'D';
	for (int i = 1; i < y; ++i)
		path[++t] = 'R';
	for (int i = x; i < n; ++i)
		path[++t] = 'D';
	for (int i = y; i < n; ++i)
		path[++t] = 'R';
	if (res.get_result() > 1)
	{
		res = item(1, 1);
		for (int i = 1; i <= n + n - 2; ++i)
			route[i] = path[i];
	}
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			int w = getint();
			get_fac(w, 2, w2[i][j]);
			get_fac(w, 5, w5[i][j]);
		}
	for (int i = 0; i <= n; ++i)
	{
		w2[i][0] = w5[i][0] = -1;
		w2[0][i] = w5[0][i] = -1;
	}

	calc(w2, w5);
	calc(w5, w2);

	printf("%d\n", res.get_result());
	printf("%s\n", route + 1);

	return 0;
}