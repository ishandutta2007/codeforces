#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
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

const int MaxN = 100005;
const int MaxM = 100005;

int n, m;

struct edge
{
	int u, v, w;
	int id;

	friend inline bool operator<(const edge &lhs, const edge &rhs)
	{
		return lhs.w < rhs.w;
	}
};

struct le_node
{
	edge e;
	int delta;
	int dep;
	le_node *lc, *rc;

	static le_node pool[], *tail;

	static inline le_node *atom(edge e)
	{
		le_node *p = tail++;
		p->e = e;
		p->delta = p->dep = 0;
		p->lc = p->rc = NULL;
		return p;
	}

	inline void add_delta(int d)
	{
		e.w += d;
		delta += d;
	}
	inline void tag_down()
	{
		if (lc)
			lc->add_delta(delta);
		if (rc)
			rc->add_delta(delta);
		delta = 0;
	}

	static le_node *merge(le_node *lhs, le_node *rhs)
	{
		if (!lhs)
			return rhs;
		if (!rhs)
			return lhs;
		if (rhs->e < lhs->e)
			swap(lhs, rhs);

		lhs->tag_down();
		lhs->rc = merge(lhs->rc, rhs);

		if (!lhs->lc || lhs->lc->dep < lhs->rc->dep)
			swap(lhs->lc, lhs->rc);
		lhs->dep = lhs->lc->dep + 1;
		return lhs;
	}
};
le_node le_node::pool[MaxM], *le_node::tail = le_node::pool;
le_node *inE[MaxN + MaxN];

int ufs[MaxN + MaxN];

int ufs_find(int v)
{
	return ufs[v] == v ? v : ufs[v] = ufs_find(ufs[v]);
}

bool book[MaxN];

int sta_n = 0, sta[MaxN + MaxN];
bool insta[MaxN + MaxN];

int next[MaxN + MaxN];
int outer[MaxN + MaxN];

inline bool solve(int rv)
{
	for (int u = 1; u <= n; ++u)
		ufs[u] = outer[u] = u;

	book[rv] = true;
	inE[rv] = NULL;

	for (int sv = 1; sv <= n; ++sv)
		if (!book[sv])
		{
			int m = n;

			sta_n = 0;
			sta[++sta_n] = sv, insta[sv] = true;

			while (true)
			{
				int u = sta[sta_n];
				if (u <= n && book[u])
				{
					insta[u] = false, --sta_n;
					break;
				}

				while (inE[u] && ufs_find(inE[u]->e.u) == ufs_find(inE[u]->e.v))
				{
					inE[u]->tag_down();
					inE[u] = le_node::merge(inE[u]->lc, inE[u]->rc);
				}
				if (!inE[u])
					return false;

				int v = ufs_find(inE[u]->e.u);
				if (insta[v])
				{
					next[++m] = 0;
					ufs[m] = outer[m] = m;
					inE[m] = NULL;

					int pos_v = sta_n;
					while (sta[pos_v] != v)
						--pos_v;

					for (int k = pos_v; k <= sta_n; ++k)
					{
						int vm = sta[k];
						next[vm] = ufs_find(inE[vm]->e.u);

						inE[vm]->tag_down();

						le_node *rest = le_node::merge(inE[vm]->lc, inE[vm]->rc);
						if (rest)
						{
							rest->add_delta(-inE[vm]->e.w);
							inE[m] = le_node::merge(inE[m], rest);
						}

						inE[vm]->lc = inE[vm]->rc = NULL;
					}
					for (int k = pos_v; k <= sta_n; ++k)
					{
						int vm = sta[k];
						outer[vm] = ufs[vm] = m;
						insta[vm] = false;
					}
					sta_n = pos_v - 1;

					v = m;
				}

				insta[sta[++sta_n] = v] = true;
			}

			while (sta_n > 0)
			{
				int u = sta[sta_n--];
				insta[u] = false;

				if (u <= n)
				{
					inE[u]->lc = inE[u]->rc = NULL, book[u] = true;
					ufs[u] = u;
				}
				else
				{
					int vs = inE[u]->e.v;
					int vm = vs;
					int dw = 0;
					do
					{
						for (int v = next[vm]; v != vm; v = next[v])
							sta[++sta_n] = v, book[v] = true;
						dw += inE[vm]->e.w;
						vm = outer[vm];
					}
					while (vm != u);

					inE[vs] = inE[u], inE[vs]->e.w += dw;
					inE[vs]->lc = inE[vs]->rc = NULL, book[vs] = true;
					ufs[vs] = vs;
				}
			}
		}
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	n = getint(), m = getint();
	for (int i = 1; i <= m; ++i)
	{
		int u = getint(), v = getint(), w = getint();
		inE[v] = le_node::merge(inE[v], le_node::atom((edge){u, v, w, i}));
	}

	if (!solve(1))
		puts("-1");
	else
	{
		vector<int> res;
		for (int u = 2; u <= n; ++u)
			if (inE[u]->e.w == 1)
				res.push_back(inE[u]->e.id);
		printf("%d\n", res.size());
		for (vector<int>::iterator it = res.begin(); it != res.end(); ++it)
			printf("%d ", *it);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}