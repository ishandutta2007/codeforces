#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
map<ll, ll> p, r, t;
ll par(ll i) {
	if(!p.count(i)) return i;
	return p[i] = par(p[i]);
}
void unite(ll i, ll j) {
	i = par(i), j = par(j);
	if(i==j) {
		t[i] = true;
		return;
	}
	if(r[i] < r[j]) swap(i, j);
	p[j] = i;
	r[i] += 1+r[j];
	t[i] |= t[j];
}
const int maxn = 1e5 + 55, mod = 1e9 + 7;
int n, pw[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("in.txt", "r", stdin);
	pw[0] = 1;
	for(int i = 1; i < maxn; i++) pw[i] = (pw[i-1]<<1)%mod;
	cin >> n;
	set<ll> check;
	for(ll x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		unite(1000000000ll + x, 3000000000ll + y);
		check.insert(1000000000ll + x);
		check.insert(3000000000ll + y);
	}
	ll ans = 1;
	for(auto i : check) {
		if(p.count(i)) continue;
		if(t[i]) ans = (ans * 1ll * pw[r[i]+1])%mod;
		else ans = (ans * 1ll * (pw[r[i]+1]-1))%mod;
	}
	cout << ans << "\n";
}