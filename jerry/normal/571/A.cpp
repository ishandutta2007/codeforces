#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll x[3], l;
	cin >> x[0] >> x[1] >> x[2] >> l;
	ll a = (l+1)*(l+2)*(l+3) / 6ll;
	for (int _ = 0;_ < 3;_++)
	{
		for (ll i = 0;i <= l;i++)
		{
			ll m = max(0ll, 1ll+min(x[0]+i-x[1]-x[2], l-i));
			a -= m*(m+1)/2ll;
		}
		swap(x[0], x[1]); swap(x[0], x[2]);
	}
	cout << a << "\n";
	return 0;
}