#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1<<17, mod = 1e9 + 7;
int a, b, c, l;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b >> c >> l;
	ll ans = 0;
	for(ll x = 0; x <= l; x++) {
		ans += (x+2)*(x+1)/2;
		ll s = a+b+c+x;
		s = (s+1)/2;
		for(int t : {max(0ll, s-a), max(0ll, s-b), max(0ll, s-c)}) {
			ll u = x-t;
			//cout << u << endl;
			if(u >= 0) ans -= (u+2)*(u+1)/2;
		}
		//cout << a << " " << b << " "<< c << " " << x << " " << ans << endl;
	}
	cout << ans << endl;
}