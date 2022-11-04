#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, p;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int ans = 0;
ll mask2 = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> m >> p;
    uniform_int_distribution<int> rng(0, n - 1);
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
    	ll now = 0;
    	for(int j = 0; j < m; j++)
    	{
    		char c;
    		cin >> c;
    		if(c == '1')
    		{
    			now |= (1ll << j);
    		}
    	}
    	a[i] = now;
    }
    for(int _ = 0; _ < 9; _++)
    {
    	int id1 = rng(rnd);
    	vector<int> indexes;
    	for(int j = 0; j < m; j++)
    	{
    		if((a[id1] >> j) & 1)
    		{
    			indexes.push_back(j);
    		}
    	}
    	
    	vector<int> b(n, 0);
    	vector<int> am(1 << (indexes.size()), 0);
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = 0; j < indexes.size(); j++)
    		{
    			if((a[i] >> indexes[j]) & 1)
    			{
    				b[i] |= (1 << j);
    			}
    		}
    		am[b[i]] += 1;
    	}
    	vector<int> am1(1 << (indexes.size()), 0);
    	for(int mask = 0; mask < (1 << (indexes.size())); ++mask)
    	{
    		if(am[mask] == 0)
    		{
    			continue;
    		}
    		for(int mask1 = mask; mask1 > 0; mask1 = (mask1 - 1) & mask)
    		{
    			am1[mask1] += am[mask];
    		}
    	}
    	for(int mask = 0; mask < (1 << (indexes.size())); ++mask)
    	{
    		if(am1[mask] * 2 < n)
    		{
    			continue;
    		}
    		if(__builtin_popcount(mask) > ans)
    		{
    			ans = __builtin_popcount(mask);
    			ll mask1 = 0;
    			for(int j = 0; j < indexes.size(); j++)
    			{
    				if((mask >> j) & 1)
    				{
    					mask1 |= (1ll << indexes[j]);
    				}
    			}
    			mask2 = mask1;
    		}
    	}
    }
    for(int i = 0; i < m; i++)
    {
    	cout << ((mask2 >> i) & 1);
    }
}