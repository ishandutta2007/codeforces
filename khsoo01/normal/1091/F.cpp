#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 100005;

ll n, a[N], gr, wr, ans;
char b[N];
bool w;

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	scanf("%s",b+1);
	for(ll i=1;i<=n;i++) {
		if(b[i] == 'W') {
			ans += a[i]*2;
			wr += a[i];
			w = true;
		}
		else if(b[i] == 'G') {
			ans += a[i]*3;
			gr += a[i];
			if(wr > 0) {
				ll L = min(wr, a[i]);
				ans -= L;
				wr -= L;
				gr += L;
			}
		}
		else {
			ll T = a[i];
			if(wr > 0) {
				ll L = min(wr, T);
				ans += 2*L;
				wr -= L;
				T -= L;
			}
			if(gr > 0) {
				ll L = min(gr, T);
				ans += 3*L;
				gr -= L;
				T -= L;
			}
			ans += (w ? 4 : 6) * T;
		}
	}
	printf("%lld\n",ans);
}