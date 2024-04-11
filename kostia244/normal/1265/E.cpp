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
int n;
ll i100;
int main() { //DINIC ORZ, FFT ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	i100 = bp(100, mod-2);
	cin >> n;
	ll i;
	ll cur = 1, sm = 1;
	while(n--) {
		cin >> i;
		ll pi = (i*i100)%mod;
		(cur *= pi)%=mod;
		(sm += cur)%=mod;
	}
	cout << (mod + sm*bp(cur, mod-2) - 1)%mod;
}