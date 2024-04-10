//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2000;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, lca, node1, len, par[maxn], h[maxn], p[maxn];
vector<ll> g[maxn], a[maxn], vec;
bool vis[maxn];
string s;

void dfs(ll v){
	ll u;
	vis[v] = 1;
	a[h[v]].pb(v);
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			par[u] = v;
			h[u] = h[v] + 1;
			dfs(u);
		}
	}
	return;
}

void ask(){
	cout << "? " << vec.size();
	for(ll i = 0; i < vec.size(); i++){
		cout << " " << vec[i];
	}
	cout << '\n';
	cout.flush();
	vec.clear();
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(ll i = 0; i <= n; i++){
			g[i].clear();
			a[i].clear();
			vis[i] = 0;
			p[i] = 0;
		}
		for(ll i = 1; i < n; i++){
			cin >> v >> u;
			g[v].pb(u);
			g[u].pb(v);
		}
		for(ll i = 1; i <= n; i++){
			vec.pb(i);
		}
		ask();
		cin >> lca >> len;
		h[lca] = 0;
		dfs(lca);
		ll l = 0, r = n, mid;
		while(l * 2 < len) l++;
		while(r - 1 > len || a[r - 1].empty()) r--;
		while(r - l > 1){
			mid = (l + r) / 2;
			for(ll i = 0; i < a[mid].size(); i++){
				vec.pb(a[mid][i]);
			}
			ask();
			cin >> v >> u;
			p[mid] = v;
			if(u == len) l = mid;
			else r = mid;
		}
		if(p[l] == 0){
			for(ll i = 0; i < a[l].size(); i++){
				vec.pb(a[l][i]);
			}
			ask();
			cin >> v >> u;
			p[l] = v;
		}
		node1 = p[l];
		v = node1;
		while(v != lca) vis[v] = 0, v = par[v];
		for(ll i = 1; i <= n; i++){
			if(h[i] + h[node1] == len && vis[i]) vec.pb(i);
		}
		ask();
		cin >> v >> u;
		cout << "! " << v << " " << node1 << '\n';
		cout.flush();
		cin >> s;
		if(s != "Correct") return 0;
	}
	
	return 0;
}