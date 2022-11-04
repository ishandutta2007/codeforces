#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int fact[3000002];
int rfact[3000002];

int bin_pow(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	if(b == 1)
	{
		return a;
	}
	int res = bin_pow(a, b / 2);
	res = ((ll)res * res) % mod;
	if(b & 1)
	{
		res = ((ll)res * a) % mod;
	}
	return res;
}

int obr(int a)
{	
	return bin_pow(a, mod - 2);
}

int c(int n, int k)
{
	if(n < 0 || k < 0 || n < k)
	{
		return 0;
	}
	int res = ((ll)fact[n] * rfact[k]) % mod;
	res = ((ll)res * rfact[n - k]) % mod;
	return res;
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
    int n, q;
    cin >> n >> q;
    fact[0] = 1;
    for(int i = 1; i <= 3000001; i++)
    {
    	fact[i] = ((ll)fact[i - 1] * i) % mod;
    	rfact[i] =  obr(fact[i]);
    }
    rfact[0] = rfact[1];
    vector<vector<int>> dp(3 * n + 1, vector<int>(3, 0));
    int val = obr(3);
    for(int i = 0; i <= 3 * n; i++)
    {
    	int sum = c(3 * n + 1, i + 1);
    	if(i == 0)
    	{
    		dp[0][0] = n + 1;
    		dp[0][1] = n;
    		dp[0][2] = n;
    		continue;
    	}
    	dp[i][1] = ((ll)sum - dp[i - 1][1] - dp[i - 1][2] - dp[i - 1][1] + 3ll * mod) % mod;
    	dp[i][1] = ((ll)dp[i][1] * val) % mod;
    	dp[i][2] = (dp[i][1] + dp[i - 1][1]) % mod;
    	dp[i][0] = (dp[i][2] + dp[i - 1][2]) % mod;
    }
    //cout << dp[1][0] << endl;
    for(int i = 0; i < q; i++)
    {
    	int x;
    	cin >> x;
    	cout << dp[x][0] << '\n';
    }
}