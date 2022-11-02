#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const ll mod = 1e9+7;

int n;
ll a[500005], c[61];

void solve ()
{
	scanf("%d",&n);
	for(int i=0;i<60;i++) c[i] = 0;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		for(int j=0;j<60;j++) {
			if((1ll<<j) & a[i]) c[j]++;
		}
	}
	ll ans = 0;
	for(int i=1;i<=n;i++) {
		ll A = 0, B = 0, X, Y;
		for(int j=0;j<60;j++) {
			X = ((1ll<<j) & a[i]);
			Y = (1ll<<j) % mod;
			A += Y * (X ? c[j] : 0);
			B += Y * (X ? n : c[j]);
		}
		ans = (ans + (A % mod) * (B % mod)) % mod;
	}
	printf("%lld\n", ans);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) solve();
}