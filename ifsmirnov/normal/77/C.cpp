#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
const int maxn = 100500;
typedef long long ll;
#define pb push_back
typedef pair<ll, ll> pll;
#define mp make_pair
#define se second
#define fi first

int n, s;
vector<int> e[maxn];
ll k[maxn], f[maxn], g[maxn];

void scan();
void solve();
void dfs(int, int);

int main()
{
//	freopen("input.txt", "r", stdin);
	ios :: sync_with_stdio(false);
	

	scan();
	solve();

	return 0;
};
void scan()
{
	cin >> n;
	forn(i, n)
		cin >> k[i];
	int a, b;
	forn(i, n-1)
	{
		cin >> a >> b;
		e[a-1].pb(b-1);
		e[b-1].pb(a-1);
	}
	cin >> s;
	s--;
};
void solve()
{
	dfs(s, -1);
	cout << f[s];
};
void dfs (int v, int anc)
{
	if (e[v].size() == 1 && e[v][0] == anc)
		return (void)(f[v] = 0, g[v] = k[v]);
	vector<pll> kids;
	forn(i, e[v].size())
	{
		int to = e[v][i];
		if (to == anc)
			continue;
	 	dfs(to, v);
	 	kids.pb(mp(f[to], g[to]));
	}
	int n = kids.size();
	ll up = k[v] - (anc != -1);
	sort(kids.begin(), kids.end());
	reverse(kids.begin(), kids.end());
	f[v] = 0;
	forn(i, n)
	{
		if (up == 0)
			break;
		f[v] += kids[i].fi + 2;	
        kids[i].se--;
		up--;
	}	
	forn(i, n)
	{
		if (up == 0)
			break;
		f[v] += 2*min(up, kids[i].se);
		up -= min(up, kids[i].se);
	}
	g[v] = up+1;
};