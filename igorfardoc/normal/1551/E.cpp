#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ostream& operator<<(ostream& out, pair<int, int> a)
{
	out << a.first << ' ' << a.second;
	return out;
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
    int t;
    cin >> t;
    while(t--)
    {
    	int n, k;
    	cin >> n >> k;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		--a[i];
    	}
    	vector<int> dp(n, 0);
    	for(int i = 0; i < n; i++)
    	{
    		if(a[i] > i)
    		{	
    			continue;
    		}
    		int l = 1;
    		int r = i + 2;
    		while(r - l > 1)
    		{
    			int mid = (l + r) / 2;
    			bool ok = false;
    			for(int j = 0; j < i; j++)
    			{	
    				if(a[j] >= a[i])
    				{
    					continue;
    				}
    				if(dp[j] >= mid - 1)
    				{
    					int posnow = i - (j - a[j]);
    					if(posnow < a[i])
    					{
    						continue;
    					}
    					ok = true;
    					break;
    				}
    			}
    			if(ok)
    			{
    				l = mid;
    			}
    			else
    			{
    				r = mid;
    			}
    		}
    		dp[i] = l;
    	}
    	int res = 1000000;
    	for(int i = 0; i < n; i++)
    	{
    		//cout << dp[i] << ' ';
    		if(dp[i] >= k)
    		{
    			res = min(res, i - a[i]);
    		}
    	}
    	//cout << '\n';
    	if(res == 1000000)
    	{
    		cout << "-1\n";
    	}
    	else
    	{
    		cout << res << '\n';
    	}
    }
}