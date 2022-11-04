#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    	while(true)
    	{
    		int sum = 0;
    		ll n1 = n;
    		while(n1 > 0)
    		{
    			sum += n1 % 10;
    			n1 /= 10;
    		}
    		if(_gcd(n, sum) != 1)
    		{
    			cout << n << '\n';
    			break;
    		}
    		++n;
    	}
    }
}