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
inline void tense(T &a, const T &b)
{
	if (b < a)
		a = b;
}

const int MaxN = 200005;
const int MaxTN = 262144;
const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int n, m, nK;
int cost[MaxN];

int li_n, li[MaxN];

int tn;
int cnt[MaxTN << 1 | 1];
s64 sum[MaxTN << 1 | 1];

inline void seg_init()
{
	tn = 1;
	while (tn <= li_n)
		tn <<= 1;
}

inline void seg_add(int x)
{
	int w = li[x];
	for (x += tn - 1; x; x >>= 1)
		++cnt[x], sum[x] += w;
}
inline void seg_del(int x)
{
	int w = li[x];
	for (x += tn - 1; x; x >>= 1)
		--cnt[x], sum[x] -= w;
}
inline s64 seg_query(int k)
{
	int now = 1;
	s64 res = 0;
	while (now < tn)
	{
		int lc = now << 1;
		int rc = lc | 1;
		if (cnt[lc] > k)
			now = lc;
		else
		{
			res += sum[lc];
			k -= cnt[lc];
			now = rc;
		}
	}
	if (cnt[now])
		res += (s64)k * sum[now] / cnt[now];
	return res;
}

int mark[MaxN];
int nA = 0, wA[MaxN];
int nB = 0, wB[MaxN];
int nC = 0, wC[MaxN];

inline void add_mark(int v)
{
	int l = getint();
	for (int i = 0; i < l; ++i)
		mark[getint()] |= v;
}

inline s64 solve()
{
	int up = min(nK, nC);
	int rest = nK - up;
	if (min(nA, nB) < rest)
		return -1;

	s64 sumA = 0, sumB = 0, sumC = 0;
	for (int i = 1; i <= rest; ++i)
		sumA += li[wA[i]], sumB += li[wB[i]];
	for (int i = rest + 1; i <= nA; ++i)
		seg_add(wA[i]);
	for (int i = rest + 1; i <= nB; ++i)
		seg_add(wB[i]);

	for (int i = 1; i <= up; ++i)
		sumC += li[wC[i]];
	for (int i = up + 1; i <= nC; ++i)
		seg_add(wC[i]);

	s64 res = INF;
	for (int i = up, k; i >= 0 && (k = m - rest - rest - i) >= 0; --i)
	{
		s64 now = sumA + sumB + sumC;
		now += seg_query(k);
		tense(res, now);

		seg_add(wC[i]);
		if (rest++ >= min(nA, nB))
			break;
		seg_del(wA[rest]);
		seg_del(wB[rest]);
		sumA += li[wA[rest]];
		sumB += li[wB[rest]];
		sumC -= li[wC[i]];
	}

	return res >= INF ? -1 : res;
}

int main()
{
	cin >> n >> m >> nK;
	for (int i = 1; i <= n; ++i)
		cost[i] = li[i] = getint();

	sort(li + 1, li + n + 1);
	li_n = unique(li + 1, li + n + 1) - li - 1;
	for (int i = 1; i <= n; ++i)
		cost[i] = lower_bound(li + 1, li + li_n + 1, cost[i]) - li;

	add_mark(1 << 0);
	add_mark(1 << 1);

	seg_init();

	for (int i = 1; i <= n; ++i)
	{
		if (mark[i] == 0)
			seg_add(cost[i]);
		else if (mark[i] == 1)
			wA[++nA] = cost[i];
		else if (mark[i] == 2)
			wB[++nB] = cost[i];
		else
			wC[++nC] = cost[i];
	}

	sort(wA + 1, wA + nA + 1);
	sort(wB + 1, wB + nB + 1);
	sort(wC + 1, wC + nC + 1);

	cout << solve() << endl;

	return 0;
}