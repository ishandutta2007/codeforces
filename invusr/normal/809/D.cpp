#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
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

const int MaxN = 300005;
const int INF = 0x3f3f3f3f;

struct node
{
	node *lc, *rc;
	int value, delta;
	int size, pri;

	inline void tag_add(int d)
	{
		delta += d;
		value += d;
	}

	inline void tag_down()
	{
		if (delta != 0)
		{
			if (lc)
				lc->tag_add(delta);
			if (rc)
				rc->tag_add(delta);

			delta = 0;
		}
	}

	inline void update()
	{
		size = 1;
		size += lc ? lc->size : 0;
		size += rc ? rc->size : 0;
	}
};
node pool[MaxN * 2], *tail = pool;
node *root = nullptr;

inline node *alloc(int v)
{
	node *x = tail++;
	x->value = v;
	x->pri = rand();
	return x;
}

typedef pair<node*, node*> root_t;

node *merge(node *p, node *q)
{
	if (!p || !q)
		return p ? p : q;

	p->tag_down();
	q->tag_down();
	if (p->pri < q->pri)
	{
		p->rc = merge(p->rc, q);
		p->update();
		return p;
	}
	else
	{
		q->lc = merge(p, q->lc);
		q->update();
		return q;
	}
}

root_t split(node *p, int k)
{
	if (!p)
		return make_pair(nullptr, nullptr);

	p->tag_down();

	int ls = p->lc ? p->lc->size : 0;
	if (k <= ls)
	{
		root_t q = split(p->lc, k);
		p->lc = q.second, p->update();
		q.second = p;
		return q;
	}
	else
	{
		root_t q = split(p->rc, k - ls - 1);
		p->rc = q.first, p->update();
		q.first = p;
		return q;
	}
}
root_t split_val(node *p, int k)
{
	if (!p)
		return make_pair(nullptr, nullptr);

	p->tag_down();

	int ls = p->lc ? p->lc->size : 0;
	if (k < p->value)
	{
		root_t q = split_val(p->lc, k);
		p->lc = q.second, p->update();
		q.second = p;
		return q;
	}
	else
	{
		root_t q = split_val(p->rc, k);
		p->rc = q.first, p->update();
		q.first = p;
		return q;
	}
}

int li_n = -1;
int li[MaxN];

void dfs(node *p)
{
	if (p)
	{
		p->tag_down();
		dfs(p->lc);
		li[++li_n] = p->value;
		dfs(p->rc);
	}
}

int main()
{
	srand(time(NULL));

	int n = getint();

	root = alloc(0);
	for (int i = 0; i < n; ++i)
		root = merge(root, alloc(INF));

	for (int i = 0; i < n; ++i)
	{
		int l = getint(), r = getint();
		root_t u = split_val(root, l - 1);
		root_t v = split_val(u.second, r - 1);
		root_t k = split(v.second, 1);

		if (v.first)
			v.first->tag_add(1);

		root = merge(u.first, alloc(l));
		root = merge(root, v.first);
		root = merge(root, k.second);
	}

	dfs(root);

	for (int i = n; i >= 0; --i)
		if (li[i] < INF)
		{
			printf("%d\n", i);
			break;
		}

	return 0;
}