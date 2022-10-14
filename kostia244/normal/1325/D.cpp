#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int maxn = 1e5 + 55;
ll x, s, cnt[66];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> x >> s;
	if(x>s||(x&1)!=(s&1)) return cout << -1, 0;
	ll D = (s-x)/2;
	for(ll i = 0; i < 60; i++) {
		if((D>>i)&1) cnt[i]+=2;
		if((x>>i)&1) cnt[i]++;
	}
	vector<ll> ans;
	while(true) {
		ll t = 0;
		for(ll i = 0; i < 60; i++) if(cnt[i]) cnt[i]--, t|=1ll<<i;
		if(!t) break;
		ans.pb(t);
	}
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i << " ";
}