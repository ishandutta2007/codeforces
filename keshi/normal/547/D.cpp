//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 4e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

bool f[maxn], t[maxn];

vector<ll> ans, h;

set<ll> g[maxn], g2[maxn];

map<ll, ll> mp[maxn];

void tur(ll v){
	ll u = -1;
	set<ll>::iterator itr = g2[v].lower_bound(u);
	while(itr != g2[v].end()){
		u = *itr;
		g2[u].erase(v);
		g2[v].erase(itr);
		tur(u);
		itr = g2[v].lower_bound(u);
	}
	itr = g[v].lower_bound(u);
	while(itr != g[v].end()){
		u = *itr;
		g[u].erase(v);
		g[v].erase(itr);
		tur(u);
		itr = g[v].lower_bound(u);
	}
	ans.pb(v);
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> v >> u;
		v = v * 2;
		u = u * 2 - 1;
		g[v].insert(u);
		g[u].insert(v);
		mp[v][u] = i;
		mp[u][v] = i;
	}
	
	for(ll i = 0; i < maxn; i++){
		if(g[i].size() % 2){
			ans.pb(i);
			h.pb(i);
			t[i] = 1;
		}
	}
	
	for(ll i = 0; i < maxn; i++){
		if(!t[i]){
			h.pb(i);
		}
	}
	
	for(ll j = 0; j + 1 < ans.size(); j += 2){
		g2[ans[j]].insert(ans[j + 1]);
		g2[ans[j + 1]].insert(ans[j]);
	}
	
	for(ll i = 0; i < h.size(); i++){
		ans.clear();
		tur(h[i]);
		c = 0;
		for(ll j = 0; j + 1 < ans.size(); j++){
			if(mp[ans[j]][ans[j + 1]] == 0){
				c = j;
			}
		}
		if(ans.size() % 2) c = 0;
		for(ll j = 0; j + 1 < ans.size(); j++){
			if(j < c) f[mp[ans[j]][ans[j + 1]]] = (c - j) % 2;
			else f[mp[ans[j]][ans[j + 1]]] = (j - c + 1) % 2;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		cout << (f[i] ? 'b' : 'r');
	}
	
	return 0;
}