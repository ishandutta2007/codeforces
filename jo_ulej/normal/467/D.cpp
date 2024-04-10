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

void tolower(string& s)
{
	for(auto& chr: s)
		if('A' <= chr && chr <= 'Z')
			chr -= 'A', chr += 'a';
}

int cntR(const string& s)
{
	int ret = 0;

	for(auto chr: s)
		ret += (chr == 'r');

	return ret;
}

map<string, int> mp;

const int MAX_N = (int)2e5 + 7;
vector<int> g[MAX_N], gT[MAX_N], g2[MAX_N];
pll cost[MAX_N], cost2[MAX_N], dp[MAX_N];
int scc[MAX_N];
int n, nscc = 0;
bool met[MAX_N], met2[MAX_N];
vector<int> ord;

int getvertidx(string label)
{
	tolower(label);

	if(mp.count(label))
		return mp[label];

	int sz = mp.size();
	mp.insert({label, sz});
	cost[sz] = {cntR(label), label.size()};

	return mp[label];
}

void dfs_topsort(int v)
{
	met[v] = true;

	for(auto u: g[v])
		if(!met[u])
			dfs_topsort(u);

	ord.push_back(v);
}

void dfs_compress(int v)
{
	met[v] = true;
	scc[v] = nscc;

	for(auto u: gT[v])
		if(!met[u])
			dfs_compress(u);
}

void dfs_dp(int v)
{
	met2[v] = true;
	dp[v] = cost2[v];

	for(auto u: g2[v])
	{
		if(!met2[u])
			dfs_dp(u);

		dp[v] = min(dp[v], dp[u]);
	}
}

void solve()
{
	int n1, m1;

	cin >> n1;

	vector<int> query;

	for(int i = 0; i < n1; ++i)
	{
		string s;
		cin >> s;

		query.push_back(getvertidx(s));
	}

	cin >> m1;

	for(int i = 0; i < m1; ++i)
	{
		string s, t;
		cin >> s >> t;

		g[getvertidx(s)].push_back(getvertidx(t));
		gT[getvertidx(t)].push_back(getvertidx(s));
	}

	n = mp.size();
	DBG(n);

	{
		for(int v = 0; v < n; ++v)
			if(!met[v])
				dfs_topsort(v);

		reverse(ord.begin(), ord.end());
		memset(met, 0, n * sizeof(bool));
	}

	{
		for(auto v: ord)
			if(!met[v])
				dfs_compress(v), ++nscc;
	}

	for(int v = 0; v < nscc; ++v)
		cost2[v] = {LL_INF, LL_INF};

	for(int v = 0; v < n; ++v)
	{
		cost2[scc[v]] = min(cost2[scc[v]], cost[v]);

		for(auto u: g[v])
			g2[scc[v]].push_back(scc[u]);
	}

	for(int v = 0; v < nscc; ++v)
		if(!met2[v])
			dfs_dp(v);

	pll ans = {0, 0};

	DBG(nscc);

	for(auto v: query)
	{
		ans.first += dp[scc[v]].first, ans.second += dp[scc[v]].second;
		DBG(dp[scc[v]].first);
		DBG(dp[scc[v]].second);
	}

	cout << ans.first << " " << ans.second << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}