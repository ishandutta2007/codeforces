#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



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
    	bool ok = false;
    	for(ll a = 1; a * a * a < n; a++)
    	{
    		ll b = n - a * a * a;
    		ll b1 = cbrt(b);
    		if(b1 * b1 * b1 == b)
    		{
    			cout << "YES\n";
    			ok = true;
    			break;
    		}
    	}
    	if(!ok)
    	{
    		cout << "NO\n";
    	}
    }
}