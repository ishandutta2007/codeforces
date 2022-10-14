#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	ll ans = 0;
	map<ll, ll> f;
	cin >> n;
	for(ll a, b; n--;) {
		cin >> a >> b;
		f[a] = max(f[a], b);
	}
	cin >> n;
	for(ll a, b; n--;) {
		cin >> a >> b;
		f[a] = max(f[a], b);
	}
	for(auto i : f) ans += i.second;
	cout << ans << '\n';
}