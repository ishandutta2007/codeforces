#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int mod = 998244353;


int dp[501][500][501]; //pref, id, amount

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
    	char c;
    	cin >> c;
    	int now = -1;
    	if(c == '+')
    	{
    		cin >> now;
    	}
    	a[i] = now;
    }
    for(int pref = 0; pref <= n; ++pref)
    {
    	for(int id1 = 0; id1 < n; ++id1)
    	{
    		for(int am = 0; am < n; ++am)
    		{
    			if(id1 < pref)
    			{
    				continue;
    			}
    			if(am > pref)
    			{
    				continue;
    			}
    			if(pref == 0)
    			{
    				if(am == 0)
    				{
    					dp[pref][id1][am] = 1;
    				}
    				continue;
    			}
    			if(a[pref - 1] == -1)
    			{
    				dp[pref][id1][am] = (dp[pref - 1][id1][am] + dp[pref - 1][id1][am + 1]) % mod;
    				if(am == 0)
    				{
    					dp[pref][id1][am] = (dp[pref][id1][am] + dp[pref - 1][id1][am]) % mod;
    				}
    				continue;
    			}
    			else
    			{
    				dp[pref][id1][am] = dp[pref - 1][id1][am];
    				if(a[pref - 1] > a[id1])
    				{
    					dp[pref][id1][am] = (dp[pref][id1][am] + dp[pref - 1][id1][am]) % mod;
    				}
    				else
    				{
    					if(am > 0)
    					{
    						dp[pref][id1][am] = (dp[pref][id1][am] + dp[pref - 1][id1][am - 1]) % mod;
    					}
    				}
    			}
    		}
    	}
    }
    int ans = 0;
    vector<vector<int> > left(n, vector<int>(0));
    for(int i = 0; i < n; i++)
    {
    	if(a[i] == -1)
    	{
    		continue;
    	}
    	for(int j = 0; j <= i; j++)
    	{
    		left[i].push_back(dp[i][i][j]);
    	}
    }
    for(int pref = n; pref >= 0; --pref)
    {
    	for(int id1 = 0; id1 < n; ++id1)
    	{
    		for(int am = 0; am < n; ++am)
    		{
    			dp[pref][id1][am] = 0;
    			if(id1 > pref - 1)
    			{
    				continue;
    			}
    			if(pref - 1 < am)
    			{
    				continue;
    			}
    			if(pref == n)
    			{
    				dp[pref][id1][am] = 1;
    				continue;
    			}
    			if(a[pref] == -1)
    			{
    				dp[pref][id1][am] = dp[pref + 1][id1][am];
    				if(am != 0)
    				{
    					dp[pref][id1][am] = (dp[pref][id1][am] + dp[pref + 1][id1][am - 1]) % mod;
    				}
    				continue;
    			}
    			else
    			{
    				dp[pref][id1][am] = dp[pref + 1][id1][am];
    				if(a[pref] >= a[id1])
    				{
    					dp[pref][id1][am] = (dp[pref][id1][am] + dp[pref + 1][id1][am]) % mod;
    				}
    				else
    				{
						dp[pref][id1][am] = (dp[pref][id1][am] + dp[pref + 1][id1][am + 1]) % mod;
    				}
    			}
    		}
    	}
    }
    for(int i = 0; i < n; i++)
    {
    	if(a[i] == -1)
    	{
    		continue;
    	}
    	for(int j = 0; j <= i; j++)
    	{
    		int left1 = left[i][j];
			int right1 = 1;
			if(i != n - 1)
			{
				right1 = dp[i + 1][i][j];
			}
			int here = ((ll)left1 * right1) % mod;
			here = ((ll)here * a[i]) % mod;
			ans = (here + ans) % mod;
    	}
    }
    cout << ans;
}