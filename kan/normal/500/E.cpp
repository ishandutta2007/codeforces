#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

struct tnode
{
	tnode *l, *r;
	tnode *p;
	int y;
	int to_push;
	int sum;
	
	tnode()
	{
		l = NULL;
		r = NULL;
		p = NULL;
		to_push = 0;
		sum = 0;
		y = (rand() << 16) ^ rand();
	}
};

typedef tnode* pnode;

void push(pnode cur)
{
	if (cur->l) cur->l->to_push += cur->to_push;
	if (cur->r) cur->r->to_push += cur->to_push;
	cur->sum += cur->to_push;
	cur->to_push = 0;
}

void update(pnode cur)
{
	if (cur->l) cur->l->p = cur;
	if (cur->r) cur->r->p = cur;
}

pnode merge(pnode l, pnode r)
{
	if (l == NULL) return r;
	if (r == NULL) return l;
	push(l);
	push(r);
	if (l->y > r->y)
	{
		l->r = merge(l->r, r);
		update(l);
		return l;
	} else
	{
		r->l = merge(l, r->l);
		update(r);
		return r;
	}
}

int calc(pnode cur)
{
	int ans = cur->sum;
	while (cur != NULL)
	{
		ans += cur->to_push;
		cur = cur->p;
	}
	return ans;
}

const int maxn = 200005;

#define ends ends_sdf

pnode root[maxn];
int lastx[maxn];
int x[maxn], l[maxn];
vector<int> begins[maxn], ends[maxn];
pnode wh[maxn];
int ans[maxn];
int n, q;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &l[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		begins[l].push_back(i);
		ends[r].push_back(i);
	}
	int top = 0;
	for (int i = 0; i < n; i++)
	{
		pnode curroot = NULL;
		while (top > 0 && lastx[top - 1] < x[i])
		{
			root[top - 1]->to_push += x[i] - lastx[top - 1];
			curroot = merge(curroot, root[top - 1]);
			top--;
		}
		if (curroot != NULL)
		{
			root[top] = curroot;
			lastx[top] = x[i];
			top++;
		}
		for (auto t : begins[i])
		{
			curroot = new tnode;
			wh[t] = curroot;
			lastx[top] = x[i];
			root[top] = curroot;
			top++;
		}
		curroot = NULL;
		while (top > 0 && lastx[top - 1] < x[i] + l[i])
		{
			curroot = merge(curroot, root[top - 1]);
			top--;
		}
		if (curroot != NULL)
		{
			root[top] = curroot;
			lastx[top] = x[i] + l[i];
			top++;
		}
		for (auto t : ends[i])
		{
			ans[t] = calc(wh[t]);
		}
	}
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
	return 0;
}