#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int fact[100000], rfact[100000];
int dp[401][401];
int p[1000];

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
	res = ((ll)res * res) % m;
	if(b & 1)
	{
		res = ((ll)res * a) % m;
	}
	return res;
}

int obr(int a)
{
	return bin_pow(a, m - 2);
}

int c(int n, int k)
{
	if(k > n || n < 0 || k < 0)
	{
		return 0;
	}
	int res = ((ll)fact[n] * rfact[k]) % m;
	res = ((ll)res * rfact[n - k]) % m;
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
	cin >> n >> m;
    fact[0] = 1;
    p[0] = 1;
    for(int i = 1; i < 1000; i++)
    {
    	p[i] = (p[i - 1] * 2) % m;
    }
    for(int i = 1; i < 100000; i++)
    {
    	fact[i] = ((ll)fact[i - 1] * i) % m;
    	rfact[i] = obr(fact[i]);
    }
    rfact[0] = rfact[1];
    for(int i = 1; i <= n; i++)
    {
    	for(int j = 0; j < i; j++)
    	{
    		if(j == 0)
    		{
    			dp[i][j] = p[i - 1];
    			continue;
    		}
    		dp[i][j] = 0;
    		for(int k = i - 2; k > 0; k--)
    		{
    			int res = ((ll)p[i - k - 2] * dp[k][j - 1]) % m;
    			res = ((ll)res * c(i - j, i - k - 1)) % m;
    			dp[i][j] = (dp[i][j] + res) % m;
    		}
    	}
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
    	res = (res + dp[n][i]) % m;
    }
    cout << res;
}