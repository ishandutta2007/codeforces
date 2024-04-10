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

const int treesize = 1 << 17;

pair<int, int> tree[treesize * 2];
ll sum[treesize * 2];
int n, m;

inline void set(int cur, int cl, int cr, int x, int t)
{
	if (cl > x || cr < x) return;
	if (cl == cr)
	{
		tree[cur] = make_pair(t, x);
		sum[cur] = t;
		return;
	}
	int cm = (cl + cr) / 2;
	set(cur * 2, cl, cm, x, t);
	set(cur * 2 + 1, cm + 1, cr, x, t);
	tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
	sum[cur] = sum[cur * 2] + sum[cur * 2 + 1];
}

inline pair<int, int> getmax(int cur, int cl, int cr, int l, int r)
{
	if (cl > r || cr < l) return make_pair(-1, -1);
	if (cl >= l && cr <= r) return tree[cur];
	int cm = (cl + cr) / 2;
	return max(getmax(cur * 2, cl, cm, l, r), getmax(cur * 2 + 1, cm + 1, cr, l, r));
}

inline ll getsum(int cur, int cl, int cr, int l, int r)
{
	if (cl > r || cr < l) return 0;
	if (cl >= l && cr <= r) return sum[cur];
	int cm = (cl + cr) / 2;
	return getsum(cur * 2, cl, cm, l, r) + getsum(cur * 2 + 1, cm + 1, cr, l, r);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		set(1, 0, treesize - 1, i, a);
	}
	for (int i = 0; i < m; i++)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l--, r--;
			printf(LLD "\n", getsum(1, 0, treesize - 1, l, r));
		} else if (op == 2)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l--, r--;
			pair<int, int> maxwh = getmax(1, 0, treesize - 1, l, r);
			while (maxwh.first >= x)
			{
				set(1, 0, treesize - 1, maxwh.second, maxwh.first % x);
				maxwh = getmax(1, 0, treesize - 1, l, r);
			}
		} else if (op == 3)
		{
			int x, t;
			scanf("%d%d", &x, &t);
			x--;
			set(1, 0, treesize - 1, x, t);
		}
	}
	return 0;
}