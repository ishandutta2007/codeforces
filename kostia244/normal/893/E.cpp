#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace  std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e6 + 66, sigma = 26, mod = 1e9 + 7;
int lp[maxn], fact[maxn], inv[maxn], pw[maxn];
vi pr;
void sieve() {
	for(int i = 2; i < maxn; i++) {
		if(!lp[i]) {
			lp[i] = i;
			pr.pb(i);
		}
		for(int j = 0; j < pr.size() && pr[j]*1ll*i < maxn && pr[j] <= lp[i]; j++) {
			lp[pr[j]*i] = pr[j];
		}
	}
}
void precalc() {
	sieve();
	fact[0] = inv[0] = inv[1] = pw[0] = 1;
	for(int i = 1; i < maxn; i++) {
		fact[i] = (fact[i-1]*1ll*i)%mod;
		pw[i] = (pw[i-1]<<1)%mod;
	}
	for(int i  = 2; i < maxn; i++) {
		inv[i] = (mod - (mod/i)*1ll*inv[mod%i]%mod)%mod;
	}
	for(int i = 2; i < maxn; i++) inv[i] = (inv[i-1]*1ll*inv[i])%mod;
}
ll nck(ll n, ll k) {
	if(k>n) return 0;
	ll r = (fact[n]*1ll*inv[k])%mod;
	return (r*1ll*inv[n-k])%mod;
}
void solve() {
	int x, y;
	ll ans = 1;
	cin >> x>> y;
	map<int, int> cnt;
	while(x>1) {
		cnt[lp[x]]++;
		x/=lp[x];
	}
	for(auto i : cnt) {
		ans = (ans*nck(y+i.second-1, y-1))%mod;
	}
	ans = (ans*pw[y-1])%mod;
	cout << ans << "\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	precalc();
	int t;
	cin >> t;
	while(t--) solve();
}