//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
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

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int n, sz[maxn], dsu[maxn];
vector<int> g[maxn];
vector<pii> vec[maxn];
map<int, int> cne[maxn];
vector<pair<pii, pii> > ans;

void init(){
	for(int i = 0; i <= n; i++){
		dsu[i] = i;
		sz[i] = 1;
	}
}
int root(int v){
	if(dsu[v] != v) dsu[v] = root(dsu[v]);
	return dsu[v];
}

bool Union(int v, int u){
	v = root(v);
	u = root(u);
	if(v == u) return 0;
	if(sz[v] < sz[u]){
		swap(v, u);
	}
	dsu[u] = v;
	sz[v] += sz[u];
	if(Sz(vec[v]) < Sz(vec[u])){
		vec[v].swap(vec[u]);
	}
	for(pii i : vec[u]){
		vec[v].pb(i);
	}
	vec[u].clear();
	vec[u].shrink_to_fit();
	return 1;
}

void dfs(int v, int p = -1){
	for(int u : g[v]){
		if(u == p) continue;
		dfs(u, v);
		if(cne[v][u] == 2 || cne[u][v] == 2){
			Union(v, u);
		}
		else{
			int ru = root(u);
			while(!vec[ru].empty()){
				int x = vec[ru].back().F, y = vec[ru].back().S;
				vec[ru].pop_back();
				if(Union(x, y)){
					ans.pb(Mp(Mp(v, u), Mp(x, y)));
					break;
				}
			}
		}
	}
	return;
}


int main(){
	fast_io;
	
	cin >> n;
	init();
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
		if(v < u) swap(v, u);
		cne[v][u]++;
	}
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		if(v < u) swap(v, u);
		if(!cne[v][u]){
			vec[v].pb(Mp(v, u));
			vec[u].pb(Mp(v, u));
		}
		cne[v][u]++;
	}
	dfs(1);
	cout << Sz(ans) << "\n";
	for(auto i : ans){
		cout << i.F.F << " " << i.F.S << " " << i.S.F << " " << i.S.S << "\n";
	}
	
	return 0;
}