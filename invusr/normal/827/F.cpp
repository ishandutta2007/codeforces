#include <bits/stdc++.h>
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

const int MaxN = 500000;
const int MaxM = 500000;

int n, m;

struct edge
{
	int u, v, l, r;
	edge() {}
	edge(const int &_u, const int &_v, const int &_l, const int &_r)
		: u(_u), v(_v), l(_l), r(_r) {}

	friend inline bool operator<(const edge &lhs, const edge &rhs)
	{
		if (lhs.l != rhs.l)
			return lhs.l > rhs.l;
		return lhs.r > rhs.r;
	}
};

priority_queue<edge> q;

int last[2][MaxN + 1];
vector<edge> adj[2][MaxN + 1];

inline void extend(int v, int l, int r)
{
	last[l & 1][v] = max(last[l & 1][v], r);

	for (edge &e : adj[l & 1][v])
		e.l = l, q.push(e);

	adj[l & 1][v].clear();
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u = getint(), v = getint();
		int l = getint(), r = getint() - 1;
		q.emplace(u, v, l, r - ((l ^ r) & 1));
		q.emplace(v, u, l, r - ((l ^ r) & 1));
		q.emplace(u, v, l + 1, r - ((l ^ r ^ 1) & 1));
		q.emplace(v, u, l + 1, r - ((l ^ r ^ 1) & 1));
	}

	last[0][1] = 0;
	for (int u = 2; u <= n; ++u)
		last[0][u] = -1;
	for (int u = 1; u <= n; ++u)
		last[1][u] = -1;

	while (!q.empty())
	{
		edge e = q.top();
		q.pop();

		if (e.l > e.r)
			continue;

		if (e.l > last[e.l & 1][e.u])
			adj[e.l & 1][e.u].push_back(e);
		else if (e.v != n)
			extend(e.v, e.l + 1, e.r + 1);
		else
		{
			cout << e.l + 1 << endl;
			return 0;
		}
	}

	cout << (n == 1 ? 0 : -1) << endl;

	return 0;
}