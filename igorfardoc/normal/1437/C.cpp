#include<bits/stdc++.h>
using namespace std;
#define int long long




signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int q;
    cin >> q;
    while(q--)
    {
    	int n;
    	cin >> n;
    	vector<int> t(n);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> t[i];
    	}
    	sort(t.begin(), t.end());
    	vector<vector<int> > dp(1000, vector<int>(n + 1, 1000000000));
    	for(int i = 1; i < 1000; i++)
    	{
    		for(int j = 0; j < n + 1; j++)
    		{
    			if(j == 0)
    			{
    				dp[i][j] = 0;
    				continue;
    			}
    			if(i == 1 && j == 1)
    			{
    				dp[i][j] = abs(1 - t[0]);
    				continue;
    			}
    			if(i < j)
    			{
    				continue;
    			}
    			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(i - t[j - 1]));
    		}
    	}
    	cout << dp[999][n] << "\n";
    }
}