#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>

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
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)2e5 + 777;
const int MAX_LOG_N = 20;

vector<int> g[MAX_N];
bool met[MAX_N];
int c[MAX_N], cnt[MAX_N], d[MAX_N];
int p[MAX_LOG_N][MAX_N];
int n, k;
vector<int> centers;

void dfs(int v)
{
	met[v] = true;
	cnt[v] = c[v];

	bool ok = true;

	for(auto u: g[v])
	{
		if(!met[u])
		{
			d[u] = d[v] + 1;
			dfs(u);

			p[0][u] = v;

			cnt[v] += cnt[u];
			ok &= cnt[u] <= k;
		}
	}

	ok &= (2 * k - cnt[v]) <= k;

	if(ok)
		centers.push_back(v);
}

inline int parent(int v, int h)
{
	for(int log = 0; log < MAX_LOG_N; ++log)
		if(h & (1 << log))
			v = p[log][v];

	return v;
}

inline int lca(int v, int u)
{
	if(d[v] < d[u])
		swap(v, u);

	v = parent(v, d[v] - d[u]);

	if(v == u)
		return v;

	for(int log = MAX_LOG_N - 1; log >= 0; --log)
	{
		int nv = p[log][v], nu = p[log][u];

		if(nv != nu)
			v = nv, u = nu;
	}

	return p[0][v];
}

inline int dist(int v, int u)
{
	int w = lca(v, u);

	return d[v] + d[u] - 2 * d[w];
}

void solve()
{
	cin >> n >> k;

	for(int i = 0; i < 2 * k; ++i)
	{
		int v;
		cin >> v;
		--v;

		c[v] = 1;
	}

	for(int i = 0; i < n - 1; ++i)
	{
		int v, u;
		cin >> v >> u;
		--v, --u;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	dfs(0);

	for(int log = 1; log < MAX_LOG_N; ++log)
		for(int v = 0;v < MAX_N; ++v)
			p[log][v] = p[log - 1][p[log - 1][v]];

	int cc = centers.front();

	for(auto cen: centers)
		if(d[cen] > d[cc])
			cc = cen;

	DBG(cc + 1);

	ll answ = 0;

	for(int v = 0; v < n; ++v)
		if(c[v])
			answ += (ll)dist(v, cc);

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}