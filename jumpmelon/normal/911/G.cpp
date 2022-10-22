#include <bits/stdc++.h>

using namespace std;

namespace program
{
	struct node
	{
		node *lt, *rt;
		node() : lt(0), rt(0) { }
	};

	const int MAXN = 200000, MAXC = 100;
	int n, A[MAXN + 10];
	node *T[MAXC + 10];

	node *merge(node *x, node *y)
	{
		if (!x)
			return y;
		else if (!y)
			return x;
		else
		{
			x->lt = merge(x->lt, y->lt);
			x->rt = merge(x->rt, y->rt);
			return x;
		}
	}

	void insert(node *&v, int pos)
	{
		int a = 1, b = n;
		node *p;
		if (!v)
			v = new node();
		p = v;
		while (a < b)
		{
			int mid = (a + b) >> 1;
			if (pos <= mid)
			{
				if (!p->lt)
					p->lt = new node();
				p = p->lt;
				b = mid;
			}
			else
			{
				if (!p->rt)
					p->rt = new node();
				p = p->rt;
				a = mid + 1;
			}
		}
	}

	void query(node *&p1, node *&p2, int x, int y, int a = 1, int b = n)
	{
		if (x <= a && b <= y)
		{
			p2 = merge(p1, p2);
			p1 = 0;
		}
		else if (p1)
		{
			int mid = (a + b) >> 1;
			if (!p2)
				p2 = new node();
			if (x <= mid)
				query(p1->lt, p2->lt, x, y, a, mid);
			if (y > mid)
				query(p1->rt, p2->rt, x, y, mid + 1, b);
		}
	}

	void DFS(node *p, int val, int a = 1, int b = n)
	{
		if (p)
		{
			if (a < b)
			{
				int mid = (a + b) >> 1;
				DFS(p->lt, val, a, mid);
				DFS(p->rt, val, mid + 1, b);
			}
			else
				A[a] = val;
		}
	}

	void work()
	{
		int q;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			insert(T[a], i);
		}
		cin >> q;
		while (q--)
		{
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			if (x != y)
				query(T[x], T[y], l, r);
		}
		for (int i = 1; i <= MAXC; i++)
			DFS(T[i], i);
		for (int i = 1; i <= n; i++)
			cout << A[i] << ' ';
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	program::work();
	return 0;
}