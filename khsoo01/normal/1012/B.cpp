#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;

const ll N = 200005;

ll n, m, k, par[N], ans;
bool x[N];

pair<ll,ll> a[N];

ll Find (ll X) {
	if(par[X] == X) return X;
	return par[X] = Find(par[X]);
}

int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		par[i] = i;
	}
	ans += n + m - 1;
	for(int i=1;i<=k;i++) {
		scanf("%lld%lld",&a[i].X,&a[i].Y);
		if(!x[a[i].X]) {
			x[a[i].X] = true;
			ans--;
		}
	}
	sort(a+1, a+1+k);
	for(int i=2;i<=k;i++) {
		if(a[i].X == a[i-1].X) {
			ll A = Find(a[i].Y), B = Find(a[i-1].Y);
			par[A] = B;
		}
	}
	for(int i=1;i<=m;i++) {
		if(Find(i) != i) ans--;
	}
	printf("%lld\n",ans);
}