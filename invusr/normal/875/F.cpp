#include <algorithm>
#include <iostream>
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

const int MaxN = 200000;
const int MaxM = 200000;

int n, m;

struct edge
{
	int u, v, w;
	edge() {}
	edge(const int &_u, const int &_v, const int &_w)
		: u(_u), v(_v), w(_w) {}

	friend inline bool operator<(const edge &lhs, const edge &rhs)
	{
		return lhs.w > rhs.w;
	}
};
edge allE[MaxM];

int ufs[MaxN + 1];
bool cir[MaxN + 1];

int ufs_find(const int &u)
{
	return ufs[u] == u ? u : ufs[u] = ufs_find(ufs[u]);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		allE[i].u = getint(), allE[i].v = getint();
		allE[i].w = getint();
	}

	sort(allE, allE + m);

	for (int u = 1; u <= n; ++u)
		ufs[u] = u, cir[u] = false;

	s64 res = 0;
	for (int i = 0; i < m; ++i)
	{
		int u = ufs_find(allE[i].u);
		int v = ufs_find(allE[i].v);
		int w = allE[i].w;

		if (u != v)
		{
			if (cir[u] && cir[v])
				continue;

			ufs[u] = v;
			cir[v] |= cir[u];
			res += w;
		}
		else if (!cir[u])
		{
			cir[u] = true;
			res += w;
		}
	}

	cout << res << endl;

	return 0;
}