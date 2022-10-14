#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<20;
ll a, b, c, d;
ll count(ll a, ll b) {
	if(a < 0) return 0;
	return (a/b)+1;
}
ll f(ll x) {
	ll ans = (x/d + 1)*a;
	ans -= c*b*count(x-c-1, d);
	ll fi = max(x-c, 0ll);
	if(fi%d) fi -= fi%d, fi += d;
	//cout << fi << endl;
	fi = x - fi;
	ll AP = (fi*(fi/d + 1))/2;
	//cout << x << " " << fi << " " << d << " " << AP << endl;
	return ans - AP*b;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll t;
	cin >> t;
	while(t--) {
		cin >> a >> b >> c >> d;
		ll lo = 0, hi = 1<<20;
		array<ll, 2> ans = {0, 0};
		while(hi-lo > 5) {
			ll a = lo + (hi-lo)/3;
			ll b = hi - (hi-lo)/3;
			if(f(a*d) < f(b*d)) lo = a;
			else hi = b;
		}
		while(lo <= hi) ans = max(ans, {f(lo*d), lo}), lo++;
		if(ans[1] == 1ll<<20) ans[0] = -1;
		cout << ans[0] << '\n';
	}
	return 0;
}