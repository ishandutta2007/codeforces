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

ll n, m, s, p[2][maxn], d, gp[maxn];
bool vis[2][maxn], f, f2, val[maxn];
vector<ll> g[maxn], ans;
set<pll> st;

void dfs(ll v, ll c){
	ll u;
	vis[c][v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[1 - c][u]){
			p[1 - c][u] = v;
			dfs(u, 1 - c);
		}
	}
	if(g[v].empty()) f = 1;
	if(g[v].empty() && c == 1) d = v;
	return;
}
void dfs2(ll v){
	ll u;
	vis[0][v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[0][u]) dfs2(u);
		else f = 1;
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> m;
		for(ll j = 0; j < m; j++){
			cin >> s;
			g[i].pb(s);
		}
	}
	cin >> s;
	dfs(s, 0);
	if(!f){
		cout << "Draw";
		return 0;
	}
	if(d == 0){
		for(ll i = 1; i <= n; i++){
			if(vis[0][i] || vis[1][i]) val[i] = 1;
		}
		for(ll i = 1; i <= n; i++){
			for(ll j = 0; j < g[i].size(); j++){
				if(val[i] && val[g[i][j]]) gp[g[i][j]]++;
			}
		}
		for(ll i = 1; i <= n; i++){
			if(val[i]) st.insert(Mp(gp[i], i));
		}
		while(!st.empty()){
			if(st.begin() -> F){
				cout << "Draw";
				return 0;
			}
			v = st.begin() -> S;
			st.erase(st.begin());
			for(ll j = 0; j < g[v].size(); j++){
				u = g[v][j];
				st.erase(Mp(gp[u], u));
				gp[u]--;
				st.insert(Mp(gp[u], u));
			}
		}
		cout << "Lose";
		return 0;
	}
	v = 1;
	while(d != s || v != 0){
		ans.pb(d);
		d = p[v][d];
		v = 1 - v;
	}
	ans.pb(s);
	reverse(ans.begin(), ans.end());
	cout << "Win\n";;
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}