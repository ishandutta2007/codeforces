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

const int MaxN = 1000005;

int n;
int val[MaxN];

vector<int> adj[MaxN];

int sum = 0;
int cnt[MaxN];

int dfs_clock = 0;
int dfn_l[MaxN], dfn_r[MaxN];

inline bool is_anc(int u, int v)
{
	return dfn_l[u] <= dfn_l[v] && dfn_l[v] <= dfn_r[u];
}

void dfs(int u)
{
	dfn_l[u] = ++dfs_clock;
	cnt[u] = val[u];
	for (int v : adj[u])
		dfs(v), cnt[u] += cnt[v];
	dfn_r[u] = dfs_clock;
}

int tot = 0;
int cal[MaxN];

int root = 0;

bool found = false;
int p1, p2;

void solve(int u, int now)
{
//	cout << u << ' ' << now << endl;
	if (found)
		return;

	int down = now + (cal[u] = (cnt[u] * 3 == sum && u != root));
	for (int v : adj[u])
	{
		solve(v, down);
		cal[u] += cal[v];

		if (found)
			return;

		if (down + cal[v] < tot && cnt[v] * 3 == sum)
		{
			for (int k = 1; k <= n; ++k)
				if (!is_anc(k, v) && !is_anc(v, k) && cnt[k] * 3 == sum)
				{
					found = true;
					p1 = v, p2 = k;
					break;
				}

	//		if (!found)
	//			cerr << "sb!" << endl;
		//	assert(found);

			return;
		}
	}
}

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;

	int flag = 1;
	for (int v = 1, u; v <= n; ++v)
	{
		scanf("%d%d", &u, &val[v]);
		sum += val[v];
		if (u > 0)
			adj[u].push_back(v);
		else
			root = v;
	}

	dfs(root);

	for (int u = 1; u <= n; ++u)
		if (cnt[u] * 3 == sum)
			++tot;

	solve(root, 0);

	if (!found)
	{
		for (int u = 1; u <= n; ++u)
			if ((sum - cnt[u]) * 3 == sum && cal[u] - (cnt[u] * 3 == sum) > 0 && u != root)
			{
				for (int v = 1; v <= n; ++v)
					if (is_anc(u, v) && u != v && cnt[v] * 3 == sum)
					{
						found = true;
						p1 = u, p2 = v;
						break;
					}
				assert(found);
				break;
			}
	}

	if (!found)
		puts("-1");
	else
		cout << p1 << ' ' << p2 << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}