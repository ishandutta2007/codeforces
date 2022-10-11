//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, t, dp[maxn], c[maxn], s, ans;

vector<ll> g[maxn];

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb % 2) pc = (pc * pa) % mod;
	return pc;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = n; i > 0; i--){
		for(ll j = 1; i * j <= n; j++){
			g[i * j].pb(i);
		}
	}
	
	for(ll i = 2; i <= n; i++){
		s = n;
		for(ll j = 0; j < g[i].size(); j++){
			c[j] = n / g[i][j];
			for(ll k = 0; k < j; k++){
				if(g[i][k] % g[i][j] == 0) c[j] -= c[k];
			}
			s = (s + c[j] * dp[g[i][j]]) % mod;
		}
		dp[i] = (s * pw(n - c[0], mod - 2)) % mod;
		ans = (ans + dp[i]) % mod;
	}
	
	ans = (ans * pw(n, mod - 2) + 1) % mod;
	
	cout << (ans + mod) % mod;
	
	return 0;
}