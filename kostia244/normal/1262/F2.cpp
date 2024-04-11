//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pi, null_type, less<pi>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set; // order_of_key, find_by_order
ll n, k, h[2][200100], fact[200100], inv[200100], pref[200100], pw[200100];
ll bp(ll a, ll p) {
	ll r = 1;
	while (p) {
		if (p & 1)
			r = (r * a) % mod;
		p >>= 1;
		a = (a * a) % mod;
	}
	return r;
}
ll nck(ll n, ll k) {
	ll r = (fact[n] * inv[k]) % mod;
	return (r * inv[n - k]) % mod;
}
void setup() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i < 200100; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
		inv[i] = bp(fact[i], mod - 2);
	}
	pref[0] = nck(n, 0);
	for (int i = 1; i <= n; i++) {
		pref[i] = (pref[i - 1] + nck(n, i)) % mod;
	}
	pw[0] = 1;
	for(int i = 1; i < 200100; i++) pw[i] = (pw[i-1]*(k-2))%mod;
}
// 3 1
// 1 3
struct binsum {
	ll sum, n, a;
	binsum() {
		sum = 1;
		n = 1;
		a = 0;
	}
	void addn() {
		sum = (mod+mod+mod+2*sum-nck(n, a))%mod;
		n++;
	}
	ll get() {
		while(2*(a+1)<n) {
			sum += nck(n, a+1);
			sum%=mod;
			a++;
		}
		return sum;
	}
};
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	setup();
	if (k == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> h[0][i];
		h[1][(i + 1) % n] = h[0][i];
	}
	ll q = 0, mul = 1;
	for (int i = 0; i < n; i++) {
		if (h[0][i] == h[1][i])
			mul = (mul * k) % mod;
		else
			q++;
	}
	ll ans = 0;
	binsum x;
	for (int a = 1; a <= q; a++) {
		ll t = (pw[q-a]*nck(q, a))%mod;
		ans += (t*x.get())%mod;
		if(ans>=mod) ans-=mod;
//		cout << a << " " << x.n << " " << x.a << " " << x.sum<< "\n";
		x.addn();
	}
//	cout << ans << " " << mul << "\n";
	cout << ((ans * mul) % mod);
}