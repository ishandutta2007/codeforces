#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
const int gr = 440;



signed main()
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
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> x[i] >> y[i];
    }
    vector<int> bal(m);
    vector<vector<int>> mass(gr + 1, vector<int>(gr));
    int sum = 0;
    vector<pair<int, int>> zap(m);
    for(int i = 0; i < m; i++)
    {
    	cin >> zap[i].first >> zap[i].second;
    	--zap[i].second;
    }
    vector<int> next(m, m);
    vector<int> prev(m, -1);
    map<int, int> now;
    for(int i = m - 1; i >= 0; i--)
    {
    	if(now.find(zap[i].second) != now.end())
    	{
    		next[i] = now[zap[i].second];
    	}
    	now[zap[i].second] = i;
    }
    now.clear();
    for(int i = 0; i < m; i++)
    {
    	if(now.find(zap[i].second) != now.end())
    	{
    		prev[i] = now[zap[i].second];
    	}
    	now[zap[i].second] = i;
    }
    for(int i = 0; i < m; i++)
    {
    	sum += bal[i];
    	int here = sum;
    	for(int j = 2; j <= gr; ++j)
    	{
    		here += mass[j][i % j];
    	}
    	int k = zap[i].second;
    	int op = zap[i].first;
    	if(op == 1)
    	{
    		if(x[k] + y[k] <= gr)
    		{
    			for(int j = i + x[k]; j < i + x[k] + y[k]; j++)
    			{
    				++mass[x[k] + y[k]][j % (x[k] + y[k])];
    			}
    		}
    		else
    		{
    			int max1 = 0;
    			int max2 = 0;
    			for(ll j = (ll)i + x[k]; j < next[i]; j += (ll)x[k] + y[k])
    			{
    				++bal[j];
    				max1 = j;
    			}
    			for(ll j = i; j <= min(next[i], m - 1); j += (ll)x[k] + y[k])
    			{
    				max2 = j;
    				--bal[j];
    			}
    			if(max1 > max2 && next[i] < m)
    			{
    				--bal[next[i]];
    			}
    		}
    	}	
    	else
    	{
    		if(x[k] + y[k] <= gr)
    		{
    			for(int j = prev[i] + x[k]; j < prev[i] + x[k] + y[k]; j++)
    			{
    				--mass[x[k] + y[k]][j % (x[k] + y[k])];
    				if(i % (x[k] + y[k]) == j % (x[k] + y[k]))
    				{
    					--here;
    				}
    			}
    		}
    	}
    	cout << here << '\n';
    }
}