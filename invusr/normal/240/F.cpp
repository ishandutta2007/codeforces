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
const int MaxSegN = MaxN * 4;
const int NLet = 26;

int n, m;
char str[MaxN];

struct seg_info
{
	int occur[NLet];

	seg_info() {}
	seg_info(int x, int t)
	{
		fill(occur, occur + NLet, 0);
		occur[x] = t;
	}

	inline int &operator[](int p)
	{
		return occur[p];
	}

	friend inline seg_info operator+(seg_info &lhs, seg_info &rhs)
	{
		seg_info res;
		for (int i = 0; i < NLet; ++i)
			res[i] = lhs[i] + rhs[i];
		return res;
	}

	inline void out() const
	{
		for (int i = 0; i < NLet; ++i)
			if (occur[i])
			{
				putchar('a' + i);
				return;
			}
	}

	inline bool valid(int t) const
	{
		int now = 0;
		for (int i = 0; i < NLet; ++i)
		{
			now += occur[i] & 1;
			if (now > t)
				return false;
		}
		return true;
	}
};
seg_info seg[MaxSegN];

int cov[MaxSegN];

inline void seg_update(int p)
{
	seg[p] = seg[p << 1 | 0] + seg[p << 1 | 1];
}

inline void seg_tag_cov(int p, int pL, int pR, int x)
{
	cov[p] = x;
	seg[p] = seg_info(x, pR - pL + 1);
}

inline void seg_tag_down(int p, int pL, int pR)
{
	if (cov[p] != NLet)
	{
		int pM = pL + pR >> 1;
		seg_tag_cov(p << 1 | 0, pL, pM, cov[p]);
		seg_tag_cov(p << 1 | 1, pM + 1, pR, cov[p]);
		cov[p] = NLet;
	}
}

void seg_build(int p, int pL, int pR)
{
	cov[p] = NLet;
	if (pL == pR)
		seg[p] = seg_info(str[pL] - 'a', 1);
	else
	{
		int pM = pL + pR >> 1;
		seg_build(p << 1 | 0, pL, pM);
		seg_build(p << 1 | 1, pM + 1, pR);
		seg_update(p);
	}
}

void seg_cover(int p, int pL, int pR, int qL, int qR, int x)
{
	if (qL <= pL && qR >= pR)
	{
		seg_tag_cov(p, pL, pR, x);
		return;
	}

	seg_tag_down(p, pL, pR);

	int pM = pL + pR >> 1;
	if (qL <= pM)
		seg_cover(p << 1 | 0, pL, pM, qL, qR, x);
	if (qR > pM)
		seg_cover(p << 1 | 1, pM + 1, pR, qL, qR, x);
	seg_update(p);
}

seg_info seg_query(int p, int pL, int pR, int qL, int qR)
{
	if (pL == qL && pR == qR)
		return seg[p];

	seg_tag_down(p, pL, pR);

	int pM = pL + pR >> 1;
	if (qR <= pM)
		return seg_query(p << 1 | 0, pL, pM, qL, qR);
	else if (qL > pM)
		return seg_query(p << 1 | 1, pM + 1, pR, qL, qR);
	else
	{
		seg_info l = seg_query(p << 1 | 0, pL, pM, qL, pM);
		seg_info r = seg_query(p << 1 | 1, pM + 1, pR, pM + 1, qR);
		return l + r;
	}
}

void seg_out(int p, int pL, int pR)
{
	if (pL == pR)
	{
		seg[p].out();
		return;
	}

	seg_tag_down(p, pL, pR);

	int pM = pL + pR >> 1;
	seg_out(p << 1 | 0, pL, pM);
	seg_out(p << 1 | 1, pM + 1, pR);
}

inline void work(int l, int r)
{
	seg_info cnt = seg_query(1, 1, n, l, r);
	if (!cnt.valid(r - l + 1 & 1))
		return;

	int mid = l + r >> 1;
	for (int i = 0; i < NLet; ++i)
		if (cnt[i] & 1)
			seg_cover(1, 1, n, mid, mid, i), --cnt[i];

	for (int i = 0; i < NLet; ++i)
		if (cnt[i] > 0)
		{
			int d = cnt[i] >> 1;
			seg_cover(1, 1, n, l, l + d - 1, i);
			seg_cover(1, 1, n, r - d + 1, r, i);
			l += d, r -= d;
		}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &n, &m);
	scanf("%s", str + 1);

	seg_build(1, 1, n);

	while (m--)
	{
		int l = getint(), r = getint();
		work(l, r);
	}

	seg_out(1, 1, n);

	fclose(stdin);
	fclose(stdout);
	return 0;
}