#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define int ll
using ll = long long;
using namespace std;
const int maxn = 1<<22, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll level(ll x) {
	return __lg(x);
}
ll sv[300], sp[300], sz[300];
ll getP(ll v) {
	if(v == 1) return 0;
	//cout << endl << v << " : ";
	ll t = level(v);
	//cout << t << " ; ";
	v -= sz[t];
	//cout << v << " : ";
	v = ((v + sp[t])%sz[t] + sz[t])%sz[t];
	//cout << v << endl;
	return sz[t-1] + (v/2);
}
ll rval(ll v) {
	//cout << endl << v << ":\n";
	ll t = level(v);
	v -= sz[t];
	//cout << endl << v << " " << sv[t] << endl;
	v = ((v + sv[t])%sz[t] + sz[t])%sz[t];
	return sz[t] + v;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	sz[0] = 1;
	for(int i = 1; i < 61; i++) sz[i] = sz[i-1]*2ll;
	ll q, t, x, k;
	cin >> q;
	while(q--) {
		cin >> t >> x;
		if(t == 3) {
			ll t = level(x);
			x -= sz[t];
			x = ((x-sv[t])%sz[t] + sz[t])%sz[t];
			x += sz[t];
			while(x) cout << rval(x) << " ", x = getP(x);
			cout << '\n';
		} else {
			cin >> k;k *= -1;
			x = level(x);
			if(t == 2) sp[x] -= k, sp[x] %= sz[x];
			else sv[x] += k, sv[x] %= sz[x];
		}
	}
}