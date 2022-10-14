//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,avx,sse,sse2,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
const int maxn = 2e6 + 55, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll bp(ll a, ll p) {
	ll r = 1;
	while(p) {
		if(p&1) r = (r*a)%mod;
		a = (a*a)%mod;
		p>>=1;
	}
	return r;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	vvi v(1001000);
	cin >> n;
	vi cnt(1e6+1), p(1e6 + 1);
	ll ii = bp(n, mod-2);
	for(int i = 0; i < n; i++) {
		cin >> k;
		v[i].resize(k);
		ll inv = (ii*bp(k, mod-2))%mod;
		for(auto &j : v[i]) {
			cin >> j;
			cnt[j]++;
			p[j] += inv;
		}
	}ll ans = 0;
	for(int i = 0; i < n; i++) {
		ll t = 0;
		for(auto &j : v[i]) {
			t = (t+p[j])%mod;
		}
		ans = (ans + t*ii)%mod;
	}
	cout << ans;
}