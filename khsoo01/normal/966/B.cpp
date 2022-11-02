#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll n, x, y, cx, cy;

pll a[300005];

int main()
{
	scanf("%lld%lld%lld",&n,&x,&y);
	for(ll i=1;i<=n;i++) {
		scanf("%lld",&a[i].X);
		a[i].Y = i;
	}
	sort(a+1, a+1+n);
	for(ll i=n;i>=1;i--) {
		if((x+a[i].X-1)/a[i].X <= n-i+1) {
			cx = max(cx, i);
			if(i+(x+a[i].X-1)/a[i].X <= cy) {
				puts("Yes");
				ll A = (x+a[i].X-1)/a[i].X, B = (y+a[cy].X-1)/a[cy].X;
				printf("%lld %lld\n",A,B);
				for(ll j=0;j<A;j++) printf("%lld ",a[i+j].Y);
				puts("");
				for(ll j=0;j<B;j++) printf("%lld ",a[cy+j].Y);
				puts("");
				return 0;
			}
		}
		if((y+a[i].X-1)/a[i].X <= n-i+1) {
			cy = max(cy, i);
			if(i+(y+a[i].X-1)/a[i].X <= cx) {
				puts("Yes");
				ll A = (x+a[cx].X-1)/a[cx].X, B = (y+a[i].X-1)/a[i].X;
				printf("%lld %lld\n",A,B);
				for(ll j=0;j<A;j++) printf("%lld ",a[cx+j].Y);
				puts("");
				for(ll j=0;j<B;j++) printf("%lld ",a[i+j].Y);
				puts("");
				return 0;
			}
		}
	}
	puts("No");
}