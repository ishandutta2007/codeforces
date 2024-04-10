#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
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
const int MaxLogN = 21;
const int MaxSegN = MaxN * MaxLogN * 2;

int n, nK;
int a[MaxN];

struct seg_node
{
	seg_node *lc, *rc;
	int sum;
};
seg_node seg_pool[MaxSegN], *seg_tail = seg_pool;
seg_node *seg[MaxN];

void seg_build(seg_node *&p, int pL, int pR)
{
	p = seg_tail++;
	if (pL != pR)
	{
		int pM = pL + pR >> 1;
		seg_build(p->lc, pL, pM);
		seg_build(p->rc, pM + 1, pR);
	}
}

seg_node *seg_add(seg_node *p, int pL, int pR, int qL, int d)
{
	seg_node *q = seg_tail++;
	*q = *p, q->sum += d;
	if (pL == pR)
		return q;

	int pM = pL + pR >> 1;
	if (qL <= pM)
		q->lc = seg_add(q->lc, pL, pM, qL, d);
	if (qL > pM)
		q->rc = seg_add(q->rc, pM + 1, pR, qL, d);
	return q;
}

int seg_query(seg_node *p, int pL, int pR, int qL, int qR)
{
	if (qL <= pL && qR >= pR)
		return p->sum;

	int res = 0;
	int pM = pL + pR >> 1;
	if (qL <= pM)
		res += seg_query(p->lc, pL, pM, qL, qR);
	if (qR > pM)
		res += seg_query(p->rc, pM + 1, pR, qL, qR);
	return res;
}

vector<int> pos[MaxN];

int main()
{
	cin >> n >> nK;
	for (int i = 1; i <= n; ++i)
		a[i] = getint();

	seg_build(seg[0], 1, n);
	for (int i = 1; i <= n; ++i)
	{
		seg[i] = seg_add(seg[i - 1], 1, n, i, 1);
		pos[a[i]].push_back(i);
		int l = pos[a[i]].size();
		if (l > nK)
			seg[i] = seg_add(seg[i], 1, n, pos[a[i]][l - nK - 1], -1);
	}

	int q = getint();
	int last = 0;
	while (q--)
	{
		int l = (getint() + last) % n + 1;
		int r = (getint() + last) % n + 1;
		if (l > r)
			swap(l, r);
		printf("%d\n", last = seg_query(seg[r], 1, n, l, r));
	}

	return 0;
}