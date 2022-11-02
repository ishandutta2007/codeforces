#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 300005;

ll n, a[N], b[N], lsb[N], s, ans;
bool odd[N];

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i],&b[i]);
		s += a[i];
		odd[i] = (__builtin_popcountll(b[i]) % 2 == 1);
		lsb[i] = (b[i] & (-b[i]));
	}
	if(s < 0) {
		for(ll i=1;i<=n;i++) {
			a[i] *= -1;
		}
	}
	ll S = 0;
	for(ll k=(1ll<<61);k>=1;k/=2) {
		S += k;
		ll T = 0;
		for(ll i=1;i<=n;i++) {
			if(k == 1) {
				if(odd[i]) T += a[i];
			}
			else {
				if(!odd[i] && lsb[i] * 2 == k) T += a[i];
			}
		}
		if(T > 0) {
			ans ^= S;
			for(ll i=1;i<=n;i++) {
				if(__builtin_popcountll(S&b[i]) % 2 == 1) a[i] *= -1;
			}
		}
	}
	printf("%lld\n", ans);
}