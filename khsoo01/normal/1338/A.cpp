#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int N = 100005;

ll n, a[N];

void solve () {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	ll C = 0;
	for(int i=2;i<=n;i++) {
		if(a[i-1] > a[i]) {
			C = max(C, a[i-1] - a[i]);
			a[i] = a[i-1];
		}
	}
	ll ans = 0;
	while(C >= (1ll<<ans)) ans++;
	printf("%lld\n", ans);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int i=1;i<=tc;i++) {
		solve();
	}
}