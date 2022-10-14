#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e5 + 55;
const int mod = 1e9 + 7;
ll fact[maxn], inv[maxn], pw[maxn];
ll bp(ll a, ll p) {
	ll r =1;
	while(p) {
		if(p&1) r = (r*a)%mod;
		a = (a*a)%mod;
		p>>=1;
	}
	return r;
}
void setup() {
	fact[0]=inv[0]=pw[0]=1;
	for(int i = 1; i < maxn; i++) {
		fact[i] = (fact[i-1]*1ll*i)%mod;
		inv[i] = bp(fact[i], mod-2);
		pw[i] = (10*pw[i-1])%mod;
	}
}
ll nck(ll n, ll k) {
	if(k>n) return 0;
	ll r = (fact[n]*inv[k])%mod;
	return (r*inv[n-k])%mod;
}
ll n, k;
string s;
vi p;
#define M(x) ((x)%mod)
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	setup();
	cin >> n >> k >> s;
	p.resize(n);
	p[0] = s[0]-'0';
	for(int i = 1; i < n; i++) {
		p[i] = s[i]-'0';
		p[i] = (p[i]+p[i-1])%mod;
	}
	ll ans = 0;
	for(int l = 0; n-l>k; l++) {
		ll t = M(pw[l]*nck(n-l-2, k-1));
		t = (t*p[n-l-2])%mod;
		ans =(ans+t)%mod;
	}
	for(ll i = 0; i < n; i++) {
		(ans += M(pw[n-i-1]*(s[i]-'0'))*nck(i, k))%=mod;
	}
	cout << ans;
}