//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], c[maxn], t, ans;

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
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		c[a[i]]++;
	}
	
	for(ll i = maxn - 2; i > -1; i--){
		c[i] += c[i + 1];
	}
	
	for(ll i = 1; i < maxn; i++){
		for(ll j = 1; i * j < maxn; j++){
			g[i * j].pb(i);
		}
	}
	
	ans = 1;
	
	for(ll i = 2; i < maxn; i++){
		t = 1;
		for(ll j = 0; j + 1 < g[i].size(); j++){
			t = (t * pw(j + 1, c[g[i][j]] - c[g[i][j + 1]])) % mod;
		}
		t = (t * (pw(g[i].size(), c[i]) - pw(g[i].size() - 1, c[i])));
		ans = (ans + t) % mod;
	}
	
	cout << (ans + mod) % mod;
	
	return 0;
}