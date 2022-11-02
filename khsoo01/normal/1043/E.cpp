#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const ll N = 300005;

ll n, m, a[N], b[N], ans[N];
pll v[N];

int main()
{
	scanf("%lld%lld",&n,&m);
	ll T = 0;
	for(ll i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i],&b[i]);
		T += a[i];
		v[i] = {b[i] - a[i], i};
	}
	sort(v+1, v+1+n);
	for(ll i=1;i<=n;i++) {
		ll I = v[i].Y;
		T -= a[I];
		ans[I] = T + (i-1) * a[I] + (n-i) * b[I];
		T += b[I];
	}
	for(ll i=1;i<=m;i++) {
		ll A, B;
		scanf("%lld%lld",&A,&B);
		T = min(a[A] + b[B], a[B] + b[A]);
		ans[A] -= T;
		ans[B] -= T;
	}
	for(ll i=1;i<=n;i++) {
		printf("%lld ",ans[i]);
	}
}