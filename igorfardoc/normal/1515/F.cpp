#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, x;
vector<ll> a;
vector<unordered_set<int>> g;
map<pair<int, int>, int> num;
vector<ll> ans;
set<pair<ll, int>> s;

bool do1(int v, int u)
{
	//cout << v << ' ' << u << endl;
	ll v1 = a[v];
	ll u1 = a[u];
	if(v1 + u1 < x)
	{
		return false;
	}
	s.erase(s.find({v1, v}));
	s.erase(s.find({u1, u}));
	ans.push_back(num[{min(v, u), max(v, u)}]);
	//cout << 2 << endl;
	if(g[v].size() < g[u].size())
	{
		swap(v, u);
		swap(v1, u1);
	}
	a[v] = v1 + u1 - x;
	s.insert({a[v], v});
	for(int ver : g[u])
	{
		if(ver == v)
		{
			continue;
		}
		num[{min(v, ver), max(v, ver)}] = num[{min(u, ver), max(u, ver)}];
		g[v].insert(ver);
		g[ver].erase(g[ver].find(u));
		g[ver].insert(v);
	}
	g[v].erase(g[v].find(u));
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m >> x;
    a.resize(n);
    g.resize(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	s.insert({a[i], i});
    }
    for(int i = 0; i < m; i++)
    {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	num[{min(v, u), max(v, u)}] = i;
    	g[v].insert(u);
    	g[u].insert(v);
    }
    while(s.size() > 1)
    {
    	auto it = s.end();
    	--it;
    	int v = (*it).second;
    	int u = *(g[v].begin());
    	if(!do1(v, u))
    	{
    		cout << "NO\n";
    		return 0;
    	}
    }
    cout << "YES\n";
    for(int i = 0; i < n - 1; i++)
    {
    	cout << ans[i] + 1 << '\n';
    }
}