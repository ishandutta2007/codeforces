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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    vector<vector<ll> > dp(n + 1, vector<ll>(n + 1, -1));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
    	for(int j = 0; j <= n; j++)
    	{
    		dp[i][j] = dp[i - 1][j];
    		if(j == 0)
    		{
    			continue;
    		}
    		if(dp[i - 1][j - 1] == -1)
    		{
    			break;
    		}
    		if(dp[i - 1][j - 1] + a[i - 1] < 0)
    		{
    			continue;
    		}
    		dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i - 1]);
    	}
    }
    for(int i = n; i >= 0; i--)
    {
    	if(dp[n][i] != -1)
    	{
    		cout << i;
    		return 0;
    	}
    }
}