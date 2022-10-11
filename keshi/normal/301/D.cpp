//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, l, r, a[maxn], b[maxn], ans[maxn], fen[maxn];

vector<pll> g[maxn];
vector<ll> p[maxn];

void upd(ll x){
	for(; x > 0; x -= x & -x){
		fen[x]++;
	}
	return;
}

ll get(ll x){
	ll y = 0;
	for(; x < maxn; x += x & -x){
		y += fen[x];
	}
	return y;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		b[a[i]] = i;
	}
	
	for(ll i = 1; i < maxn; i++){
		for(ll j = i; j < maxn; j += i){
			if(b[i] && b[j]){
				p[max(b[i], b[j])].pb(min(b[i], b[j]));
			}
		}
	}
	
	for(ll i = 0; i < m; i++){
		cin >> l >> r;
		g[r].pb({l, i});
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < p[i].size(); j++){
			upd(p[i][j]);
		}
		for(ll j = 0; j < g[i].size(); j++){
			ans[g[i][j].S] += get(g[i][j].F);
		}
	}
	
	for(ll i = 0; i < m; i++){
		cout << ans[i] << '\n';
	}
	
	return 0;
}