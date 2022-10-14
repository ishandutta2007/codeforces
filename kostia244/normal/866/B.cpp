//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 5e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, s[maxn], a[maxn], b[maxn], sm = 0, def;
vpi vv;
ll eat(ll rr) {
	vpi v = vv;
	ll t = m*rr;
	ll ans = def;
	ll j = 0;
	while(j < v.size() && t) {
		ll x = min(v[j].second, t);
		v[j].second-=x;
		t -= x;
		ans += v[j].first * x;
		if(!v[j].second) j++;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s[i] >> a[i] >> b[i];
		vv.pb({-a[i]+b[i], s[i]});
		sm += s[i];
		def += s[i] * a[i];
	}
	ll e = (m - (sm%m))%m;
	vv.pb({0, e});
	sm += e;
	ll ans = 0;
	sort(rall(vv));
	for(ll i = 1ll<<38; i>>=1;)
		if(ans + i <= sm/m && eat(ans+i-1)<eat(ans+i)) ans += i;
	cout << eat(ans);
}