#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<19, mod = 1e9 + 7;
ll bp(ll a, ll p) {
	ll r = 1;
	while(p) {
		if(p&1) r = r * a %mod;
		a = a * a % mod, p >>= 1;
	}
	return r;
}
void solve() {
	int n, p;
	cin >> n >> p;
	map<int, int> x;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		x[t]++;
	}
	if(p == 1) {
		cout << (n&1) << '\n';
		return;
	}
	vector<pair<int, int>> t;
	for(auto i : x) t.pb(i);
	reverse(all(t));
	int fu = 0;
	ll ans = 0;
	for(int i = 0; i < t.size(); i++) {
		if(fu) {
			ans = (mod + ans - (t[i].second * 1ll * bp(p, t[i].first) % mod))%mod;
		} else {
			if(t[i].second%2 == 0) continue;
			ll need = 1;
			int j = i+1, pw = t[i].first;
			while(j < t.size() && need && need < (1<<20)) {
				while(pw > t[j].first && need < (1<<20)) {
					need *= p;
					pw--;
				}
				if(need > (1<<20)) break;
				ll uwu = min((ll)t[j].second, need);
				need -= uwu;
				j++;
			}
			if(need) {
				ans = bp(p, t[i].first);
				fu = 1;
			} else {
				ll need = 1;
				int j = i+1, pw = t[i].first;
				while(need) {
					while(pw > t[j].first) {
						need *= p;
						pw--;
					}
					ll uwu = min((ll)t[j].second, need);
					need -= uwu;
					t[j].second -= uwu;
					j++;
				}
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}