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
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	sum += a[i];
    }
    if(sum % 2 == 1)
    {
    	cout << 0;
    	return 0;
    }
    vector<vector<bool>> dp(sum / 2 + 1, vector<bool>(n + 1));
    for(int i = 0; i <= sum / 2; i++)
    {
    	for(int j = 0; j <= n; j++)
    	{
    		if(i == 0)
    		{
    			dp[i][j] = true;
    			continue;
    		}
    		if(j == 0)
    		{
    			dp[i][j] = false;
    			continue;
    		}
    		dp[i][j] = dp[i][j - 1];
    		if(i - a[j - 1] >= 0)
    		{
    			dp[i][j] = dp[i][j] || dp[i - a[j - 1]][j - 1];
    		}
    	}
    }
    if(!dp[sum / 2][n])
    {
    	cout << 0;
    	return 0;
    }
    cout << "1\n";
    for(int i = 0; i < n; i++)
    {
    	if(a[i] % 2 == 1)
    	{
    		cout << i + 1;
    		return 0;
    	}
    }
    for(int i = 0; i < n; i++)
    {
    	if(!dp[sum / 2 - a[i] / 2][n])
    	{
    		cout << i + 1;
    		return 0;
    	}
    }
    return -1;
}