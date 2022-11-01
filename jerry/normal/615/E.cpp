#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

ll foo(ll x)
{
	return 3*x*x-3*x+1;
}

void foo(ll& x, ll& y, ll& extra, const ll dx, const ll dy, const ll len)
{
	if (extra <= 0) return;
	ll todo = min(extra, len);
	x += dx*todo;
	y += dy*todo;
	extra -= todo;
}

ll get_layer()
{
	ll lo = 1;
	ll hi = 600000000;
	while (lo+1 < hi)
	{
		ll mid = (lo+hi) >> 1;
		ll val = foo(mid);
		if (n < val) hi = mid;
		else lo = mid;
	}
	return lo;
}

int main()
{
	cin >> n;
	if (n == 0)
	{
		printf("0 0\n");
		return 0;
	}
	ll layer = get_layer();
	ll x = 2*layer-1, y = 2;
	ll extra = n - foo(layer);
	// fix things
	foo(x, y, extra, -1, 2, layer-1);
	foo(x, y, extra, -2, 0, layer);
	foo(x, y, extra, -1, -2, layer);
	foo(x, y, extra, 1, -2, layer);
	foo(x, y, extra, 2, 0, layer);
	foo(x, y, extra, 1, 2, layer);
	cout << x << " " << y << endl;
	return 0;
}