//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 3e5 + 10, mod = 1e9 + 7;
ll fact[maxn], inv[maxn], pw[maxn];
void setup() {
	fact[0] = inv[0] = pw[0] = 1;
	for(int i = 1; i < maxn; i++) {
		fact[i] = (fact[i-1]*i)%mod;
		pw[i] = (pw[i-1]*2)%mod;
		if(i==1)
			inv[i] = 1;
		else
			inv[i] = (mod - (mod/i)*inv[mod%i]%mod)%mod;
	}
	for(int i = 2; i < maxn; i++) inv[i] = (inv[i]*inv[i-1])%mod;
}
ll nck(ll n, ll k) {
	if(k>n) return 0;
	ll r = (fact[n]*inv[k])%mod;
	return (r*inv[n-k])%mod;
}
ll solve(ll n, ll m) {
	ll l = n+m;
	ll ans = 0;
	for(int i = 2; i < l; i+=2) {
		ans = (ans + nck(l-i, m-1))%mod;
	}
	if(m==1&&!(n&1)) if(++ans==mod) ans=0;
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	setup();
	ll n, m, k;
	cin >> n >> m >> k;
	if(m==0) {
		++n;
		cout << ((n&1)==k?1:0);
		return 0;
	}
	if(n==0) {
		if(m==1) return cout << (k==1), 0;
		else return cout << (k!=1), 0;
		return 0;
	}
	if(k==1) {
		cout << solve(n, m);
	} else {
		cout << (mod + nck(n+m, m) - solve(n, m))%mod;
	}
	return 0;
}