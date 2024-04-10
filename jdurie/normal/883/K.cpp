#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define F(i, l, r) for(ll i = l; i < (r); i++)
#define G(x) ll x; cin >> x;

#define NN 200010
ll w[NN], l[NN], r[NN], s[NN], g[NN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin>>n;
	ll ans = 0;
	l[0] = 0;
	r[0] = INT_MAX;
	for (ll i=1; i<=n; ++i) {
		cin>>s[i]>>g[i];
		ll a = s[i], b = s[i]+g[i];
		ll c = l[i-1]-1;
		ll d = r[i-1]+1;
		l[i] = max(c, a), r[i] = min(b, d);
		if(r[i] < l[i]) { cout << "-1\n"; exit(0); }
	}
	w[n] = r[n];
	for (ll i=n-1; i>=1; --i) {
		w[i] = min(w[i+1]+1, r[i]);
	}
	for (ll i=1; i<=n; ++i) ans += w[i]-s[i];
	cout<<ans<<endl;
	for (ll i=1; i<=n; ++i) cout<<w[i]<<' ';
	cout<<endl;
}