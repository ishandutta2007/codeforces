#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    }
    vector<vector<int> > dp(n, vector<int>(k + 1, 1));
    for(int k1 = 1; k1 <= k; k1++)
    {
    	for(int n1 = 0; n1 < n; n1++)
    	{
    		dp[n1][k1] = 0;
    		if(n1 > 0)
    		{
    			dp[n1][k1] = dp[n1 - 1][k1 - 1];
    		}
    		if(n1 < n - 1)
    		{
    			dp[n1][k1] = ((ll)dp[n1][k1] + dp[n1 + 1][k1 - 1]) % mod;
    		}
    	}
    }
    vector<int> am(n, 0);
    int res = 0;
    vector<int> mass(n, 1);
    for(int i = 0; i < k + 1; i++)
    {
    	for(int j = 0; j < n; j++)
    	{
    		am[j] = ((ll)am[j] + (ll)mass[j] * dp[j][k - i]) % mod;
    	}
    	vector<int> massnew(n, 0);
    	for(int j = 0; j < n; j++)
    	{
    		if(j > 0)
    		{
    			massnew[j] = mass[j - 1];
    		}
    		if(j < n - 1)
    		{
    			massnew[j] = ((ll)massnew[j] + mass[j + 1]) % mod;
    		}
    	}
    	mass = massnew;
    }
    for(int i = 0; i < n; i++)
    {
    	//cout << am[i] << ' ';
    	int adding = ((ll)a[i] * am[i]) % mod;
    	res = ((ll)adding + res) % mod;
    }
    //cout << endl;
    //cout << res << endl;
    /*for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j <= k; j++)
    	{
    		am[i] = ((ll)am[i] + dp[i][j]) % mod;
    		int adding = ((ll)am[i] * a[i]) % mod;
    		res = ((ll)res + adding) % mod;
    	}
    }*/
    for(int i = 0; i < q; i++)
    {
    	int pos, x;
    	cin >> pos >> x;
    	--pos;
    	int minus = ((ll)a[pos] * am[pos]) % mod;
    	res = ((ll)res - minus + mod) % mod;
    	a[pos] = x;
    	int adding = ((ll)a[pos] * am[pos]) % mod;
    	res = ((ll)res + adding) % mod;
    	cout << res << '\n';
    }
}