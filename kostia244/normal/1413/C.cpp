#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<18, mod = 998244353, inv2 = (mod+1)/2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	vector<ll> a(6);
	for(auto &i : a) cin >> i;
	ll n;cin >> n;
	vector<array<ll, 2>> b;
	for(ll x, i = 0; i < n; i++) {
		cin >> x;
		for(auto &p : a) b.push_back({x-p, i});
	}
	sort(all(b));
	multiset<ll> lst;
	map<ll, ll> L;
	ll ans = 1ll<<50;
	for(auto [pos, tp] : b) {
		if(L.count(tp)) lst.erase(lst.find(L[tp]));
		lst.insert(L[tp] = pos);
		if(lst.size() == n) ans = min(ans, pos-*lst.begin());
	}
	cout << ans << '\n';
}