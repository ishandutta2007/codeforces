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

const int MaxN = 300000;
const int MaxM = 300000;
const int MaxNF = 20;
const int INF = 0x3f3f3f3f;

struct point
{
	int x, y;
	point() {}
	point(const int &_x, const int &_y)
		: x(_x), y(_y) {}

	friend inline bool operator<(const point &lhs, const point &rhs)
	{
		if (lhs.x != rhs.x)
			return lhs.x < rhs.x;
		return lhs.y < rhs.y;
	}
};

using edge = point;

int n, m;
point pos[MaxN + 1];

map<point, int> all;

vector<int> adj[MaxN + 1];

vector<int> out[MaxN + 1];

int ufs[MaxN + 1];
int num[MaxN + 1], bot[MaxN + 1];
vector<int> vertices[MaxN + 1];

int ufs_find(const int &u)
{
	return ufs[u] == u ? u : ufs[u] = ufs_find(ufs[u]);
}

int pref[MaxN + 1];

int lab[MaxN + 1];

inline void compress_graph()
{
	vector<edge> extra;

	for (int i = 1; i <= n; ++i)
	{
		ufs[i] = i;
		num[i] = 1, bot[i] = pos[i].y;
	}

	for (int i = 1; i <= n; ++i)
	{
		int x = pos[i].x, y = pos[i].y;
		point u = {x + 1, y + 0};
		point v = {x + 0, y + 1};

		if (all.count(u))
		{
			int j = all[u];
			adj[i].push_back(j);
			adj[j].push_back(i);

			extra.emplace_back(i, j);
		}

		if (all.count(v))
		{
			int j = all[v];
			adj[i].push_back(j);
			adj[j].push_back(i);

			int fx = ufs_find(i);
			int fy = ufs_find(j);
			bot[fx] = min(bot[fx], bot[fy]);
			num[fx] += num[fy];
			ufs[fy] = fx, num[fy] = 0;
		}
	}

	for (int i = 1; i <= n; ++i)
		vertices[ufs_find(i)].push_back(i);

	for (edge e : extra)
	{
		int u = ufs_find(e.x);
		int v = ufs_find(e.y);
		if (u != v)
		{
			out[u].push_back(v);
			out[v].push_back(u);
		}
	}

	for (int u = 1; u <= n; ++u)
	{
		auto &v = out[u];
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}

	pref[0] = 0;
	for (int i = 1; i <= n; ++i)
		pref[i] = pref[i - 1] + num[i];

	for (int i = 1; i <= n; ++i)
	{
		int u = ufs[i];
		lab[i] += pref[u - 1];
		lab[i] += pos[i].y - bot[u] + 1;
	}
}

struct seg_tree
{
	static const int TN = 524288;

	int val[TN << 1 | 1];

	inline void update(const int &p)
	{
		val[p] = min(val[p << 1 | 0], val[p << 1 | 1]);
	}

	inline void build()
	{
		for (int p = TN + 1; p <= TN + n; ++p)
			val[p] = INF;
		for (int p = TN - 1; p; --p)
			update(p);
	}

	inline void modify(int q, int v)
	{
		q += TN;
		while (q > 0)
		{
			val[q] = min(val[q], v);
			q >>= 1;
		}
	}

	inline int query(int l, int r)
	{
		int res = INF;
		for (l += TN - 1, r += TN + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
		{
			if (~l & 1)
				res = min(res, val[l ^ 1]);
			if (r & 1)
				res = min(res, val[r ^ 1]);
		}
		return res;
	}
};
seg_tree seg_l, seg_r;

int book_mark = 0;
int book[MaxN + 1];

bool deleted[MaxN + 1];

int q_n, q[MaxN + 1];
int weight[MaxN + 1], heavy[MaxN + 1];
int fa[MaxN + 1];

inline int centroid(const int &sv)
{
	q[q_n = 1] = sv, fa[sv] = 0;
	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i];
		for (int v : out[u])
			if (!deleted[v] && v != fa[u])
			{
				q[++q_n] = v;
				fa[v] = u;
			}
	}

	int vC = -1, wC = q_n + 1;
	for (int i = 1; i <= q_n; ++i)
		weight[q[i]] = 1, heavy[q[i]] = 1;
	for (int i = q_n; i >= 1; --i)
	{
		int u = q[i], v = fa[q[i]];
		weight[v] += weight[u];
		heavy[v] = max(heavy[v], weight[u]);

		int vW = max(heavy[u], q_n - weight[u]);
		if (vW < wC)
			wC = vW, vC = u;
	}

	return vC;
}

int anc[MaxN + 1][MaxNF + 1];
int bel[MaxN + 1][MaxNF + 1];
int dep[MaxN + 1][MaxNF + 1];

inline void bfs(const int &sv, const int &lev)
{
	++book_mark;

	q_n = 0;
	for (int i : vertices[sv])
	{
		anc[i][lev] = sv;
		bel[i][lev] = lab[i];
		dep[i][lev] = 0;

		q[++q_n] = i;
		book[i] = book_mark;
	}

	for (int i = 1; i <= q_n; ++i)
	{
		int u = q[i];
		for (int v : adj[u])
		{
			if (deleted[ufs[v]])
				continue;
			if (book[v] == book_mark)
				continue;

			anc[v][lev] = sv;
			bel[v][lev] = bel[u][lev];
			dep[v][lev] = dep[u][lev] + 1;

			q[++q_n] = v;
			book[v] = book_mark;
		}
	}
}

void build_lev(const int &u, const int &lev)
{
	int vC = centroid(u);

	deleted[vC] = true;

	bfs(vC, lev);

	for (int v : out[vC])
		if (!deleted[v])
			build_lev(v, lev + 1);
}

inline void modify(const int &u)
{
	for (int i = 0; i <= MaxNF && anc[u][i]; ++i)
	{
		int x = bel[u][i], v = dep[u][i];
		seg_l.modify(x, v - x);
		seg_r.modify(x, v + x);
	}
}

inline int query(const int &u)
{
	int res = INF;
	for (int i = 0; i <= MaxNF && anc[u][i]; ++i)
	{
		int x = bel[u][i], v = dep[u][i];
		int l = pref[anc[u][i] - 1] + 1;
		int r = pref[anc[u][i]];

		int a = seg_l.query(l, x) + x;
		int b = seg_r.query(x, r) - x;
		res = min(res, min(a, b) + v);
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		pos[i].x = getint();
		pos[i].y = getint();
		all.emplace(pos[i], i);
	}

	compress_graph();

	build_lev(ufs_find(1), 0);

	seg_l.build();
	seg_r.build();

	cin >> m;
	while (m--)
	{
		int t = getint();
		int x = getint(), y = getint();

		int u = all[{x, y}];

		if (t == 1)
			modify(u);
		else
		{
			int res = query(u);
			res > n ? res = -1 : 0;
			printf("%d\n", res);
		}
	}

	return 0;
}