#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <map>
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

const int MaxN = 100005;
const int MaxNV = MaxN * 2;
const int MaxSegN = MaxN * 4;

int n, q;

struct edge
{
	int u, v;
	edge() {}
	edge(const int &_u, const int &_v)
		: u(_u), v(_v) {}

	friend inline bool operator<(const edge &lhs, const edge &rhs)
	{
		if (lhs.u != rhs.u)
			return lhs.u < rhs.u;
		return lhs.v < rhs.v;
	}

	friend inline bool operator==(const edge &lhs, const edge &rhs)
	{
		return lhs.u == rhs.u && lhs.v == rhs.v;
	}
	friend inline bool operator!=(const edge &lhs, const edge &rhs)
	{
		return !(lhs == rhs);
	}
};

vector<edge> pool[MaxSegN];
stack<edge> oper[MaxSegN];
map<edge, int> last;

void seg_add(int p, int pL, int pR, int qL, int qR, edge e)
{
	if (qL <= pL && qR >= pR)
	{
		pool[p].push_back(e);
		return;
	}

	int pM = pL + pR >> 1;
	if (qL <= pM)
		seg_add(p << 1 | 0, pL, pM, qL, qR, e);
	if (qR > pM)
		seg_add(p << 1 | 1, pM + 1, pR, qL, qR, e);
}

int ufs[MaxNV];
int size[MaxNV];

int ufs_find(int v)
{
	return ufs[v] == v ? v : ufs_find(ufs[v]);
}

inline void ufs_add(int p, int u, int v)
{
	u = ufs_find(u);
	v = ufs_find(v);
	if (u != v)
	{
		oper[p].emplace(u, v);
		size[u] += size[v];
		ufs[v] = u;
	}
}

inline bool ufs_union(int p, int u, int v)
{
	int fx = ufs_find(u);
	int fy = ufs_find(v);
	if (fx == fy)
		return false;
	ufs_add(p, u + n, v);
	ufs_add(p, v + n, u);
	return true;
}

inline void ufs_undo(int p)
{
	while (!oper[p].empty())
	{
		edge e = oper[p].top();
		oper[p].pop();
		size[e.u] -= size[e.v];
		ufs[e.v] = e.v;
	}
}

inline void print(int l, int r, const char *s)
{
	for (int i = l; i <= r; ++i)
		puts(s);
}

void solve(int p, int pL, int pR)
{
	bool ok = true;
	for (edge e : pool[p])
		if (!ufs_union(p, e.u, e.v))
		{
			ok = false;
			break;
		}

	if (!ok)
		print(pL, pR, "NO");
	else if (pL == pR)
		print(pL, pR, "YES");
	else
	{
		int pM = pL + pR >> 1;
		solve(p << 1 | 0, pL, pM);
		solve(p << 1 | 1, pM + 1, pR);
	}

	ufs_undo(p);
}

int main()
{
	cin >> n >> q;
	for (int i = 1; i <= q; ++i)
	{
		int u = getint(), v = getint();
		if (u > v)
			swap(u, v);

		edge e(u, v);
		auto it = last.find(e);
		if (it == last.end())
			last.insert(make_pair(e, i));
		else
		{
			seg_add(1, 1, q, it->second, i - 1, e);
			last.erase(it);
		}
	}

	for (auto it : last)
		seg_add(1, 1, q, it.second, q, it.first);

	for (int u = 1; u <= n + n; ++u)
		ufs[u] = u, size[u] = 1;
	solve(1, 1, q);

	return 0;
}