#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;
typedef double r32;

const int MaxN = 1005;
const int M = 1000000007;
const r32 eps = 1e-8;
const r32 INF = 1e100;

inline bool equal(r32 a, r32 b)
{
	return fabs(a - b) < eps;
}

int n, m = 0;
r32 dx[MaxN], dy[MaxN];

struct line
{
	r32 x, y, k;
	line() {}
	line(const r32 &_x, const r32 &_y, const r32 &_k)
		: x(_x), y(_y), k(_k) {}

	friend inline bool operator<(const line &lhs, const line &rhs)
	{
		if (!equal(lhs.x, rhs.x))
			return lhs.x < rhs.x;
		if (!equal(lhs.y, rhs.y))
			return lhs.y < rhs.y;
		return lhs.k < rhs.k;
	}
};
line l[MaxN * MaxN / 2];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		r32 x = (r32)a / b;
		r32 y = (r32)c / d;
		r32 len = x * x + y * y;
		dx[i] = x / len;
		dy[i] = y / len;
	}

	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			r32 x = dx[i] + dx[j];
			r32 y = dy[i] + dy[j];
			r32 k = equal(dx[i], dx[j]) ? INF : (dy[i] - dy[j]) / (dx[i] - dx[j]);
			l[m++] = line(x, y, k);
		}

	sort(l, l + m);

	int res = 0;
	for (int i = 0, k; i < m; i = k)
	{
		k = i;
		while (k < m && equal(l[i].x, l[k].x) && equal(l[i].y, l[k].y))
			++k;

		int now = 1, cur = 1;
		for (int j = i + 1; j < k; ++j)
		{
			if (equal(l[j - 1].k, l[j].k))
				++now;
			else
			{
				cur = (s64)cur * (now + 1) % M;
				now = 1;
			}
		}
		cur = (s64)cur * ++now % M;

		res = (res + cur) % M;
		res = (res - k + i - 1) % M;
	}

	cout << (res + M) % M << endl;

	return 0;
}