//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll maxm = 50;
const ll maxk = 1e4 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, f[maxn], fp[maxn], p[maxn], b, s, x[maxn], ans, dp[maxm][maxm][2], ps[maxm][maxm + 1][2];

vector<ll> g, a, c;

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
	fp[0] = 1;
	p[0] = 1;
	for(ll i = 1; i < maxn; i++){
		f[i] = (f[i - 1] * i) % mod;
		fp[i] = pw(f[i], mod - 2);
		p[i] = pw(i, mod - 2);
	}
	
	cin >> n >> k;
	
	for(ll o = 1; o <= k; o++){
		for(ll i = 0; i < maxm; i++){
			for(ll j = 0; j <= i; j++){
				if(o == 1) dp[i][j][o % 2] = p[i + 1];
				else dp[i][j][o % 2] = (ps[i][i + 1][1 - o % 2] - ps[i][j][1 - o % 2]) % mod;
				ps[i][j + 1][o % 2] = (ps[i][j][o % 2] + dp[i][j][o % 2] * p[j + 1]) % mod;
			}
		}
	}
	
	m = n;
	
	for(ll i = 2; i * i <= m; i++){
		if(m % i == 0){
			a.pb(i);
			c.pb(0);
			while(m % i == 0) m /= i, c.back()++;
		}
	}
	
	if(m != 1){
		a.pb(m);
		c.pb(1);
	}
	
	for(ll i = 1; i * i <= n; i++){
		if(n % i == 0){
			g.pb(i);
			if(i * i != n) g.pb(n / i);
		}
	}
	
	for(ll i = 0; i < g.size(); i++){
		m = g[i];
		x[i] = 1;
		for(ll j = 0; j < a.size(); j++){
			b = 0;
			while(m % a[j] == 0){
				m /= a[j];
				b++;
			}
			x[i] = (x[i] * dp[c[j]][b][k % 2]) % mod;
		}
		ans = (ans + (g[i] % mod) * x[i]) % mod;
	}
	
	cout << (ans + mod) % mod;
	
	return 0;
}