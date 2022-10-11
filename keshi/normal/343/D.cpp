//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 12e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, c, st[maxn], ft[maxn], t, seg1[maxn], seg2[maxn];

bool vis[maxn];

vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	st[v] = t++;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) dfs(u);
	}
	ft[v] = t;
	return;
}

void upd1(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg1[id] = max(seg1[id], x);
		return;
	}
	ll mid = (s + e) / 2;
	upd1(id * 2, s, mid, l, r, x);
	upd1(id * 2 + 1, mid, e, l, r, x);
	return;
}

ll get1(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg1[id];
	ll mid = (s + e) / 2;
	return max(seg1[id], max(get1(id * 2, s, mid, l, r), get1(id * 2 + 1, mid, e, l, r)));
}

void upd2(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg2[id] = max(seg2[id], x);
		return;
	}
	ll mid = (s + e) / 2;
	upd2(id * 2, s, mid, l, r, x);
	upd2(id * 2 + 1, mid, e, l, r, x);
	seg2[id] = max(seg2[id], max(seg2[id * 2], seg2[id * 2 + 1]));
	return;
}

ll get2(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg2[id];
	ll mid = (s + e) / 2;
	return max(get2(id * 2, s, mid, l, r), get2(id * 2 + 1, mid, e, l, r));
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs(1);
	
	cin >> q;
	
	t = 1;
	
	while(q--){
		cin >> c >> v;
		if(c == 1) upd1(1, 0, n, st[v], ft[v], t);
		else if(c == 2) upd2(1, 0, n, st[v], st[v] + 1, t);
		else cout << (get1(1, 0, n, st[v], st[v] + 1) > get2(1, 0, n, st[v], ft[v])) << '\n';
		t++;
	}
	
	return 0;
}