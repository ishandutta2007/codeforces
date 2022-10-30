#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>

using namespace std;

typedef long long int64;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define ms(a,x)

const int N = 150005;

int lazy[N * 4], val[N * 4], a[N], b[N], c[N];

void make(int a, int l, int r)
{
	if (l == r)
	{
		val[a] = -l;
		lazy[a] = 0;
		return;
	}
	int mid = (l + r) / 2;
	make(a * 2, l, mid);
	make(a * 2 + 1, mid + 1, r);
	val[a] = min(val[a * 2], val[a * 2 + 1]);
}

void add(int a, int l, int r, int ll, int rr, int d)
{
	if (r < ll) return;
	if (rr < l) return;
	if (ll <= l && r <= rr)
	{
		val[a] += d;
		lazy[a] += d;
		return;
	}
	if (lazy[a] != 0)
	{
		val[a * 2] += lazy[a];
		val[a * 2 + 1] += lazy[a];
		lazy[a * 2] += lazy[a];
		lazy[a * 2 + 1] += lazy[a];
		lazy[a] = 0;
	}
	int mid = (l + r) / 2;
	add(a * 2, l, mid, ll, rr, d);
	add(a * 2 + 1, mid + 1, r, ll, rr, d);
	val[a] = min(val[a * 2], val[a * 2 + 1]);
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
//		freopen("a.out","w",stdout);
	#endif
	int n, m, h;
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i]);
	sort(b, b + m);
	for (int i = m; i; --i)
		b[i] = b[i - 1];
	make(1, 1, m);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		c[i] = -1;
		if (a[i] + b[m] >= h)
		{
			int l = 1, r = m;
			while (l < r)
			{
				int mid = (l + r) / 2;
				if (a[i] + b[mid] >= h)
					r = mid;
				else
					l = mid + 1;
			}
			c[i] = l;
		}
		if (c[i] != -1)
			add(1, 1, m, c[i], m, 1);
		if (i > m && c[i - m] != -1)
			add(1, 1, m, c[i - m], m, -1);
		if (i >= m && val[1] >= 0) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}