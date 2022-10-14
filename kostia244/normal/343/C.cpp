#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;
vector<ll> a, b;
ll n, m;
bool can(ll x) {
	int j = 0;
	for(int i = 0; i < n && j < m; i++) {
		ll t = -1;
		for(ll z = 1<<18; z>>=1;) {
			if(j+t+z >= m) continue;
			ll tt= abs(a[i]-b[j]) + abs(b[j]-b[j+t+z]);
			ll y = abs(a[i]-b[j+t+z]) + abs(b[j]-b[j+t+z]);
			if(min(tt,y) <= x) t += z;
		}
		j += t+1;
	}
	return j >= m;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	a.resize(n);for(auto &i : a) cin >> i;
	b.resize(m);for(auto &i : b) cin >> i;
	ll ans = -1;
	for(ll z = 1ll<<50; z>>=1;)
		ans += z*!can(ans+z);
	cout << ans + 1 << endl;
}