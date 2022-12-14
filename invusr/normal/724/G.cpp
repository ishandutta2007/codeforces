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
inline s64 gets64()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	s64 res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100005;
const int MaxM = 200005;
const int M = 1000000007;
const int MaxNL = 63;

int n, m;
int prePow[MaxNL];

struct halfEdge
{
	int v;
	s64 w;
	halfEdge *next;
};
halfEdge adj_pool[MaxM * 2], *adj_tail = adj_pool;
halfEdge *adj[MaxN];

inline void addEdge(const int &u, const int &v, const s64 &w)
{
	adj_tail->v = v, adj_tail->w = w;
	adj_tail->next = adj[u], adj[u] = adj_tail++;
}

int book[MaxN];
s64 dep[MaxN];

int cnt[MaxNL][2];
s64 bas[MaxN];

inline void init_lb()
{
	for (int i = 0; i <= 60; ++i)
	{
		cnt[i][0] = cnt[i][1] = 0;
		bas[i] = 0;
	}
}

inline void append_lb(s64 w)
{
	for (int i = 60; i >= 0; --i)
	{
		if (~w >> i & 1)
			continue;
		if (bas[i])
			w ^= bas[i];
		else
		{
			bas[i] = w;
			break;
		}
	}
}

void dfs(const int &u, const int &p, const int &mark)
{
	book[u] = mark;
	for (int i = 0; i <= 60; ++i)
		++cnt[i][dep[u] >> i & 1];

	for (halfEdge *e = adj[u]; e; e = e->next)
	{
		if (!book[e->v])
		{
			dep[e->v] = dep[u] ^ e->w;
			dfs(e->v, u, mark);
		}
		else if (e->v != p)
			append_lb(dep[u] ^ dep[e->v] ^ e->w);
	}
}

inline int solve(const int &root)
{
	init_lb();
	dfs(root, 0, root);

	int l = 0;
	s64 mask = 0;
	for (int i = 0; i <= 60; ++i)
		l += bas[i] > 0, mask |= bas[i];

	int sum = 0;
	int n = cnt[0][0] + cnt[0][1];
	int t = (s64)n * (n - 1) / 2 % M;
	for (int i = 0; i <= 60; ++i)
	{
		int ways = 0;
		if (mask >> i & 1)
			ways = (s64)prePow[l - 1] * t % M;
		else
			ways = (s64)prePow[l] * cnt[i][0] % M * cnt[i][1] % M;
		sum = (sum + (s64)ways * prePow[i]) % M;
	}
	return sum;
}

int main()
{
	n = getint(), m = getint();
	for (int i = 0; i < m; ++i)
	{
		int u = getint(), v = getint();
		s64 w = gets64();
		addEdge(u, v, w);
		addEdge(v, u, w);
	}

	prePow[0] = 1;
	for (int i = 1; i <= 60; ++i)
		prePow[i] = prePow[i - 1] * 2 % M;

	int res = 0;
	for (int u = 1; u <= n; ++u)
		if (!book[u])
			res = (res + solve(u)) % M;

	cout << res << endl;

	return 0;
}