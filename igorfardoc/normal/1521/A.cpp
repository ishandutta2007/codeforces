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
    	int a, b;
    	cin >> a >> b;
    	if(b == 1)
    	{
    		cout << "NO\n";
    		continue;
    	}
    	cout << "YES\n";
    	ll fir = (ll)a * (b - 1);
    	ll sec = a;
    	ll third = (ll)a * b;
    	if(fir != sec)
    	{
    		cout << fir << ' ' << sec << ' ' << third << '\n';
    	}
    	else
    	{
    		int ch = 100000;
    		while(_gcd(third, ch) != 1)
    		{
    			++ch;
    		}
    		cout << fir * ch - third << ' ' << sec * ch + third << ' ' << third * ch << '\n';
    	}
    }
}