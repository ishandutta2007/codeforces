#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<17, mod = 1e9 + 7 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll bp(ll a, ll p) {
	p%=mod-1;
	if(p<0) p+=mod-1;
	if(p>=mod-1) p-=mod-1;
	ll r = 1;
	while(p) {
		if(p&1) r = r*1ll*a%mod;
		p>>=1, a = a*1ll*a%mod;
	}
	return r;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, a = 1, t;
	cin >> n;
	int ev = 0;
	for(int i = 0; i < n; i++) cin >> t, t%=mod-1, (a*=t)%=mod-1, ev |= !(t&1);
	ll r = 1;
	if(!ev) r = (mod + bp(2, a-1) - 1)*333333336ll%mod;
	else r = (mod + bp(2, a-1) + 1)*333333336ll%mod;
	cout << r << "/" << bp(2, a-1);
	return 0;
}