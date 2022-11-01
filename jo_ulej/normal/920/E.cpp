#include <bits/stdc++.h>
 
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const ll mod = 1e9 + 7;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)2e5 + 7777;
int segtree[4 * MAX_N];
int met[MAX_N];

inline int choose(int lhs, int rhs)
{
	return (met[lhs] < met[rhs] ? lhs : rhs);
}

void ch(int v, int tl, int tr, int i, int x)
{
	if(tl == tr)
	{
		segtree[v] = i;
		met[i] = x;
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(i <= tm)
			ch(2 * v + 1, tl, tm, i, x);
		else
			ch(2 * v + 2, tm + 1, tr, i, x);

		segtree[v] = choose(segtree[2 * v + 1], segtree[2 * v + 2]);
	}
}

int get(int v, int tl, int tr, int l, int r)
{
	if(tl == l && tr == r)
	{
		return segtree[v];
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(r <= tm)
			return get(2 * v + 1, tl, tm, l, r);

		if(l >= tm + 1)
			return get(2 * v + 2, tm + 1, tr, l, r);

		int i = get(2 * v + 1, tl, tm, l, tm);
		int j = get(2 * v + 2, tm + 1, tr, tm + 1, r);

		return choose(i, j);
	}
}

vector<int> g[MAX_N];
vector<int> answer;
int n, m;

int dfs(int v)
{
	ch(0, 0, n - 1, v, 1);
	int sz = 1;

	if(g[v].empty())
	{
		for(;;)
		{
			int u = get(0, 0, n - 1, 0, n - 1);

			if(met[u])
				break;

			sz += dfs(u);
		}

		return sz;
	}

	sort(g[v].begin(), g[v].end());

	if(g[v].front() != 0)
	{
		int r = g[v].front() - 1;

		for(;;)
		{
			int u = get(0, 0, n - 1, 0, r);

			if(met[u])
				break;

			sz += dfs(u);
		}
	}

	if(g[v].back() != n - 1)
	{
		int l = g[v].back() + 1;

		for(;;)
		{
			int u = get(0, 0, n - 1, l, n - 1);

			if(met[u])
				break;

			sz += dfs(u);
		}
	}

	for(int i = 0; i + 1 < g[v].size(); ++i)
	{
		int l = g[v][i] + 1, r = g[v][i + 1] - 1;

		if(l > r)
			continue;

		for(;;)
		{
			int u = get(0, 0, n - 1, l, r);

			if(met[u])
				break;

			sz += dfs(u);
		}
	}

	return sz;
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		ch(0, 0, n - 1, i, 0);

	for(int i = 0; i < m; ++i)
	{
		int v, u;
		cin >> v >> u;
		--v, --u;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	for(int v = 0; v < n; ++v)
		if(!met[v])
			answer.push_back(dfs(v));

	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	cout << answer << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}