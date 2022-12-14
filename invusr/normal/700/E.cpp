#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 200005;
const int MaxTN = MaxN * 2;
const int MaxLogN = 21;
const int MaxSegN = MaxTN * MaxLogN * 2;
const int NLet = 26;

int n;
char s[MaxN];

int tn = 1, last = 1;
int next[MaxTN][NLet];
int fail[MaxTN];
int len[MaxTN], pos[MaxTN];
bool suf[MaxTN];

inline void sa_extend(const int &c)
{
	int p = last;
	int np = last = ++tn;
	pos[np] = len[np] = len[p] + 1;
	suf[np] = true;

	while (p && !next[p][c])
		next[p][c] = np, p = fail[p];
	if (!p)
		fail[np] = 1;
	else
	{
		int q = next[p][c];
		if (len[q] == len[p] + 1)
			fail[np] = q;
		else
		{
			int nq = ++tn;
			for (int i = 0; i < NLet; ++i)
				next[nq][i] = next[q][i];
			len[nq] = len[p] + 1;
			pos[nq] = pos[np];
			fail[nq] = fail[q];
			fail[np] = fail[q] = nq;
			while (next[p][c] == q)
				next[p][c] = nq, p = fail[p];
		}
	}
}

struct halfEdge
{
	int v;
	halfEdge *next;
};
halfEdge adj_pool[MaxTN], *adj_tail = adj_pool;
halfEdge *adj[MaxTN];

inline void addEdge(const int &u, const int &v)
{
	adj_tail->v = v, adj_tail->next = adj[u];
	adj[u] = adj_tail++;
}

struct seg_node
{
	seg_node *lc, *rc;
};
seg_node seg_pool[MaxSegN], *seg_tail = seg_pool;
seg_node *seg[MaxTN];

seg_node *seg_add(seg_node *p, int pL, int pR, int q)
{
	seg_node *np = seg_tail++;
	np->lc = p ? p->lc : NULL;
	np->rc = p ? p->rc : NULL;
	if (pL == pR)
		return np;

	int pM = pL + pR >> 1;
	if (q <= pM)
		np->lc = seg_add(np->lc, pL, pM, q);
	if (q > pM)
		np->rc = seg_add(np->rc, pM + 1, pR, q);
	return np;
}

seg_node *seg_merge(seg_node *p, seg_node *q)
{
	if (!p || !q)
		return p ? p : q;

	seg_node *np = seg_tail++;
	np->lc = seg_merge(p->lc, q->lc);
	np->rc = seg_merge(p->rc, q->rc);
	return np;
}

bool seg_query(seg_node *p, int pL, int pR, int qL, int qR)
{
	if (!p)
		return false;
	if (qL <= pL && qR >= pR)
		return true;

	int pM = pL + pR >> 1;
	if (qL <= pM && seg_query(p->lc, pL, pM, qL, qR))
		return true;
	if (qR > pM && seg_query(p->rc, pM + 1, pR, qL, qR))
		return true;
	return false;
}

int f[MaxTN];

void dfs(int u, int fr)
{
	for (halfEdge *e = adj[u]; e; e = e->next)
	{
		int l = pos[e->v] - len[e->v] + len[fr];
		int r = pos[e->v] - 1;
		if (!seg_query(seg[fr], 1, n, l, r))
			dfs(e->v, fr);
		else
		{
			f[e->v] = f[fr] + 1;
			dfs(e->v, e->v);
		}
	}
}

void build(int u)
{
// 	if (suf[u])
		seg[u] = seg_add(seg[u], 1, n, pos[u]);

	for (halfEdge *e = adj[u]; e; e = e->next)
	{
		build(e->v);
		seg[u] = seg_merge(seg[u], seg[e->v]);
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);

	for (int i = 1; i <= n; ++i)
		sa_extend(s[i] - 'a');
	for (int u = 2; u <= tn; ++u)
		addEdge(fail[u], u);

	build(1);

	for (halfEdge *e = adj[1]; e; e = e->next)
	{
		f[e->v] = 1;
		dfs(e->v, e->v);
	}

	cout << *max_element(f + 2, f + tn + 1);
	cout << endl;

	return 0;
}