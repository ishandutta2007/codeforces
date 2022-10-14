#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

#define tcs ll T; cin >> T; while(T--)
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll NN = 200010;

pair<ll, ll> pb[NN];
vector<ll> anss;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    tcs {
		ll n, T, a, b, as = 0, bs = 0;
		cin >> n >> T >> a >> b;
		for(ll i = 0; i < n; i++) {
			ll x; cin >> x;
			pb[i].second = x ? b : a;
			if(x) bs++; else as++;
		}
		for(ll i = 0; i < n; i++) cin >> pb[i].first;
		sort(pb, pb + n);
		ll tot = 0, ans = 0;
		if(a * as < pb[0].first)
			ans = max(ans, as + min(bs, (pb[0].first - 1 - a * as) / b));
		else ans = max(ans, (pb[0].first - 1) / a);
		for(ll i = 0; i < n; i++) {
			tot += pb[i].second;
			if(pb[i].second == b) bs--; else as--;
			while(i + 1 < n && pb[i].first == pb[i + 1].first) {
				tot += pb[++i].second;
				if(pb[i].second == b) bs--; else as--;
			}
			ll time = i == n - 1 ? T : pb[i + 1].first - 1;
			if(tot <= time) {
				if(tot + a * as <= time)
					ans = max(ans, n - bs + min(bs, (time - tot - a * as) / b));
				else ans = max(ans, n - bs - as + min(as, (time - tot) / a));
			}
		}
		anss.push_back(ans);
	}
	for(ll ans : anss) cout << ans << endl;
}