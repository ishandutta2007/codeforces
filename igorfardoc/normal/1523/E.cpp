#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int fact[1000001];

int bin_pow(int a, int b)
{
	if(b == 0)
	{
		return 1;
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
	if(k > n)
	{
		return 0;
	}
	int up = fact[n];
	int down = ((ll)fact[k] * fact[n - k]) % mod;
	return ((ll)up * obr(down)) % mod;
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
    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++)
    {
    	fact[i] = ((ll)fact[i - 1] * i) % mod;
    }
    cin >> t;
    while(t--)
    {
    	int n, k;
    	cin >> n >> k;
    	int ans = 1;
    	vector<int> values;
    	for(int i = 1; i <= (n - 1) / k + 1; i++)
    	{
    		int res = c(n - (k - 1) * (i - 1), i);
    		int up = fact[i];
    		int down = ((ll)fact[n] * obr(fact[n - i])) % mod;
    		int res1 = ((ll)up * obr(down)) % mod;
    		res = ((ll)res * res1) % mod;
    		values.push_back(res);
    		//res = ((ll)res * i) % mod;
    		//ans = ((ll)ans + res) % mod;
    	}
    	for(int i = 0; i < (int)values.size() - 1; i++)
    	{
    		int res = ((ll)values[i] - values[i + 1] + mod) % mod;
    		res = ((ll)res * (i + 1)) % mod;
    		ans = ((ll)ans + res) % mod;
    	}
    	int res1 = ((ll)values[values.size() - 1] * (ll)values.size()) % mod;
    	ans = ((ll)ans + res1) % mod;
    	cout << ans << '\n';
    }
}