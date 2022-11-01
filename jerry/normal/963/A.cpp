#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000009;

ll ex(ll x, ll y)
{
	if (y == 0) return 1;
	ll r = ex(x, y>>1);
	r *= r; r %= MOD;
	if (y&1) { r *= x; r %= MOD; }
	return r;
}

char buf[100005];
ll n, a, b, ans;
int k;

int main()
{
	scanf("%lld%lld%lld%d%s", &n, &a, &b, &k, buf);
	for (int i = 0;i < k;i++)
	{
		ll here = MOD-1;
		if (buf[i] == '+') here = 1;
		here *= ex(a, n-i); here %= MOD;
		here *= ex(b, i); here %= MOD;
		ans += here; ans %= MOD;
	}
	ll rat = ex(a, MOD-1-k)*ex(b, k); rat %= MOD;
	if (rat == 1)
	{
		ll fact = (n+1)/k;
		ans = ans*fact; ans %= MOD;
	} else
	{
		rat = (1-ex(rat, (n+1)/k)+MOD)*ex(1-rat+MOD, MOD-2); rat %= MOD;
		ans = (ans*rat)%MOD;
	}
	printf("%lld\n", ans);
	return 0;
}