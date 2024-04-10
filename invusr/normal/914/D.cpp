#include <bits/stdc++.h>
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

const int MaxN = 500000;
const int MaxM = 400000;
const int MaxSegN = MaxN * 4;

int gcd(const int &a, const int &b)
{
	return b ? gcd(b, a % b) : a;
}

int n, m;
int a[MaxN + 1];

int divs[MaxSegN];

inline void seg_update(int p)
{
	divs[p] = gcd(divs[p << 1 | 0], divs[p << 1 | 1]);
}

void seg_build(int p, int pL, int pR)
{
	if (pL == pR)
		divs[p] = a[pL];
	else
	{
		int pM = pL + pR >> 1;
		seg_build(p << 1 | 0, pL, pM);
		seg_build(p << 1 | 1, pM + 1, pR);
		seg_update(p);
	}
}

void seg_modify(int p, int pL, int pR, int q, int x)
{
	if (pL == pR)
	{
		divs[p] = x;
		return;
	}

	int pM = pL + pR >> 1;
	if (q <= pM)
		seg_modify(p << 1 | 0, pL, pM, q, x);
	if (q > pM)
		seg_modify(p << 1 | 1, pM + 1, pR, q, x);

	seg_update(p);
}

int seg_query(int p, int pL, int pR, int qL, int qR, int x)
{
	int pM = pL + pR >> 1;
	if (qL <= pL && qR >= pR)
	{
		if (divs[p] % x == 0)
			return -1;
		if (pL == pR)
			return pL;

		int l = divs[p << 1 | 0];
		if (l % x != 0)
			return seg_query(p << 1 | 0, pL, pM, qL, qR, x);
		if (l % x == 0)
			return seg_query(p << 1 | 1, pM + 1, pR, qL, qR, x);
	}

	int l = -1;
	if (qL <= pM)
		l = seg_query(p << 1 | 0, pL, pM, qL, qR, x);
	if (qR > pM && !~l)
		l = seg_query(p << 1 | 1, pM + 1, pR, qL, qR, x);

	return l;
}

bool seg_validate(int p, int pL, int pR, int qL, int qR, int x)
{
	if (qL == pL && qR == pR)
		return divs[p] % x == 0;

	int pM = pL + pR >> 1;
	if (qR <= pM)
		return seg_validate(p << 1 | 0, pL, pM, qL, qR, x);
	else if (qL > pM)
		return seg_validate(p << 1 | 1, pM + 1, pR, qL, qR, x);
	else
	{
		if (!seg_validate(p << 1 | 0, pL, pM, qL, pM, x))
			return false;
		if (!seg_validate(p << 1 | 1, pM + 1, pR, pM + 1, qR, x))
			return false;
		return true;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		a[i] = getint();

	seg_build(1, 1, n);

	cin >> m;
	while (m--)
	{
		int t = getint();
		int l = getint(), r = getint();

		if (t == 2)
			seg_modify(1, 1, n, l, r);
		else
		{
			int x = getint();
			int p = seg_query(1, 1, n, l, r, x);
		//	cerr << p << ' ';

			if (p == -1 || p == r)
				puts("YES");
			else if (seg_validate(1, 1, n, p + 1, r, x))
				puts("YES");
			else
				puts("NO");
		}
	}

	return 0;
}