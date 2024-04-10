//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
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

ll n, m, dsu[maxn], sz[maxn], f[maxn], ans;
bool vis[maxn];
vector<ll> vec;

void init(ll s){
	for(ll i = 0; i <= s; i++){
		sz[i] = 1;
		dsu[i] = i;
		f[i] = i;
	}
	return;
}

ll par(ll v){
	if(dsu[v] != v) dsu[v] = par(dsu[v]);
	return dsu[v];
}

void Union(ll v, ll u){
	v = par(v);
	u = par(u);
	if(v == u) return;
	if(sz[v] < sz[u]) swap(v, u);
	dsu[u] = v;
	sz[v] += sz[u];
	f[v] = min(f[v], f[u]);
	return;
}

int main(){
    fast_io;

	cin >> n >> m;
	init(m);
	ans = 1;
	for(ll i = 1; i <= n; i++){
		ll k;
		ll x = 0, y = m + 1;
		cin >> k >> x;
		if(k == 2) cin >> y;
		x = f[par(m + 1 - x)];
 		y = f[par(m + 1 - y)];
		if(x == y) continue;
		vec.pb(i);
		ans = ans * 2;
		if(ans >= mod) ans -= mod;
		Union(x, y);
	}
	cout << ans << " " << Sz(vec)<< "\n";
	for(ll i : vec){
		cout << i << " ";
	}

    return 0;
}