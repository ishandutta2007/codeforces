#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int treesize = 1 << 18;
const int maxn = 200005;

struct tnode
{
	int f0, f1;
	int push;
};

tnode tree[treesize * 2];
int a[treesize * 2];
int f[treesize * 2], sum[treesize * 2];
int n, m;

const int MOD = 1000000000;

inline int get_sum(int l, int r)
{
	return (sum[r] - sum[l] + MOD) % MOD;
}

inline int get_ith(const tnode &cur, int i)
{
	if (i == 0) return cur.f0;
	if (i == 1) return cur.f1;
	return ((ll)f[i - 1] * cur.f1 + (ll)f[i - 2] * cur.f0) % MOD;
}

inline void upd(tnode &cur, const tnode &l, const tnode &r, int len)
{
	cur.f0 = (l.f0 + get_ith(r, len)) % MOD;
	cur.f1 = (l.f1 + get_ith(r, len + 1)) % MOD;
}

void make_tree(int cur, int cl, int cr)
{
	if (cl == cr) return;
	int cm = (cl + cr) / 2;
	make_tree(cur * 2, cl, cm);
	make_tree(cur * 2 + 1, cm + 1, cr);
	tree[cur].push = 0;
	upd(tree[cur], tree[cur * 2], tree[cur * 2 + 1], cr - cm);
// 	cout << "make_tree " << cl << ' ' << cr << ' ' << tree[cur].f0 << ' ' << tree[cur].f1 << endl;
}

inline void add_one(int &cur, int l, int r, int t)
{
	cur = (cur + (ll)get_sum(l, r) * t) % MOD;
}

inline void push(int cur, int len)
{
	len /= 2;
	add_one(tree[cur * 2].f0, 0, len, tree[cur].push);
	add_one(tree[cur * 2].f1, 1, len + 1, tree[cur].push);
	add_one(tree[cur * 2 + 1].f0, 0, len, tree[cur].push);
	add_one(tree[cur * 2 + 1].f1, 1, len + 1, tree[cur].push);
	tree[cur * 2].push = (tree[cur * 2].push + tree[cur].push) % MOD;
	tree[cur * 2 + 1].push = (tree[cur * 2 + 1].push + tree[cur].push) % MOD;
	tree[cur].push = 0;
}

void set(int cur, int cl, int cr, int x, int t)
{
	if (cr < x || cl > x) return;
	if (cr == cl)
	{
		tree[cur].push = 0;
		tree[cur].f0 = t;
		tree[cur].f1 = t;
		return;
	}
	push(cur, cr - cl + 1);
	int cm = (cl + cr) / 2;
	set(cur * 2, cl, cm, x, t);
	set(cur * 2 + 1, cm + 1, cr, x, t);
	upd(tree[cur], tree[cur * 2], tree[cur * 2 + 1], cr - cm);
}

int get(int cur, int cl, int cr, int l, int r)
{
	if (cr < l || cl > r) return 0;
	if (cl >= l && cr <= r)
	{
// 		cout << "get " << cl << ' ' << cr << ' ' << get_ith(tree[cur], cl - l) << endl;
		return get_ith(tree[cur], cl - l);
	}
	push(cur, cr - cl + 1);
	int cm = (cl + cr) / 2;
	return (get(cur * 2, cl, cm, l, r) + get(cur * 2 + 1, cm + 1, cr, l, r)) % MOD;
}

void add(int cur, int cl, int cr, int l, int r, int t)
{
	if (cr < l || cl > r) return;
	if (cl >= l && cr <= r)
	{
		add_one(tree[cur].f0, 0, cr - cl + 1, t);
		add_one(tree[cur].f1, 1, cr - cl + 2, t);
// 		cout << "add " << cl << ' ' 
		tree[cur].push = (tree[cur].push + t) % MOD;
		return;
	}
	push(cur, cr - cl + 1);
	int cm = (cl + cr) / 2;
	add(cur * 2, cl, cm, l, r, t);
	add(cur * 2 + 1, cm + 1, cr, l, r, t);
	upd(tree[cur], tree[cur * 2], tree[cur * 2 + 1], cr - cm);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < treesize * 2; i++) f[i] = (f[i - 1] + f[i - 2]) % MOD;
	sum[0] = 0;
	for (int i = 0; i + 1 < treesize * 2; i++) sum[i + 1] = (sum[i] + f[i]) % MOD;
	for (int i = 0; i < n; i++)
	{
		tree[treesize + i].f1 = a[i];
		tree[treesize + i].f0 = a[i];
	}
	make_tree(1, 0, treesize - 1);
	for (int IT = 0; IT < m; IT++)
	{
// 		cout << "IT = " << IT << endl;
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			set(1, 0, treesize - 1, a, b);
		}
		if (t == 2)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l--, r--;
			printf("%d\n", get(1, 0, treesize - 1, l, r));
		}
		if (t == 3)
		{
			int l, r, b;
			scanf("%d%d%d", &l, &r, &b);
			l--, r--;
			add(1, 0, treesize - 1, l, r, b);
		}
	}
	return 0;
}