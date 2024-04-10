#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
const ll N = 200005;

ll n, t, cc, cp, c[N], p[N], ans, ai;
pair<ll,pair<ll,ll> > a[N];

int main()
{
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i].Y.X,&a[i].X);
		a[i].Y.Y = i; a[i].Y.X++;
	}
	sort(a+1, a+1+n);
	for(int i=1,j=1;i<=n;i++) {
		cc -= c[i]; cp -= p[i];
		for(;j<=n && cc < i;j++) {
			if(a[j].Y.X <= i) continue;
			if(a[j].X + cp > t) break;
			cc++; c[a[j].Y.X]++;
			cp += a[j].X; p[a[j].Y.X] += a[j].X;
		}
		if(ans < cc) {
			ans = cc; ai = i;
		}
	}
	printf("%lld\n",ans);
	printf("%lld\n",ans);
	for(int i=1;i<=n && ans;i++) {
		if(a[i].Y.X > ai) {
			printf("%lld ",a[i].Y.Y);
			ans--;
		}
	}
}