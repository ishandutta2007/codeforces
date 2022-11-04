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
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	vector<ll> a(n);
    	vector<int> am(60, 0);
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		for(int j = 0; j < 60; j++)
    		{
    			if((a[i] >> j) & 1)
    			{
    				++am[j];
    			}
    		}
    	}
    	ll ans = 0;
    	for(int i = 0; i < n; i++)
    	{
    		ll proz1 = 0;
    		for(int j = 0; j < 60; j++)
    		{
    			if(((a[i] >> j) & 1) == 0)
				{
					proz1 = (proz1 + ((1ll << j) % mod) * am[j]) % mod;
				}
				else
				{
					proz1 = (proz1 + ((1ll << j) % mod) * n) % mod;
				}
    		}
    		for(int j = 0; j < 60; j++)
    		{
				if(((a[i] >> j) & 1) == 0)
				{
					continue;
				}
				ll proz = am[j];
				proz = (proz * ((1ll << j) % mod)) % mod;
				proz = (proz * proz1) % mod;
				ans = (proz + ans) % mod;
    		}
    	}
    	cout << ans << '\n';
    }
}