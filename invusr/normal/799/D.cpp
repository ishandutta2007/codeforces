#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

const int MaxN = 100005;
const int MaxLiN = 55;
const int INF = 1000000;

int a, b, h, w, n;
int v[MaxN];

int li_n, li[MaxLiN];

struct item
{
	int u, v;
	item() {}
	item(const int &_u, const int &_v)
		: u(_u), v(_v) {}

	friend inline bool operator<(const item &lhs, const item &rhs)
	{
		return lhs.u < rhs.u;
	}
};

int da_n, db_n;
item da[1 << 17 | 1];
item db[1 << 17 | 1];

inline int mul(int u, int v)
{
	return (int)min((s64)u * v, (s64)INF);
}

inline void extend(item *d, int &dn, int k)
{
	int hn = dn, pl = dn = 0, pr = 0;
	static item dl[1 << 17 | 1];
	static item dr[1 << 17 | 1];
	for (int i = 0; i < hn; ++i)
	{
		dl[i] = item(mul(d[i].u, k), d[i].v);
		dr[i] = item(d[i].u, mul(d[i].v, k));
	}

	while (pl < hn || pr < hn)
	{
		if (pr >= hn || (pl < hn && dl[pl] < dr[pr]))
			d[dn++] = dl[pl++];
		else
			d[dn++] = dr[pr++];
	}
}

inline bool check(int x, int vh, int vw)
{
	li_n = 0;
	for (int i = x; i <= n; ++i)
		li[++li_n] = v[i];

	int h = li_n / 2;
	da[da_n = 0, da_n++] = item(1, 1);
	db[db_n = 0, db_n++] = item(vh, vw);
	for (int i = 1; i <= h; ++i)
		extend(da, da_n, li[i]);
	for (int i = h + 1; i <= li_n; ++i)
		extend(db, db_n, li[i]);

	int now = db_n - 1, val = 0;
	for (int i = 0; i < da_n; ++i)
	{
		while (~now && mul(da[i].u, db[now].u) >= a)
			relax(val, db[now--].v);
		if (mul(da[i].v, val) >= b)
			return true;
	}
	return false;
}

int main()
{
	cin >> a >> b >> h >> w >> n;
	for (int i = 1; i <= n; ++i)
		v[i] = getint();

	int l = max(1, n - 33), r = n + 1;
	nth_element(v + 1, v + l, v + r);
	sort(v + l, v + r);

	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid, h, w) || check(mid, w, h))
			l = mid + 1;
		else
			r = mid - 1;
	}

	cout << (r ? n - r + 1 : -1) << endl;

	return 0;
}