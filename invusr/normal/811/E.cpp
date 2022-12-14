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

const int MaxN = 12;
const int MaxM = 100005;
const int MaxSegN = MaxM * 4;

int n, m, q;
int a[MaxN][MaxM];

struct seg_info
{
	int tot, cur;
	int vl[MaxN], vr[MaxN];

	inline void init(int x)
	{
		int b = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (i == 1 || a[i][x] != a[i - 1][x])
				++b;
			vl[i] = vr[i] = b;
		}
		tot = cur = b;
	}
};
seg_info seg[MaxSegN];

int ufs[MaxN * 4];
int vis[MaxN * 4];

int ufs_find(int x)
{
	return ufs[x] == x ? x : ufs[x] = ufs_find(ufs[x]);
}

int ufs_union(int u, int v)
{
	u = ufs_find(u);
	v = ufs_find(v);
	return u == v ? 0 : (ufs[u] = v, 1);
}

inline seg_info seg_info_merge(seg_info lhs, seg_info rhs, int k)
{
	seg_info ret;

	for (int i = 1; i <= lhs.cur + rhs.cur; ++i)
		ufs[i] = i, vis[i] = 0;

	ret.tot = lhs.tot + rhs.tot;
	for (int i = 1; i <= n; ++i)
		if (a[i][k] == a[i][k + 1])
			ret.tot -= ufs_union(lhs.vr[i], rhs.vl[i] + lhs.cur);

	int idx = 0;
	for (int i = 1; i <= n; ++i)
	{
		int u = ufs_find(lhs.vl[i]);
		int v = ufs_find(rhs.vr[i] + lhs.cur);
		vis[u] = vis[v] = 1;
	}
	for (int i = 1; i <= lhs.cur + rhs.cur; ++i)
		if (vis[i])
			vis[i] = ++idx;

	ret.cur = idx;
	for (int i = 1; i <= n; ++i)
	{
		int u = ufs_find(lhs.vl[i]);
		int v = ufs_find(rhs.vr[i] + lhs.cur);
		ret.vl[i] = vis[u];
		ret.vr[i] = vis[v];
	}

	return ret;
}

inline void seg_update(int p, int pM)
{
	seg[p] = seg_info_merge(seg[p << 1 | 0], seg[p << 1 | 1], pM);
}

void seg_build(int p, int pL, int pR)
{
	if (pL == pR)
		seg[p].init(pL);
	else
	{
		int pM = pL + pR >> 1;
		seg_build(p << 1 | 0, pL, pM);
		seg_build(p << 1 | 1, pM + 1, pR);
		seg_update(p, pM);
	}
}

seg_info seg_query(int p, int pL, int pR, int qL, int qR)
{
	if (qL == pL && qR == pR)
		return seg[p];

	int pM = pL + pR >> 1;
	if (qR <= pM)
		return seg_query(p << 1 | 0, pL, pM, qL, qR);
	else if (qL > pM)
		return seg_query(p << 1 | 1, pM + 1, pR, qL, qR);
	else
	{
		seg_info l = seg_query(p << 1 | 0, pL, pM, qL, pM);
		seg_info r = seg_query(p << 1 | 1, pM + 1, pR, pM + 1, qR);
		return seg_info_merge(l, r, pM);
	}
}

int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			a[i][j] = getint();

	seg_build(1, 1, m);

	while (q--)
	{
		int l = getint(), r = getint();
		seg_info ret = seg_query(1, 1, m, l, r);
		printf("%d\n", ret.tot);
	}

	return 0;
}