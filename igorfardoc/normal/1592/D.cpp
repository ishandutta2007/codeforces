#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> used;
set<pair<int, int>> ban, ans;
vector<vector<int>> g;
int now, n, max1;

int print()
{
	if(now == 1)
	{
		cout << "! " << (*ans.begin()).first + 1 << ' ' << (*ans.begin()).second + 1 << endl;
		return max1;
	}
	set<int> all1;
	for(auto el : ans)
	{
		all1.insert(el.first);
		all1.insert(el.second);
	}
	cout << "? " << all1.size() << ' ';
	for(int el : all1)
	{
		cout << el + 1 << ' ';
	}
	cout << endl;
	int a;
	cin >> a;
	return a;
}

int dfs(int v, int need)
{
	int fir = need;
	used[v] = true;
	for(int u : g[v])
	{
		if(used[u] || need == 0 || ban.find({min(v, u), max(v, u)}) != ban.end())
		{
			continue;
		}
		--need;
		ans.insert({min(v, u), max(v, u)});
		need -= dfs(u, need);
	}
	return fir - need;
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
    cin >> n;
    used.assign(n, false);
    g.resize(n);
    now = n - 1;
    for(int i = 0; i < n - 1; i++)
    {
    	int v, u;
    	cin >> v >> u;
    	--u;
    	--v;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    cout << "? " << n << ' ';
    for(int i = 0; i < n; i++)
    {
    	cout << i + 1 << ' ';
    }
    cout << endl;
    cin >> max1;
    while(true)
    {
    	int need = (now - 1) / 2 + 1;
    	used.assign(n, false);
    	ans.clear();
    	for(int i = 0; i < n; i++)
    	{
    		if(!used[i] && need > 0)
    		{
    			need -= dfs(i, need);
    		}
    	}
    	bool was1 = (now == 1);
    	int here = print();
    	if(here == max1)
    	{
    		now = ans.size();
    		if(now == 1 && was1)
    		{
    			return 0;
    		}
    		for(int i = 0; i < n; i++)
    		{
    			for(int u : g[i])
    			{
    				if(ans.find({min(i, u), max(i, u)}) == ans.end())
    				{
    					ban.insert({min(i, u), max(i, u)});
    				}
    			}
    		}
    	}
    	else
    	{
    		now -= ans.size();
    		for(auto el : ans)
    		{
    			ban.insert(el);
    		}
    	}
    }
}