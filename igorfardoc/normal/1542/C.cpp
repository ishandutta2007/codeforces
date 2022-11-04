#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int mod = 1000000007;

ll _gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return _gcd(b, a % b);
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
    	ll n;
    	cin >> n;
    	int ans = n % mod;
    	ll now = 1;
    	for(int i = 1;; i++)
    	{
    		ll now1 = now * i;
    		now = now1 / _gcd(now, i);
    		if(now > n)
    		{
    			break;
    		}
    		ans = ((ll)ans + n / now) % mod;
    	}
    	cout << ans << '\n';
    }
}