//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, q, ans, x, y, a[maxn], d[maxn], c[maxn], f[maxn], fp[maxn];

vector<ll> g[maxn];

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb % 2) pc = (pc * pa) % mod;
	return pc;
}

ll C(ll ca, ll cb){
	if(cb < 0 || cb > ca) return 0;
	return (((f[ca] * fp[cb]) % mod) * fp[ca - cb]) % mod;
}

int main(){
	fast_io;
	
	f[0] = 1;
	fp[0] = pw(f[0], mod - 2);
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
		fp[i] = pw(f[i], mod - 2);
	}
	
	for(ll i = 1; i < maxn; i++){
		d[i] = i - a[i];
		for(ll j = 1; i * j < maxn; j++){
			a[i * j] += d[i];
			g[i * j].pb(i);
		}
	}
	
	cin >> n >> k >> q;
	
	for(ll i = 0; i < n + q; i++){
		cin >> x;
		for(ll j = 0; j < g[x].size(); j++){
		    y = g[x][j];
			ans = (ans + (d[y] * C(c[y], k - 1)) % mod) % mod;
			c[y]++;
		}
		if(i >= n) cout << ans << '\n';
	}
	
	return 0;
}