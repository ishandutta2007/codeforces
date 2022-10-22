#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
void exgcd(ll a,ll b,ll *aa,ll*bb) {
	ll x, y;
	if (a == 0) { *aa = 0, *bb = 1; return; }
	exgcd(b%a, a, &x, &y);
	*bb = x;
	*aa = y - x * (b / a);
}
ll inv(ll a, ll m) {
	ll x, y;
	exgcd(a, m, &x, &y);
	return x>0?x:(x+m);
}
ll gcd(ll a, ll b) {
	while (b)a %= b, a ^= b ^= a ^= b;
	return a;
}
ll crt(ll a, ll m1, ll b, ll m2) {
	ll g = gcd(m1, m2);
	if (a%g != b % g)return 0x3f3f3f3f3f3f3f3f;
	if(m1%(g*g)==0)m2 /= g,	b %= m2;
	else m1 /= g, a %= m1;
	return (a*m2*inv(m2, m1) + b * m1*inv(m1, m2)) % (m1*m2);
}
int main() {
	int k,i;
	ll n, m;
	scanf("%lld%lld%d",&n,&m, &k);
	for (i = 0; i < k; i++) {
		ll x, y, ans = 0x3f3f3f3f3f3f3f3f;
		scanf("%lld%lld", &x, &y);
		ans = min(ans, crt(x, 2 * n, y, 2 * m));
		ans = min(ans, crt(2 * n - x, 2 * n, y, 2 * m));
		ans = min(ans, crt(2 * n - x, 2 * n, 2 * m - y, 2 * m));
		ans = min(ans, crt(x, 2 * n, 2 * m - y, 2 * m));
		if (ans != 0x3f3f3f3f3f3f3f3f)printf("%lld\n", ans);
		else printf("-1\n");
	}
}