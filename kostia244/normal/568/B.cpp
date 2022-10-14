#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1000000007ll;
ll fact[100100], inv[100100];
ll bp(ll a, ll p) {
	ll res = 1;
	while(p) {
		if(p&1) res = (res*a)%mod;
		a = (a*a)%mod;
		p>>=1;
	}
	return res;
}
void setup() {
	fact[0] = inv[0] = 1;
	for(int i = 1; i < 100100; i++) {
		fact[i] = (fact[i-1]*1ll*i)%mod;
		inv[i] = bp(fact[i], mod-2);
	}
}
ll nck(ll n, ll k) {
	if(k>n)return 0;
	ll res = (fact[n]*inv[n-k])%mod;
	return (res*inv[k])%mod;
}

int main() {
	setup();
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);//a(n+1) = 1 + Sum_{j=1..n} (1+binomial(n, j))*a(j)
	ll dp[5000];
	dp[1] = 1;
	ll n;
	cin >> n;
	for(int i = 2; i <= n; i++) {
		dp[i] = 1;
		for(int j = 1; j < i; j++) {
			dp[i]+=(dp[j]*1ll*(1ll+nck(i-1, j)))%mod;
			dp[i]%=mod;
		}
	}
	cout << dp[n];
}