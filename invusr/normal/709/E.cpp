#include <bits/stdc++.h>
using namespace std;

typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

typedef double r32;
typedef long double r64;

template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tense(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

inline int getint()
{
	static char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');

	if (c == '-')
	{
		int res = 0;
		while ((c = getchar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return -res;
	}
	else
	{
		int res = c - '0';
		while ((c = getchar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return res;
	}
}
inline s64 gets64()
{
	static char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');

	if (c == '-')
	{
		s64 res = 0;
		while ((c = getchar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return -res;
	}
	else
	{
		s64 res = c - '0';
		while ((c = getchar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return res;
	}
}

const int MaxN = 400005;

int n;

struct halfEdge
{
	int v;
	halfEdge *next;
};
halfEdge adj_pool[MaxN * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxN];

inline void addEdge(const int &u, const int &v)
{
	adj_tail->v = v, adj_tail->next = adj[u], adj[u] = adj_tail++;
	adj_tail->v = u, adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int size[MaxN];

int nC, vC[233];

void dfs1(int u, int v)
{
	int vW = size[u] = 1;
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != v)
		{
			dfs1(e->v, u);
			size[u] += size[e->v];
			relax(vW, size[e->v]);
		}
	relax(vW, n - size[u]);

	if (vW <= n >> 1)
		vC[++nC] = u;
}

bool orz[MaxN];

void dfs2(int u, int v)
{
	orz[u] = true;
	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != v)
			dfs2(e->v, u);
}

int main()
{
	n = getint();
	for (int i = 1; i < n; ++i)
	{
		int u = getint(), v = getint();
		addEdge(u, v);
	}

	dfs1(1, 0);

	if (nC == 2)
	{
		for (int i = 1; i <= n; ++i)
		{
			putchar('1');
			putchar(' ');
		}
		return 0;
	}

	int c = vC[1];
	dfs1(c, 0);

	int gzb = -1, csy = -1;
	for (halfEdge *e = adj[c]; e; e = e->next)
	{
		if (gzb == -1 || size[e->v] >= size[gzb])
			csy = gzb, gzb = e->v;
		else if (csy == -1 || size[e->v] > size[csy])
			csy = e->v;
	}

	dfs2(gzb, c);

	for (int i = 1; i <= n; ++i)
	{
		if (i == c)
			printf("1 ");
		else
		{
			int l = size[orz[i] ? csy : gzb];
			if (n - l - size[i] <= n >> 1)
				putchar('1');
			else
				putchar('0');
			putchar(' ');
		}
	}

	return 0;
}