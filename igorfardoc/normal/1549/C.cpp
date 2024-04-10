#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<set<int>> g;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++)
    {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	g[v].insert(u);
    	g[u].insert(v);
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
    	auto it = g[i].lower_bound(i);
    	if(it == g[i].end())
    	{
    		++res;
    	}
    }
    int q;
    cin >> q;
    for(int _ = 0; _ < q; _++)
    {
    	int num;
    	cin >> num;
    	if(num == 3)
    	{
    		cout << res << '\n';
    	}
    	else if(num == 1)
    	{
    		int v, u;
    		cin >> v >> u;
    		--u;
    		--v;
    		int have = (int)(g[v].lower_bound(v) == g[v].end()) + (g[u].lower_bound(u) == g[u].end());
    		res -= have;
    		g[v].insert(u);
    		g[u].insert(v);
    		res += (int)(g[v].lower_bound(v) == g[v].end()) + (g[u].lower_bound(u) == g[u].end());
    	}
    	else
    	{
    		int v, u;
    		cin >> v >> u;
    		--u;
    		--v;
    		int have = (int)(g[v].lower_bound(v) == g[v].end()) + (g[u].lower_bound(u) == g[u].end());
    		res -= have;
    		g[v].erase(g[v].find(u));
    		g[u].erase(g[u].find(v));
    		res += (int)(g[v].lower_bound(v) == g[v].end()) + (g[u].lower_bound(u) == g[u].end());
    	}
    }
}