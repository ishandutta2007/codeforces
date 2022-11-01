#include <bits/stdc++.h>
using namespace std;

const int INF = 2147483647;

struct node
{
	node *l, *r;
	int mi, ma;
	node() : l(NULL), r(NULL), mi(0), ma(0) { }
	void upd(int x, int v, int lo, int hi, node *b)
	{
		if (lo+1 == hi)
			mi = ma = v;
		else
		{
			int mid = (lo+hi) >> 1;
			if (x < mid)
			{
				l = new node; l->upd(x, v, lo, mid, b?b->l:NULL);
				r = b?b->r:NULL;
			} else
			{
				l = b?b->l:NULL;
				r = new node; r->upd(x, v, mid, hi, b?b->r:NULL);
			}
			mi = min(getmin(l), getmin(r));
			ma = max(getmax(l), getmax(r));
		}
	}
	node *gl()
	{
		if (l) return l;
		return l = new node;
	}
	node *gr()
	{
		if (r) return r;
		return r = new node;
	}
	static int getmin(node *w)
	{
		return w?w->mi:0;
	}
	static int getmax(node *w)
	{
		return w?w->ma:0;
	}
};

struct query
{
	int a, b, t;
	bool operator< (const query& oth) const
	{
		return (a < oth.a);
	}
} queries[400005];

int d1[400005];
node *d2[400005];

int have[400005];
int step[400005];
int ls[400005];
int rs[400005];
int lis;

int ans[400005];

int h[400005];
int n, q;

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1;i <= n;i++)
		scanf("%d", h+i);
	for (int i = 0;i < q;i++)
		scanf("%d%d", &queries[i].a, &queries[i].b), queries[i].t = i;
	sort(queries, queries+q);
	for (int i = 1;i <= n;i++)
		d1[i] = 2147483647;
	for (int i = 1;i <= n;i++)
	{
		int *wh = lower_bound(d1, d1+n, h[i]);
		lis = max(lis, ls[i] = wh-d1);
		if (h[i] < *wh)
			*wh = h[i];
	}
	d2[n+1] = new node;
	d2[n+1]->upd(0, INF, 0, 524288, NULL);
	for (int i = n;i >= 1;i--)
	{
		node *at = d2[i+1];
		int lo = 0, hi = 524288;
		while (lo+1 < hi)
		{
			int mid = (lo+hi) >> 1;
			if (node::getmin(at->l) <= h[i])
			{
				at = at->gl();
				hi = mid;
			} else
			{
				at = at->gr();
				lo = mid;
			}
		}
		rs[i] = lo;
		if (h[i] > node::getmin(at))
		{
			d2[i] = new node;
			d2[i]->upd(lo, h[i], 0, 524288, d2[i+1]);
		} else
			d2[i] = d2[i+1];
	}
	for (int i = 1;i <= n;i++) if (ls[i]+rs[i]-1 == lis)
	{
		if (have[ls[i]] == -1) continue;
		else if (have[ls[i]] == 0)
		{
			have[ls[i]] = i;
			step[i] = ls[i];
		} else
		{
			step[have[ls[i]]] = 0;
			have[ls[i]] = -1;
		}
	}
	for (int i = 1;i <= n;i++)
		d1[i] = 2147483647;
	int upto = 0;
	for (int i = 0;i < q;i++)
	{
		int a = queries[i].a, b = queries[i].b;
		for (;upto < a;upto++)
			d1[ls[upto]] = min(d1[ls[upto]], h[upto]);
		int llo = lower_bound(d1, d1+n, b) - d1;
		node *rgt = d2[a+1];
		int rlo = 0, rhi = 524288;
		while (rgt && rlo+1 < rhi)
		{
			int mid = (rlo+rhi) >> 1;
			if (node::getmin(rgt->l) <= b)
			{
				rgt = rgt->l;
				rhi = mid;
			} else
			{
				rgt = rgt->r;
				rlo = mid;
			}
		}
		ans[queries[i].t] = llo + rlo - 1;
		if (step[a]) ans[queries[i].t] = max(ans[queries[i].t], lis-1);
		else ans[queries[i].t] = max(ans[queries[i].t], lis);
	}
	for (int i = 0;i < q;i++)
		printf("%d\n", ans[i]);
	return 0;
}