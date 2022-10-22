#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int MAXN = 100000, MX = 1000000000;
	int n, V[MAXN + 1];
	struct segment { int sa, ea, sb, eb; } A[MAXN];

	extern struct node *null;

	struct node
	{
		bool tag;
		node *lt, *rt;
		node() : tag(0), lt(this), rt(this) { }
		void update(int x, int y, int a = 1, int b = MX);
		bool query(int x, int y, int a = 1, int b = MX);
	} *null = new node(), *Root[MAXN + 1];

	void node::update(int x, int y, int a, int b)
	{
		if (tag)
			return;
		if (x <= a && b <= y)
			tag = 1;
		else
		{
			int mid = (a + b) >> 1;
			if (x <= mid)
				(lt = new node(*lt))->update(x, y, a, mid);
			if (y > mid)
				(rt = new node(*rt))->update(x, y, mid + 1, b);
		}
	}

	bool node::query(int x, int y, int a, int b)
	{
		if (this == null)
			return 0;
		if (tag)
			return 1;
		if (x <= a && b <= y)
			return 1;
		else
		{
			int mid = (a + b) >> 1;
			if (x <= mid && lt->query(x, y, a, mid))
				return 1;
			if (y > mid && rt->query(x, y, mid + 1, b))
				return 1;
			return 0;
		}
	}

	bool judge()
	{
		sort(A, A + n, [](const segment &a, const segment &b) { return a.ea < b.ea; });
		Root[0] = null;
		for (int i = 0; i < n; i++)
		{
			Root[i + 1] = new node(*Root[i]);
			Root[i + 1]->update(A[i].sb, A[i].eb);
			V[i] = A[i].ea;
			int p = lower_bound(V, V + i, A[i].sa) - V;
			if (Root[p]->query(A[i].sb, A[i].eb))
				return 0;
		}
		return 1;
	}

	void work()
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d%d%d", &A[i].sa, &A[i].ea, &A[i].sb, &A[i].eb);
		if (!judge())
			puts("NO");
		else
		{
			for (int i = 0; i < n; i++)
			{
				swap(A[i].sa, A[i].sb);
				swap(A[i].ea, A[i].eb);
			}
			puts(judge() ? "YES" : "NO");
		}
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}