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
    int n, mod;
    cin >> n >> mod;
    vector<unordered_map<int, int> > dp(n + 1);
    for(int i = 1; i <= n; i++)
    {
    	if(i == 1)
    	{
    		dp[i][0] = 1;
    		continue;
    	}
    	/*for(int a1 = 0; a1 < i; a1++)
    	{
    		for(int a2 = 0; a2 < i; a2++)
    		{
    			int delta = a1 - a2;
    			for(auto& p : dp[i - 1])
    			{
    				dp[i][p.first + delta] = (dp[i][p.first + delta] + p.second) % mod;
    			}
    		}
    	}*/
    	for(int delta = 1 - i; delta <= i - 1; ++delta)
    	{
    		for(auto& p : dp[i - 1])
			{
				dp[i][p.first + delta] = (dp[i][p.first + delta] + (ll)(p.second) * (i - abs(delta))) % mod;
			}
    	}
    }
    if(n == 1)
    {
    	cout << 0;
    	return 0;
    }
    /*for(auto& p: dp[4])
    {
    	cout << p.first << ' ' << p.second << endl;
    }*/
    int ans = 0;
    int now = 1;
    for(int i = 0; i < n - 1; i++)
    {
    	int here = 0;
    	/*
    	for(int a1 = 0; a1 < n - i; a1++)
    	{
    		for(int a2 = a1 + 1; a2 < n - i; a2++)
    		{
    			int delta = a1 - a2;
    			for(auto& p : dp[n - i - 1])
    			{
    				if(p.first + delta > 0)
    				{
    					here = (here + p.second) % mod;
    				}
    			}
    		}
    	}*/
    	for(int delta = i + 1 - n; delta <= -1; ++delta)
    	{
    		for(auto& p : dp[n - i - 1])
			{
				if(p.first + delta > 0)
				{
					here = (here + (ll)p.second * (n - i - abs(delta))) % mod;
				}
				//dp[i][p.first + delta] = (dp[i][p.first + delta] + (ll)(p.second) * (2 * i - 1 - delta)) % mod;
			}
    	}
    	ans = ((ll)here * now + ans) % mod;
    	now = ((ll)now * (n - i)) % mod;
    }
    cout << ans;
}