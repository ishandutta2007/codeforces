//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 30000;
const ll maxk = 60;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, d, D, t, g[maxn][10], nxt[maxn][10], par[maxn], bd[maxn], q[maxn], dp[maxn][maxk];
string s, l, r;

void bld(){
	ll l = 0, r = 0;
	q[r++] = 0;
	while(l < r){
		ll v = q[l++];
		bd[v] |= bd[par[v]];
		for(ll i = 0; i < 10; i++){
			if(g[v][i]){
				nxt[v][i] = g[v][i];
				if(v) par[nxt[v][i]] = nxt[par[v]][i];
				q[r++] = nxt[v][i];
			}
			else{
				nxt[v][i] = nxt[par[v]][i];
			}
		}
	}
}

ll cal(string x){
	ll v = 0, ans = 0;
	for(ll i = 0; i < D; i++){
		if(bd[v]) break;
		for(ll j = 0; j < (x[i] - '0'); j++){
			ans += dp[nxt[v][j]][D - 1 - i];
			ans %= mod;
		}
		v = nxt[v][x[i] - '0'];
	}
	ans += dp[v][0];
	return ans % mod;
}

int main(){
	fast_io;
	
	cin >> s >> l >> r;
	n = Sz(s);
	D = Sz(l);
	d = Sz(l) / 2;
	for(ll i = D; i--;){
		if(l[i] == '0') l[i] = '9';
		else{
			l[i]--;
			break;
		}
	}
	for(ll i = 0; i + d <= n; i++){
		ll x = 0;
		for(ll j = 0; j < d; j++){
			if(!g[x][s[i + j] - '0']) g[x][s[i + j] - '0'] = ++t;
			x = g[x][s[i + j] - '0'];
		}
		bd[x] = 1;
	}
	bld();
	for(ll i = 0; i <= t; i++){
		if(!bd[i]) dp[i][0] = 1;
	}
	for(ll j = 1; j < maxk; j++){
		for(ll i = 0; i <= t; i++){
			if(bd[i]) continue;
			for(ll k = 0; k < 10; k++){
				dp[i][j] += dp[nxt[i][k]][j - 1];
				dp[i][j] %= mod;
			}
		}
	}
	ll cl = 0, cr = 0;
	for(ll i = 0; i < D; i++){
		cl = (cl * 10 + (l[i] - '0')) % mod;
		cr = (cr * 10 + (r[i] - '0')) % mod;
	}
	cout << ((cr - cl - (cal(r) - cal(l))) % mod + mod) % mod;
	return 0;
}