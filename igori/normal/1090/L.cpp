#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll t, n, a, b, k;
	cin >> t >> n >> a >> b >> k;
	ll x = n / 2 + n % 2;
	ll y = n / 2;
	if (n < k)
	{
		cout << 0;
		return 0;
	}
	if (n < 2 * k)
	{
	    if (b > a)
		b = min(b, x * a / (k - y));
		else
		if (a > b)
		a = min(a, y * b / (k - x));
	}
	ll ans = (a * x + b * y) / k;
	cout << min(t, ans);
}