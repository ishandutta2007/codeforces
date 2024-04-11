//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
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
const int maxn = 2e5 + 100;
int n, m;
ll i100;
ll pmul[maxn], psum[maxn];
set<int> check{0};
ll f(ll l, ll r) {
	ll t = (mod + psum[r-1]-(l>1?psum[l-2]:0))%mod;
	t = (mod + t*bp(pmul[r-1], mod-2))%mod;
	return t-1;
}
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	i100 = bp(100, mod-2);
	cin >> n >> m;
	check.insert(n+1);
	ll i;
	ll cur = 1, sm = 1;
	psum[0] = pmul[0] = 1;
	for(int p = 1; p <= n; p++) {
		cin >> i;
		ll pi = (i*i100)%mod;
		pmul[p] = ((cur *= pi)%=mod);
		psum[p] = ((sm += cur)%=mod);
	}
	ll ans = f(0, n+1);
	while(m--) {
		cin >> i;
		auto it = check.lower_bound(i);
		if(*it == i) {
			auto l = it, r = it;
			--l, ++r;
			ans = (mod + ans - f(*l, *it))%mod;
			ans = (mod + ans - f(*it, *r))%mod;
			ans = (ans + f(*l, *r))%mod;
			check.erase(it);
		} else {
			auto l = it;
			--l;
			ans = (mod + ans - f(*l, *it))%mod;
			ans = (ans + f(*l, i))%mod;
			ans = (ans + f(i, *it))%mod;
			check.insert(i);
		}
		cout << ans << "\n";
	}
}