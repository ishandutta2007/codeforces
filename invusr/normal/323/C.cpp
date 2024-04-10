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

const int MaxN = 1000005;
const int MaxM = 200005;
const int MaxLogN = 23;
const int MaxSegN = MaxN * MaxLogN;

int n, m, last_ans = 0;
int p[MaxN], pos[MaxN];

struct seg_node
{
	seg_node *lc, *rc;
	int sum;
};
seg_node seg_pool[MaxSegN], *seg_tail = seg_pool;
seg_node *seg[MaxN];

seg_node *seg_add(seg_node *p, int pL, int pR, int qL)
{
	seg_node *q = seg_tail++;
	if (p != nullptr)
		*q = *p, ++q->sum;
	else
		q->lc = q->rc = nullptr, q->sum = 1;
	if (pL == pR)
		return q;

	int pM = pL + pR >> 1;
	if (qL <= pM)
		q->lc = seg_add(q->lc, pL, pM, qL);
	else
		q->rc = seg_add(q->rc, pM + 1, pR, qL);
	return q;
}
int seg_query(seg_node *p, int pL, int pR, int qL, int qR)
{
	if (p == nullptr)
		return 0;
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

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		p[i] = getint();
	for (int i = 1; i <= n; ++i)
		pos[getint()] = i;

	seg[0] = nullptr;
	for (int i = 1; i <= n; ++i)
		seg[i] = seg_add(seg[i - 1], 1, n, pos[p[i]]);

	m = getint();
	while (m--)
	{
		int l1 = (getint() + last_ans - 1) % n + 1;
		int r1 = (getint() + last_ans - 1) % n + 1;
		int l2 = (getint() + last_ans - 1) % n + 1;
		int r2 = (getint() + last_ans - 1) % n + 1;
		l1 > r1 ? l1 ^= r1 ^= l1 ^= r1 : 0, --l1;
		l2 > r2 ? l2 ^= r2 ^= l2 ^= r2 : 0;
		int a = seg_query(seg[l1], 1, n, l2, r2);
		int b = seg_query(seg[r1], 1, n, l2, r2);
		printf("%d\n", last_ans = b - a), ++last_ans;
	}

	return 0;
}