//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dsu[maxn], sz[maxn], t[maxn], a[maxn], mx, s, ans;

pair<ll, pll> e[maxn];

void init(){
	mx = 0;
	for(ll i = 1; i <= n; i++){
		dsu[i] = i;
		sz[i] = 1;
		t[i] = a[i] + sz[i];
		mx = max(mx, t[i]);
	}
}

ll root(ll v){
	if(dsu[v] == v) return v;
	return root(dsu[v]);
}

bool Union(ll v, ll u){
	ll x = root(v), y = root(u);
	if(x == y) return 1;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	t[x] += t[y];
	mx = max(mx, t[x]);
	dsu[y] = x;
	return 0;
}

bool isval(ll x){
	init();
	for(ll i = 0; i < n - 1; i++){
		if(e[i].F < x){
			Union(e[i].S.F, e[i].S.S);
		}
	}
	return (mx <= s);
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n - 1; i++){
		cin >> e[i].S.F >> e[i].S.S >> e[i].F;
	}
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		s += a[i];
	}
	
	ll l = 0, r = 2e4, mid;
	
	while(r - l > 1){
		mid = (l + r) / 2;
		if(isval(mid)) l = mid;
		else r = mid;
	}
	
	cout << l;
	
	return 0;
}