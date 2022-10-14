#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 60, mod = 1e9 + 7, i2 = (mod+1)/2;
ll n, m;
vector<string> r;
ll idx(string s) {
	ll x = 0;
	for(ll t = 1, i = s.size(); i--; t*=2) {
		if(s[i] == '1') x += t;
	}
	return x - (lower_bound(all(r), s)-r.begin());
}
void solve() {
	cin >> n >> m;
	ll k = (1ll<<m) - n;
	k = (k-1)/2;
	r = vector<string>(n);
	for(auto &i : r) cin >> i;
	sort(all(r));
	string ans(m, '0');
	for(int i = 0; i < m; i++) {
		ans[i] = '1';
		if(idx(ans) > k) ans[i] = '0';
	}
	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}