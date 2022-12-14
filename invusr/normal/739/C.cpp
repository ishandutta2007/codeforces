#include <algorithm>
#include <iostream>
#include <cassert>
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

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

const int MaxN = 300005;
const int MaxM = 300005;
const int MaxSegN = MaxN * 4;

int n, m;
s64 height[MaxN];

struct seg_info
{
	int whole;
	int black_r, white_l;
	int total_l, total_r, total;
	int l, r;

	seg_info() {}
	seg_info(int x, s64 w)
	{
		l = r = x;
		whole = w < 0 ? -1 : (w > 0 ? 1 : 0);
		black_r = whole == +1;
		white_l = whole == -1;
		total_l = total_r = total = whole != 0;
	}

	friend inline seg_info operator+(const seg_info &lhs, const seg_info &rhs)
	{
		assert(lhs.r + 1 == rhs.l);
		seg_info res;
		res.l = lhs.l, res.r = rhs.r;
		res.whole = lhs.whole == rhs.whole ? lhs.whole : 0;
		res.black_r = (rhs.whole == +1 ? lhs.black_r : 0) + rhs.black_r;
		res.white_l = (lhs.whole == -1 ? rhs.white_l : 0) + lhs.white_l;
		res.total_l = (lhs.total_l == lhs.r - lhs.l + 1 ? (lhs.whole == +1 ? rhs.total_l : rhs.white_l) : 0) + lhs.total_l;
		res.total_r = (rhs.total_r == rhs.r - rhs.l + 1 ? (rhs.whole == -1 ? lhs.total_r : lhs.black_r) : 0) + rhs.total_r;
		res.total = max(lhs.total, rhs.total);
		relax(res.total, lhs.total_r + rhs.white_l);
		relax(res.total, rhs.total_l + lhs.black_r);
		return res;
	}
};
seg_info seg[MaxSegN];

inline void seg_update(int p)
{
	seg[p] = seg[p << 1 | 0] + seg[p << 1 | 1];
}

void seg_build(int p, int pL, int pR)
{
	if (pL == pR)
		seg[p] = seg_info(pL, height[pL]);
	else
	{
		int pM = pL + pR >> 1;
		seg_build(p << 1 | 0, pL, pM);
		seg_build(p << 1 | 1, pM + 1, pR);
		seg_update(p);
	}
}

void seg_modify(int p, int pL, int pR, int q)
{
	if (pL == pR)
	{
		seg[p] = seg_info(pL, height[pL]);
		return;
	}

	int pM = pL + pR >> 1;
	if (q <= pM)
		seg_modify(p << 1 | 0, pL, pM, q);
	else
		seg_modify(p << 1 | 1, pM + 1, pR, q);
	seg_update(p);
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		height[i] = getint();
	for (int i = n; i > 1; --i)
		height[i] -= height[i - 1];

	if (n != 1)
		seg_build(1, 2, n);

	m = getint();
	while (m--)
	{
		int l = getint(), r = getint();
		int w = getint();
		if (n == 1)
		{
			printf("1\n");
			continue;
		}

		height[l] += w;
		height[r + 1] -= w;
		if (l > 1)
			seg_modify(1, 2, n, l);
		if (r < n)
			seg_modify(1, 2, n, r + 1);
		printf("%d\n", seg[1].total + 1);
	}

	return 0;
}