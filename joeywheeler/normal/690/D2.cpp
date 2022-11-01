#include <bits/stdc++.h>
typedef long long ll;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define MOD 1000003LL
#define N 1234567
using namespace std;

ll n, c, fct[N] = {1}, ifct[N], ans;
ll pw(ll a, ll b) {
	if (b==0) return 1;
	ll ans = pw(a, b/2);
	ans = (ans*ans)%MOD;
	if (b%2) ans = (ans*a)%MOD;
	return ans;
}
ll inv(ll a) {
	return pw(a, MOD-2);
}
int main() {
	scanf("%lld %lld", &n, &c);
	fo(i,1,N) fct[i] = (i*fct[i-1])%MOD;
	fo(i,0,N) ifct[i] = inv(fct[i]);
	fo(i,1,n+1) ans = (ans + fct[i + c - 1] * (ifct[i] * ifct[c-1])%MOD)%MOD;
	printf("%lld\n", ans);

	return 0;
}