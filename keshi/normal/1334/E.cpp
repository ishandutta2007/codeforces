//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1000;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, a, b, c, d, e, h, ans, f[maxn], fp[maxn];

vector<ll> g;

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb % 2) pc = (pc * pa) % mod;
	return pc;
}

int main(){
	fast_io;
	
	f[0] = 1;
	fp[0] = 1;
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
		fp[i] = pw(f[i], mod - 2);
	}
	
	cin >> n >> q;
	
	for(ll i = 2; i * i <= n; i++){
		if(n % i) continue;
		while(n % i == 0) n /= i;
		g.pb(i);
	}
	if(n > 1){
		g.pb(n);
	}
	
	while(q--){
		cin >> a >> b;
		ans = 1;
		e = h = 0;
		for(ll i = 0; i < g.size(); i++){
			c = 0;
			while(a % g[i] == 0) a /= g[i], c++;
			d = 0;
			while(b % g[i] == 0) b /= g[i], d++;
			ans = (ans * fp[abs(c - d)]) % mod;
			if(c > d) e += c - d;
			else h += d - c;
		}
		ans = (((ans * f[e]) % mod) * f[h]) % mod;
		cout << ans << '\n';
	}
	
	return 0;
}