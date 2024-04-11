#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int, int>;
const int maxn = 2e3 + 55, mod = 1e9 + 7;
ll fact[maxn], inv[maxn];
ll bp(ll a, ll p) {
	ll r = 1;
	while(p) {
		if(p&1) r = (r*a)%mod;
		a = (a*a)%mod;
		p>>=1;
	}
	return r;
}
ll setup() {
	inv[0] = fact[0] = 1;
	for(int i = 1; i < maxn; i++) {
		fact[i] = (fact[i-1]*i)%mod;
		inv[i] = bp(fact[i], mod-2);
	}
}
ll f[maxn];
ll calc(ll n, ll k) {
	if(n<k) return 0;
	if(n-k < k) k = n-k;
	ll r = 1;
	for(int i = n; i > n-k; i--) {
		r = (r*i)%mod;
	}
	r = (r*inv[k])%mod;
	return r;
}
ll n, k, a[maxn], res[maxn];
void setup2() {
	for(int i = 1; i < maxn; i++) f[i] = calc(i+k-1, k);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	setup();
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(k==0) {
		for(int i = 1; i <= n; i++) cout << a[i] << " ";
		return 0;
	}
	k--;
	setup2();
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			res[j] += f[j-i+1]*a[i]%mod;
			if(res[j]>=mod) res[j] -= mod;
		}
	}
	for(int i = 1; i <= n; i++) cout << res[i] << " ";
	cout << "\n";
}