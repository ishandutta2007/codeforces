#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e5 + 5, mod = 1e9 + 7;
struct dsu {
	vi r, p;
	void init(int n) {
		r.resize(n);
		p.resize(n);
		for(int i = 0; i < n; i++) p[i] = i, r[i] = 1;
	}
	int par(int i) {
		if(i == p[i]) return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i==j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[j];
	} 
};
int n, k;
dsu d;
ll pw(ll x, ll p, ll M) {
	ll r = 1;
	while(p--) r = (r*1ll*x)%M;
	return r;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	if(k==0) return cout << pw(n, n-1, mod), 0;
	d.init(n);
	for(int i = 0; i < n; i++) {
		d.unite(i, (i*1ll*k)%n);
	}
	ll ans = 1;
	for(int i = 0; i < n; i++) {
		if(d.par(i)!=i) continue;
		ll t = pw(k, d.r[i], n);
		if(t==1) {
			ans = (ans*1ll*n)%mod;
		}	
	}
	cout << ans << '\n';
}