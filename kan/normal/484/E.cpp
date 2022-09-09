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

const int inf = 1e9;

struct tnode
{
	tnode *l, *r;
	int to_push;
	int max;
	
	tnode()
	{
		l = NULL;
		r = NULL;
		to_push = 0;
		max = 0;
	}
	tnode(tnode &x): l(x.l), r(x.r), to_push(x.to_push), max(x.max) {}
};

typedef tnode* pnode;

int getans(pnode cur)
{
	return cur->max + cur->to_push;
}

void push(pnode cur)
{
	cur->l->to_push += cur->to_push;
	cur->r->to_push += cur->to_push;
	cur->max += cur->to_push;
	cur->to_push = 0;
}

pnode add(pnode cur, int cl, int cr, int l, int r, int t)
{
	if (cl > r || cr < l) return cur;
	cur = new tnode(*cur);
	if (cl >= l && cr <= r)
	{
		cur->to_push += t;
		return cur;
	}
	int cm = (cl + cr) / 2;
	push(cur);
	cur->l = add(cur->l, cl, cm, l, r, t);
	cur->r = add(cur->r, cm + 1, cr, l, r, t);
	cur->max = max(getans(cur->l), getans(cur->r));
	return cur;
}

int getmax(pnode cur, int cl, int cr, int l, int r)
{
	if (cl > r || cr < l) return -inf;
	if (cl >= l && cr <= r) return getans(cur);
	int cm = (cl + cr) / 2;
	return cur->to_push + max(getmax(cur->l, cl, cm, l, r), getmax(cur->r, cm + 1, cr, l, r));
}

pnode build(int cl, int cr)
{
	pnode cur = new tnode;
	if (cl == cr) return cur;
	int cm = (cl + cr) / 2;
	cur->l = build(cl, cm);
	cur->r = build(cm + 1, cr);
	return cur;
}

const int treesize = 1 << 17;
const int maxn = 100005;

int a[maxn];
pair<int, int> b[maxn];

pnode global_root;
pnode root[maxn];
int p[maxn], s[maxn];
int l[maxn], r[maxn];
int n, m;

inline int find(int cur)
{
	return (p[cur] == cur ? cur : p[cur] = find(p[cur]));
}

inline void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (s[a] > s[b]) swap(a, b);
	p[a] = b;
	if (s[a] == s[b]) s[b]++;
	l[b] = min(l[a], l[b]);
	r[b] = max(r[a], r[b]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) b[i] = {a[i], i};
	sort(b, b + n);
	reverse(b, b + n);
	global_root = build(0, treesize - 1);
	for (int i = 0; i <= n; i++) l[i] = i, r[i] = i;
	for (int i = 0; i <= n; i++) p[i] = i, s[i] = 0;
	for (int i = 0; i < n; i++)
	{
		int waslid = find(b[i].second);
		int wasrid = find(b[i].second + 1);
		int rr = r[wasrid] - l[wasrid] + 1;
		int wasl = l[waslid];
		int wasr = r[waslid];
		unite(b[i].second, b[i].second + 1);
// 		cout << i << ' ' << wasl << ' ' << wasr << ' ' << rr << endl;
		global_root = add(global_root, 0, treesize - 1, wasl, wasr, rr);
		root[i] = global_root;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int l, r, w;
		scanf("%d%d%d", &l, &r, &w);
		l--, r--;
		r = r - w + 1;
		int L = -1;
		int R = n - 1;
		while (R - L > 1)
		{
			int M = (L + R) / 2;
			if (getmax(root[M], 0, treesize - 1, l, r) >= w) R = M;
			else L = M;
		}
		printf("%d\n", b[R].first);
	}
	return 0;
}