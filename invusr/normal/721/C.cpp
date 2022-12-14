#include <bits/stdc++.h>
using namespace std;

#define prev PREV

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
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 5001;
const int MaxM = 5001;
const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int n, m, nT;

struct halfEdge
{
	int v, w;
	halfEdge *next;
};
halfEdge adj_pool[MaxM], *adj_tail = adj_pool;
halfEdge *adj[MaxN];

inline void addEdge(const int &u, const int &v, const int &w)
{
	adj_tail->v = v, adj_tail->w = w;
	adj_tail->next = adj[u], adj[u] = adj_tail++;
}

int deg[MaxN];

int f[MaxN][MaxN];
int prev[MaxN][MaxN];

int main()
{
	cin >> n >> m >> nT;
	for (int i = 1; i <= m; ++i)
	{
		int u = getint(), v = getint(), w = getint();
		addEdge(u, v, w), ++deg[v];
	}

	for (int u = 1; u <= n; ++u)
		for (int i = 1; i <= n; ++i)
			f[u][i] = nT + 1;
	f[1][1] = 0;

	int q_n = 0;
	static int q[MaxN];
	for (int u = 1; u <= n; ++u)
		if (!deg[u])
			q[++q_n] = u;
	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i];
		for (halfEdge *e = adj[u]; e; e = e->next)
		{
			for (int j = 1; j <= n; ++j)
				if (tense(f[e->v][j + 1], f[u][j] + e->w))
					prev[e->v][j + 1] = u;
			if (--deg[e->v] == 0)
				q[++q_n] = e->v;
		}
	}

	for (int i = n; i >= 1; --i)
		if (f[n][i] <= nT)
		{
			cout << i << endl;

			static vector<int> path;
			for (int j = i, x = n; j > 0; --j)
			{
				path.push_back(x);
				x = prev[x][j];
			}
			reverse(path.begin(), path.end());
			for (int i: path)
				printf("%d ", i);
			break;
		}

	return 0;
}