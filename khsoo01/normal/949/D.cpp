#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf = 1e18, N = 100005;

ll n, d, b, a[N], h[N], t[N], ans = inf;

pll solve (ll X) {
	for(ll i=1;i<=n;i++) {
		ll L = a[i];
		h[i] = 0; t[n-i+1] = 0;
		if(X > 0) {
			ll T = min(L, X);
			h[i] += T;
			L -= T; X -= T;
		}
		if(L > 0) t[n-i+1] += L;
	}
	for(ll i=2;i<=n;i++) {
		h[i] += h[i-1];
		t[i] += t[i-1];
	}
	ll A = 0, B = 0, RA = 0, RB = 0;
	for(ll i=1;i<=(n+1)/2;i++) {
		ll T = h[min(n,(d+1)*i)];
		if(T-A < b) RA++;
		else A += b;
	}
	for(ll i=1;i<=n/2;i++) {
		ll T = t[min(n,(d+1)*i)];
		if(T-B < b) RB++;
		else B += b;
	}
	return pll(RA, RB);
}

int main()
{
	scanf("%lld%lld%lld",&n,&d,&b);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll S = 0, E = n*b;
	while(S <= E) {
		ll M = (S+E)/2;
		ll A, B; tie(A, B) = solve(M);
		ans = min(ans, max(A, B));
		A > B ? S = M+1 : E = M-1;
	}
	printf("%lld\n",ans);
}