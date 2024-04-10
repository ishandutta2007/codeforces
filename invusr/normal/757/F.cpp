#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

namespace input
{
	const int BufferSize = 1 << 16 | 1;

	char buffer[BufferSize];
	char *head = buffer + BufferSize;
	const char *tail = head;

	inline char nextChar()
	{
		if (head == tail)
		{
			fread(buffer, 1, BufferSize, stdin);
			head = buffer;
		}
		return *head++;
	}

	inline int getint()
	{
		static char c;
		while ((c = nextChar()) < '0' || c > '9');

		int res = c - '0';
		while ((c = nextChar()) >= '0' && c <= '9')
			res = res * 10 + c - '0';
		return res;
	}
}
using input::getint;

template <class T>
inline void tense(T &a, const T &b)
{
	if (b < a)
		a = b;
}
template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

const int MaxN = 200005;
const int MaxM = 300005;
const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int n, m, vS;

struct halfEdge
{
	int v, w;
	halfEdge *next;
};
halfEdge adj_pool[MaxM * 3 + MaxN], *adj_tail = adj_pool;
halfEdge *adj[MaxN], *adjR[MaxN];
halfEdge *dom[MaxN];

inline void addEdge(const int &u, const int &v, const int &w)
{
	adj_tail->v = v, adj_tail->w = w;
	adj_tail->next = adj[u], adj[u] = adj_tail++;
}
inline void addEdge(halfEdge **adj, const int &u, const int &v)
{
	adj_tail->v = v, adj_tail->next = adj[u];
	adj[u] = adj_tail++;
}

s64 dist[MaxN];

struct item
{
	int u;
	s64 l;
	item() {}
	item(const int &_u, const s64 &_l)
		: u(_u), l(_l) {}

	friend inline bool operator<(const item &lhs, const item &rhs)
	{
		return lhs.l > rhs.l;
	}
};

int q_n = 0;
item q[MaxM];

inline void push(int v, s64 d)
{
	q[q_n++] = item(v, d);
	push_heap(q, q + q_n);
}
inline item pop()
{
	item r = q[0];
	pop_heap(q, q + q_n--);
	return r;
}

inline void calc_dist()
{
	for (int u = 1; u <= n; ++u)
		dist[u] = INF;
	dist[vS] = 0;

	push(vS, 0);
	while (q_n > 0)
	{
		item t = pop();
		if (t.l != dist[t.u])
			continue;
		for (halfEdge *e = adj[t.u]; e; e = e->next)
		{
			s64 l = t.l + e->w;
			if (l < dist[e->v])
			{
				dist[e->v] = l;
				push(e->v, l);
			}
		}
	}
}

int dfs_clock = 0;
int idom[MaxN], sdom[MaxN], idx[MaxN];
int label[MaxN], anc[MaxN], fa[MaxN];

void compress(const int &u)
{
	if (anc[anc[u]])
	{
		compress(anc[u]);
		if (sdom[label[anc[u]]] < sdom[label[u]])
			label[u] = label[anc[u]];
		anc[u] = anc[anc[u]];
	}
}

inline int eval(const int &u)
{
	return anc[u] ? (compress(u), label[u]) : u;
}

void dfs_relabel(const int &u)
{
	sdom[u] = ++dfs_clock;
	label[u] = idx[dfs_clock] = u;
	for (halfEdge *e = adj[u]; e; e = e->next)
	{
		if (dist[u] + e->w != dist[e->v])
			continue;

		addEdge(adjR, e->v, u);
		if (!sdom[e->v])
		{
			fa[e->v] = u;
			dfs_relabel(e->v);
		}
	}
}

int size[MaxN];

inline void build_dominator_tree()
{
	dfs_relabel(vS);

	for (int i = dfs_clock, v; i > 1; --i)
	{
		int u = idx[i];
		for (halfEdge *e = adjR[u]; e; e = e->next)
			tense(sdom[u], sdom[eval(e->v)]);

		if (!(v = fa[u]))
			continue;
		anc[u] = v;
		addEdge(dom, idx[sdom[u]], u);
		for (halfEdge *&e = dom[v]; e; e = e->next)
		{
			int w = eval(e->v);
			idom[e->v] = sdom[w] < sdom[e->v] ? w : v;
		}
	}

	for (int i = 2; i <= dfs_clock; ++i)
	{
		int u = idx[i];
		if (idom[u] != idx[sdom[u]])
			idom[u] = idom[idom[u]];
	}

	int res = 0;
	for (int i = dfs_clock; i >= 1; --i)
	{
		int u = idx[i];
		size[idom[u]] += ++size[u];
		if (u != vS)
			relax(res, size[u]);
	}

	cout << res << endl;
}

int main()
{
	cin >> n >> m >> vS;
	for (int i = 1; i <= m; ++i)
	{
		int u = getint(), v = getint(), w = getint();
		addEdge(u, v, w);
		addEdge(v, u, w);
	}

	calc_dist();
	build_dominator_tree();

	return 0;
}