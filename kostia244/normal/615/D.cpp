#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int D = 30, maxn = 2e5 + 556, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, cur = 1;
map<int, int> cnt;
ll bp(ll a, ll p, ll M) {
	ll r = 1;
	while (p > 0) {
		if (p & 1)
			r = (r * a) % M;
		a = (a * a) % M;
		p >>= 1;
	}
	return r;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int t, i = 0; i < n; i++) {
		cin >> t;
		cnt[t]++;
	}
	vector<pi> tt;
	vi x, y;
	for (auto i : cnt)
		tt.pb(i);
	x.resize(tt.size());
	y.resize(tt.size());
	x[0] = tt[0].second + 1;
	y[tt.size() - 1] = tt[tt.size() - 1].second + 1;
	for (int i = 1; i < tt.size(); i++) {
		x[i] = (x[i - 1] * (tt[i].second + 1)) % (mod - 1);
	}
	for (int i = tt.size() - 1; i--;) {
		y[i] = (y[i + 1] * (tt[i].second + 1)) % (mod - 1);
	}
	ll ans = 1;
	for (int i = 0; i < tt.size(); i++) {
		ll X = 1, t =tt[i].first, r = 1;
		if(i) X = (X*x[i-1])%(mod-1);
//		cout << x[i] << " " << y[i] << "\n";
		if(i+1<tt.size()) X = (X*y[i+1])%(mod-1);
//		cout << X << "\n";
		for (int j = 1; j <= tt[i].second; j++) {
			(r *= t) %= mod;
			t = (t * tt[i].first) % mod;
		}
//		cout << tt[i].first << " " << r << " " << X << '\n';
		ans = (ans * bp(r, X, mod)) % mod;
	}
	cout << ans;
}