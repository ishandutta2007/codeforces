#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

set<ll> occ, ans;
set<pair<ll, ll>> lfs, rts;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n, m, tot = 0;
	cin >> n >> m;
	for(ll i = 0; i < n; i++) {
		ll t; cin >> t;
		lfs.insert({1, t - 1});
		rts.insert({1, t + 1});
		occ.insert(t);
	}
	while(ans.size() < m) {
		while(occ.count(lfs.begin() -> second)) lfs.erase(*lfs.begin());
		while(occ.count(rts.begin() -> second)) rts.erase(*rts.begin());
		if(lfs.begin() -> first <= rts.begin() -> first) {
			pair<ll, ll> p = *lfs.begin();
			lfs.erase(p);
			tot += p.first;
			ans.insert(p.second);
			occ.insert(p.second);
			p.first++;
			p.second--;
			lfs.insert(p);
		} else {
			pair<ll, ll> p = *rts.begin();
			rts.erase(p);
			tot += p.first;
			ans.insert(p.second);
			occ.insert(p.second);
			p.first++;
			p.second++;
			rts.insert(p);
		}
	}
	cout << tot << endl;
	for(ll a : ans) cout << a << " ";
	cout << endl;
}