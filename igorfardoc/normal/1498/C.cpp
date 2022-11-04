#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;
vector<vector<vector<int> > > dp;
int n, k;

void rec(int i, int j, int l)
{
	//cout << i << ' ' << j << ' ' << l << endl;
	if(dp[i][j][l] != -1)
	{
		return;
	}
	dp[i][j][l] = 0;
	if(j == 1)
	{
		dp[i][j][l] = 1;
		return;
	}
	if(l == 0)
	{
		if(i != 0)
		{
			rec(i - 1, j - 1, 1);
			dp[i][j][l] = dp[i - 1][j - 1][1];
		}
		else
		{
			dp[i][j][l] = 1;
		}
		if(i != n - 1)
		{
			rec(i + 1, j, 0);
			dp[i][j][l] = (dp[i + 1][j][0] + dp[i][j][l]) % mod;
		}
		else
		{
			dp[i][j][l] = (dp[i][j][l] + 1) % mod;
		}
	}
	else
	{
		if(i != n - 1)
		{
			rec(i + 1, j - 1, 0);
			dp[i][j][l] = dp[i + 1][j - 1][0];
		}
		else
		{
			dp[i][j][l] = 1;
		}
		if(i != 0)
		{
			rec(i - 1, j, 1);
			dp[i][j][l] = (dp[i - 1][j][1] + dp[i][j][l]) % mod;
		}
		else
		{
			dp[i][j][l] = (dp[i][j][l] + 1) % mod;
		}
	}
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
    	cin >> n >> k;
    	dp.assign(n, vector<vector<int> >(k + 1, vector<int>(2, -1)));
    	rec(0, k, 0);
    	cout << dp[0][k][0] << '\n';
    }
}