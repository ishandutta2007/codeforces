#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20;

int main() {
  	cin.tie(0)->sync_with_stdio(0);
  	ll t, p, q;
  	cin >> t;
  	while(t--) {
		cin >> p >> q;
		ll tq = q, ans = 0;
		for(ll d = 2; d*d <= tq; d++) if(tq%d == 0) {
			ll f = 1;
			while(tq%d == 0) tq/=d, f *= d;
			ll tp = p;
			while(tp%f == 0) tp /= d;
			ans = max(ans, tp);
		}
		if(tq > 1) {
			ll d = tq, f = 1;
			while(tq%d == 0) tq/=d, f *= d;
			ll tp = p;
			while(tp%f == 0) tp /= d;
			ans = max(ans, tp);
		}
		cout << ans << '\n';
	}
}