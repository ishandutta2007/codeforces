//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll fact[maxn], inv[maxn];
ll bp(ll a, ll p) {
	ll res = 1;
	while(p) {
		if(p&1) res = (res*a)%mod;
		a=(a*a)%mod;
		p>>=1;
	}
	return res;
}
ll nck(ll n, ll k) {
	ll res = (fact[n]*inv[k])%mod;
	return (res*inv[n-k])%mod;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		fact[0] = 1;
	for(int i = 1; i < maxn; i++)
		fact[i] = (fact[i-1]*i)%mod;
	inv[maxn-1]=bp(fact[maxn-1], mod-2);
	for(int i = maxn-1; i--;)
		inv[i] = (inv[i+1]*(i+1))%mod;
	int n;
	cin >> n;
	int ans = 2ll*nck(2*n-1, n)%mod;
	cout << (mod+ans-n)%mod << endl;
}