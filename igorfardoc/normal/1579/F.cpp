#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--)
    {
    	int n, d;
    	cin >> n >> d;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	vector<bool> used(n, false);
    	vector<vector<int>> components;
    	for(int i = 0; i < n; i++)
    	{
    		if(used[i])
    		{
    			continue;
    		}
    		components.push_back({});
    		int now = i;
    		while(!used[now])
    		{
    			used[now] = true;
    			components[components.size() - 1].push_back(a[now]);
    			now = (now + d) % n;
    		}
    	}
    	bool all1 = false;
    	int ans = 0;
    	for(const auto& comp : components)
    	{
    		int sz = comp.size();
    		bool ok = true;
    		for(int i = 0; i < sz; i++)
    		{
    			if(comp[i] == 0)
    			{
    				ok = false;
    				break;
    			}
    		}
    		if(ok)
    		{
    			all1 = true;
    			break;
    		}
    		int prev = -1;
    		int max1 = 0;
    		for(int i = 0; i < sz; i++)
    		{
    			if(comp[i] == 1)
    			{
    				if(prev == -1)
    				{
    					prev = i;
    					max1 = max(max1, 1);
    				}
    				else
    				{
    					max1 = max(max1, i - prev + 1);
    				}
    			}
    			else
    			{
    				prev = -1;
    			}
    		}
    		int fr = 0;
    		for(int i = 0; i < sz; i++)
    		{
    			if(comp[i] == 0)
    			{
    				break;
    			}
    			++fr;
    		}
    		for(int i = sz - 1; i >= 0; i--)
    		{
    			if(comp[i] == 0)
    			{
    				break;
    			}
    			++fr;
    		}
    		max1 = max(max1, fr);
    		ans = max(max1, ans);
    	}
    	if(all1)
    	{
    		cout << "-1\n";
    	}
    	else
    	{
    		cout << ans << '\n';
    	}
    }
}