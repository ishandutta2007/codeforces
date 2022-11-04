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
    	ll a, b;
    	cin >> a >> b;
    	if(a == b)
    	{
    		cout << "0 0\n";
    		continue;
    	}
    	if(a > b)
    	{
    		swap(a, b);
    	}
    	cout << b - a << ' ';
    	ll t = b - a;
    	ll res;
    	ll k = (((b - 1) / t + 1) * t);
    	res = abs(b - k);
    	ll k1 = (b / t * t);
    	if(a - b + k1 >= 0)
    	{
    		res = min(res, abs(k1 - b));
    	}
    	cout << res << '\n';
    }
}