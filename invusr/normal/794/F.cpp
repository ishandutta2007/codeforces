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

const int MaxN = 100005;
const int MaxM = 100005;
const int ND = 10;
const int MaxSegN = MaxN * 8;

int n, m;

s64 sum[MaxSegN][ND];
int rep[MaxSegN][ND];

inline void seg_tag_replace(int p, int *tag)
{
	int rep_t[ND];
	s64 sum_t[ND];
	for (int i = 0; i < ND; ++i)
		rep_t[i] = tag[rep[p][i]], sum_t[i] = 0;
	for (int i = 0; i < ND; ++i)
		rep[p][i] = rep_t[i], sum_t[tag[i]] += sum[p][i];
	for (int i = 0; i < ND; ++i)
		sum[p][i] = sum_t[i];
}

inline void seg_tag_down(int p)
{
	bool ok = true;
	for (int i = 0; i < ND; ++i)
		if (rep[p][i] != i)
		{
			ok = false;
			break;
		}
	if (ok)
		return;

	seg_tag_replace(p << 1 | 0, rep[p]);
	seg_tag_replace(p << 1 | 1, rep[p]);
	for (int i = 0; i < ND; ++i)
		rep[p][i] = i;
}

inline void seg_update(int p)
{
	int lc = p << 1, rc = lc | 1;
	for (int i = 0; i < ND; ++i)
		sum[p][i] = sum[lc][i] + sum[rc][i];
}

void seg_build(int p, int pL, int pR)
{
	for (int i = 0; i < ND; ++i)
		rep[p][i] = i;

	if (pL == pR)
	{
		int x = getint(), v = 1;
		while (x > 0)
		{
			sum[p][x % 10] += v;
			v *= 10, x /= 10;
		}
	}
	else
	{
		int pM = pL + pR >> 1;
		seg_build(p << 1 | 0, pL, pM);
		seg_build(p << 1 | 1, pM + 1, pR);
		seg_update(p);
	}
}
void seg_replace(int p, int pL, int pR, int qL, int qR, int *tag)
{
	if (qL <= pL && qR >= pR)
	{
		seg_tag_replace(p, tag);
		return;
	}

	seg_tag_down(p);

	int pM = pL + pR >> 1;
	if (qL <= pM)
		seg_replace(p << 1 | 0, pL, pM, qL, qR, tag);
	if (qR > pM)
		seg_replace(p << 1 | 1, pM + 1, pR, qL, qR, tag);

	seg_update(p);
}
s64 seg_query(int p, int pL, int pR, int qL, int qR)
{
	if (qL <= pL && qR >= pR)
	{
		s64 res = 0;
		for (int i = 0; i < ND; ++i)
			res += i * sum[p][i];
		return res;
	}

	seg_tag_down(p);

	int pM = pL + pR >> 1;
	s64 res = 0;
	if (qL <= pM)
		res += seg_query(p << 1 | 0, pL, pM, qL, qR);
	if (qR > pM)
		res += seg_query(p << 1 | 1, pM + 1, pR, qL, qR);
	return res;
}

int main()
{
	cin >> n >> m;

	seg_build(1, 1, n);

	while (m--)
	{
		int op = getint();
		if (op == 1)
		{
			int l = getint(), r = getint();
			int u = getint(), v = getint();

			int tag[ND];
			for (int i = 0; i < ND; ++i)
				tag[i] = i;
			tag[u] = v;
			seg_replace(1, 1, n, l, r, tag);
		}
		else
		{
			int l = getint(), r = getint();
			printf("%lld\n", seg_query(1, 1, n, l, r));
		}
	}

	return 0;
}