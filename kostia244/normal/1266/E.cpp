#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,sse2,sse,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
ll n, a[301000], deg[301000], q;
map<pair<ll, ll>, ll> cur;
ll ans = 0;
void dec(ll i) {
	if(deg[i] <= a[i]) ans++;
	deg[i]--;
}
void add(ll i) {
	deg[i]++;
	if(deg[i] <= a[i]) ans--;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], ans += a[i];
	ll s, t, u;
	cin >> q;
	while(q--) {
		cin >> s >> t >> u;
		if(cur[{s, t}])
			dec(cur[{s, t}]);
		if(u)
			add(u);
		cur[{s, t}] = u;
		cout << ans << "\n";
	}
}