#include <algorithm>
#include <cstdio>
#include <map>
using ll = long long;
namespace segT
{
	int seg[800005];
	void modify(int u, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			seg[u] = val;
			return;
		}
		int m = l + r >> 1;
		if (pos <= m)
			modify(u << 1, l, m, pos, val);
		else
			modify(u << 1 | 1, m + 1, r, pos, val);
		seg[u] = std::min(seg[u << 1], seg[u << 1 | 1]);
	}
	int query(int u, int l, int r, int pos)
	{
		if (l == r)
			return seg[u];
		int m = l + r >> 1;
		if (pos <= m)
			return query(u << 1, l, m, pos);
		return std::min(seg[u << 1], query(u << 1 | 1, m + 1, r, pos));
	}
}
struct data
{
	ll k, b;
	inline data operator +(const data &a) const { return {k + a.k, b + a.b}; }
	inline void operator +=(const data &a) { *this = *this + a; }
	inline ll operator ()(const int &x) const { return k * x + b; }
} seg[20000005];
int rt[200005], lson[20000005], rson[20000005], t_cnt;
void modify(int &u, int l, int r, int L, int R, data val)
{
	int v = u;
	u = ++t_cnt;
	lson[u] = lson[v];
	rson[u] = rson[v];
	seg[u] = seg[v];
	if (L <= l && r <= R)
	{
		seg[u] += val;
		return;
	}
	int m = l + r >> 1;
	if (L <= m)
		modify(lson[u], l, m, L, R, val);
	if (m < R)
		modify(rson[u], m + 1, r, L, R, val);
}
data query(int u, int l, int r, int pos)
{
	if (!u)
		return {0, 0};
	if (l == r)
		return seg[u];
	data res = seg[u];
	int m = l + r >> 1;
	if (pos <= m)
		res += query(lson[u], l, m, pos);
	else
		res += query(rson[u], m + 1, r, pos);
	return res;
}
int main()
{
	// freopen("1148H.in", "r", stdin);
	ll ans = 0;
	int n;
	scanf("%d", &n);
	std::map<int, int> pre = {{ -1, -1}, {0, 0}, {n + 1, 0}};
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		a = (a + ans) % (n + 1);
		rt[i] = i ? rt[i - 1] : 0;
		segT::modify(1, 0, n, a, i + 1);
		if (pre.count(a))
		{
			int x = (--pre.find(a))->second, y = (++pre.find(a))->first;
			int orig = pre[a], cur = a;
			pre.erase(a);
			while (cur < y)
			{
				int val = segT::query(1, 0, n, cur);
				int l = cur, r = y - 1, res = -1;
				while (l <= r)
				{
					int m = l + r >> 1;
					if (segT::query(1, 0, n, m) == val)
					{
						res = m;
						l = m + 1;
					}
					else
						r = m - 1;
				}
				modify(rt[i], 0, n, cur, res, {val - orig, -(ll)(val - orig) * i});
				if (val != x)
					pre[cur] = val;
				cur = res + 1;
			}
		}
		auto calc = [&] (int pos, int k) { return query(rt[pos], 0, n, k)(pos + 1); };
		auto solve = [&] (int l, int r, int k)
		{
			if (k < 0)
				return (ll)(r - l + 2) * (r - l + 1) / 2;
			int x = l, y = r, res = r + 1;
			while (x <= y)
			{
				int m = x + y >> 1;
				if (calc(m, k) - calc(m - 1, k) > l)
				{
					res = m;
					y = m - 1;
				}
				else
					x = m + 1;
			}
			return calc(r, k) - calc(res - 1, k) - (ll)l * (r - res + 1);
		};
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		l = (l + ans) % (i + 1);
		r = (r + ans) % (i + 1);
		k = (k + ans) % (n + 1);
		if (l > r)
			std::swap(l, r);
		printf("%lld\n", ans = solve(l, r, k - 1) - solve(l, r, k));
	}
	return 0;
}