#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 998244353;
ll n, m, k;
ll bp(ll a, ll p) {
	ll r = 1;
	while(p) {
		if(p&1) r = r*a%mod;
		a = a*a%mod, p>>=1;
	}
	return r;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m, k;
	cin >> n >> m >> k;
	ll f = 1;
	for(int i = 1; i <= n-1; i++) f = f*i%mod;
	for(int i = 1; i <= k; i++) f = f*bp(i, mod-2)%mod;
	for(int i = 1; i <= n-1-k; i++) f = f*bp(i, mod-2)%mod;
	f = f*m%mod;
	f = f*bp(m-1, k)%mod;
	cout << f << '\n';
}