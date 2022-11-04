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
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    	}
    	vector<vector<int>> dp(n + 1, vector<int>(2));
    	for(int i = n; i >= 0; i--)
    	{
    		if(i == n)
    		{
    			dp[i][0] = 0;
    			dp[i][1] = 0;
    			continue;
    		}
    		if(i == n - 1)
    		{
    			dp[i][0] = 0;
    			dp[i][1] = 0;
    			if(a[i] == 1)
    			{
    				dp[i][1] = 1;
    			}
    			continue;
    		}
    		dp[i][0] = min(dp[i + 1][1], dp[i + 2][1]);
    		if(a[i + 1] == 1)
    		{
    			dp[i][1] = min(dp[i + 1][0], dp[i + 2][0] + 1);
    		}
    		else
    		{
    			dp[i][1] = min(dp[i + 1][0], dp[i + 2][0]);
    		}
    		if(a[i] == 1)
    		{
    			++dp[i][1];
    		}
    	}
    	cout << dp[0][1] << '\n';
    }
}