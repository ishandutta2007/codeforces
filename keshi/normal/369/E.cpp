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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, c[maxn], ans[maxn], fen[maxn];

vector<ll> g[maxn];
vector<pll> q[maxn];

void upd(ll x, ll y){
	for(; x < maxn; x += x & -x){
		fen[x] += y;
	}
	return;
}

ll get(ll x){
	ll y = 0;
	for(; x > 0; x -= x & -x){
		y += fen[x];
	}
	return y;
}

int main(){
	ll l, r;
	fast_io;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> l >> r;
		upd(r, 1);
		g[l].pb(r);
	}
	
	for(ll i = 0; i < m; i++){
		cin >> c[i];
		ans[i] = n;
		l = 0;
		for(ll j = 0; j < c[i]; j++){
			cin >> r;
			ans[i] -= get(r - 1);
			q[l].pb(Mp(r - 1, i));
			l = r;
		}
		ans[i] -= get(maxn - 1);
		q[l].pb(Mp(maxn - 1, i));
	}
	fill(fen, fen + maxn, 0);
	
	for(ll i = 0; i < maxn; i++){
		for(ll j = 0; j < g[i].size(); j++){
			upd(g[i][j], 1);
		}
		for(ll j = 0; j < q[i].size(); j++){
			ans[q[i][j].S] += get(q[i][j].F);
		}
	}
	
	for(ll i = 0; i < m; i++){
		cout << ans[i] << '\n';
	}
	
	return 0;
}