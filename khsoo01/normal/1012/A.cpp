#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a[200005];

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=2*n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1, a+1+2*n);
	ll ans = (a[2*n]-a[n+1])*(a[n]-a[1]);
	for(ll i=2;i<=n;i++) {
		ans = min(ans, (a[i+n-1]-a[i])*(a[2*n]-a[1]));
	}
	printf("%lld\n",ans);
}