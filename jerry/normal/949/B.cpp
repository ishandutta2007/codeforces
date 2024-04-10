#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll qu1(ll n, ll x);
ll qu2(ll n, ll x);

ll qu1(ll n, ll x)
{
	if (x&1) return (x/2)+1;
	if (n&1) return qu2(n/2, x/2)+n/2+1;
	return qu1(n/2, x/2)+n/2;
}

ll qu2(ll n, ll x)
{
	if (!(x&1)) return x/2;
	if (n&1) return qu1(n/2+1, x/2+1)+n/2;
	return qu2(n/2, x/2+1)+n/2;
}

int main()
{
	ll n; int q; scanf("%lld%d", &n, &q);
	while (q--)
	{
		ll x; scanf("%lld", &x);
		printf("%lld\n", qu1(n, x));
	}
	return 0;
}