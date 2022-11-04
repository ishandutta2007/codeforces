#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int solve(vector<int> & a)
{
	int n = a.size();
	vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(2, vector<int>(2, 1000000000)));
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	dp[0][1][0] = 0;
	dp[0][1][1] = 0; // 0 -  
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			for(int k = 0; k < 2; k++)
			{
				if(i == 1)
				{
					dp[i][j][j] = 1 - j;
					continue;
				}
				if(k == 0 && j == 0)
				{
					if(i == 1)
					{
						dp[i][j][k] = 1;
					}
					else
					{
						dp[i][j][k] = dp[i - 2][1][1] + 2;
					}
				}
				else if(k == 1 && j == 0)
				{
					dp[i][j][k] = dp[i - 1][1][1] + 1;
				}
				else if(k == 0 && j == 1)
				{

				}
				else
				{
					dp[i][j][k] = dp[i - 1][1][1] + 1;
					if(a[i - 2] == a[i - 1] - 1 && (i <= 2 || a[i - 3] != a[i - 1] - 2))
					{
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][0][1]);
					}
					else if(a[i - 2] == a[i - 1] - 2)
					{
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][0][1]);
					}
					else if(i > 2 && a[i - 2] == a[i - 1] - 1 && a[i - 3] == a[i - 1] - 2)
					{
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][0][0]);
					}
					else
					{
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][1][1]);
					}
				}
			}
		}
	}
	return dp[n][1][1];
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
    	int n;
    	string s;
    	cin >> s;
    	n = s.size();
    	int ans = 0;
    	for(int i = 0; i < 26; i++)
    	{
    		vector<int> mass;
    		for(int j = 0; j < n; j++)
    		{
    			if(s[j] - 'a' == i)
    			{
    				mass.push_back(j);
    			}
    		}
    		ans += solve(mass);
    	}
    	cout << ans << '\n';
    }
}