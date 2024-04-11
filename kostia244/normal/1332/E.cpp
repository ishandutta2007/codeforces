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
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 404, mod = (119<<23)+1, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll bp(ll a, ll p) {
	if(a==0) return 0;
	a%=mod;
	a+=mod;
	a%=mod;
	ll r = 1;
	while(p) {
		if(p&1) r = r*1ll*a%mod;
		p>>=1, a=a*1ll*a%mod;
	}
	return r;
}
ll eval(ll n, ll x, ll y) {
	ll h = (mod+1)/2;
	ll r = bp(x-y, n);
	r = (r + bp(x+y, n))%mod;
	return h*r%mod;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m, L, R;//x = even number
	cin >> n >> m >> L >> R;
	if((n*m)&1) {
		cout << bp(R-L+1, n*m);
	} else {
		cout << eval(n*m, R/2 - (L-1)/2, R-L+1 - (R/2 - (L-1)/2));
	}
	
	return 0;
}