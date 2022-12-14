#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
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

const int MaxN = 100005;
const int INF = 1000000000;

int n, m, vC;
bool is_black[MaxN];

struct halfEdge
{
	int v, w;
	halfEdge *next;
};
halfEdge adj_pool[MaxN * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxN];

inline void addEdge(const int &u, const int &v, const int &w)
{
	adj_tail->v = v, adj_tail->w = w;
	adj_tail->next = adj[u], adj[u] = adj_tail++;
}

int book_mark = 0;
int book[MaxN];

int dist[MaxN];
int prev[MaxN];

inline int get_most_distant(const int &sv)
{
	int v = sv;
	int q_n = 0;
	static int q[MaxN];

	q[q_n++] = sv;
	book[sv] = ++book_mark;
	dist[sv] = 0;
	for (int i = 0; i < q_n; ++i)
	{
		int u = q[i];
		if (is_black[u] && dist[u] > dist[v])
			v = u;

		for (halfEdge *e = adj[u]; e; e = e->next)
			if (book[e->v] != book_mark)
			{
				dist[e->v] = dist[u] + e->w;
				book[e->v] = book_mark;
				prev[q[q_n++] = e->v] = u;
			}
	}

	return v;
}

inline int get_root(const int &bv)
{
	int fv = get_most_distant(bv);
	int sv = get_most_distant(fv);

	int vC = 0, wC = INF;
	for (int u = sv; u != fv; u = prev[u])
		if (tense(wC, abs(dist[u] * 2 - dist[sv])))
			vC = u;
	return vC;
}

int subtr[MaxN];
int depest[MaxN], depestN[MaxN];
int blackN[MaxN];

int dfs(const int &u, const int &prev)
{
	depest[u] = 0;
	depestN[u] = blackN[u] = 0;
	if (is_black[u])
		blackN[u] = depestN[u] = 1, depest[u] = dist[u];

	for (halfEdge *e = adj[u]; e; e = e->next)
		if (e->v != prev)
		{
			subtr[e->v] = u == vC ? e->v : subtr[u];
			dist[e->v] = dist[u] + e->w;
			blackN[u] += dfs(e->v, u);

			if (relax(depest[u], depest[e->v]))
				depestN[u] = depestN[e->v];
			else if (depest[e->v] && depest[u] == depest[e->v])
				depestN[u] += depestN[e->v];
		}

	return blackN[u];
}

int main()
{
	n = getint(), m = getint();

	int sv;
	for (int i = 0; i < m; ++i)
		is_black[sv = getint()] = true;
	for (int i = 1; i < n; ++i)
	{
		int u = getint(), v = getint(), w = getint();
		addEdge(u, v, w);
		addEdge(v, u, w);
	}

	vC = get_root(sv);
	dist[vC] = 0, dfs(vC, 0);

	int depestF = 0, depestFN = 0, depestFV = 0;
	int depestS = 0, depestSN = 0, depestSV = 0;
	for (halfEdge *e = adj[vC]; e; e = e->next)
	{
		if (depest[e->v] > depestF)
		{
			depestS = depestF, depestF = depest[e->v];
			depestSN = depestFN;
			depestFV = e->v, depestFN = 1;
		}
		else if (depest[e->v] == depestF)
			++depestFN, depestSV = e->v;
		else if (relax(depestS, depest[e->v]))
			depestSN = 1;
		else if (depestS == depest[e->v])
			++depestSN;
	}

	int res = -1, resN = 0;
	for (int u = 1; u <= n; ++u)
	{
		if (is_black[u])
			continue;

		int now = blackN[u], v = subtr[u];
		if (u != vC && depest[u] == depest[v] && depestN[u] == depestN[v])
		{
			if (depest[u] == depestS)
				if (depestS && depestFN == 1 && depestSN == 1)
					now += blackN[depestFV];
			if (depest[u] == depestF)
			{
				if (depestFN == 1)
					now += blackN[vC] - blackN[v];
				else if (depestFN == 2)
				{
					int kp = v == depestFV ? depestSV : depestFV;
					now += blackN[kp];
				}
			}
		}

		if (relax(res, now))
			resN = 1;
		else if (res == now)
			++resN;
	}

	cout << res << ' ' << resN << endl;

	return 0;
}