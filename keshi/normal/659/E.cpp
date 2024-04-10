//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
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

int n, m, s, c, ans;
vector<int> g[maxn];
bool vis[maxn];

void dfs(int v){
	vis[v] = 1;
	c++;
	s += Sz(g[v]);
	for(int u : g[v]){
		if(!vis[u]) dfs(u);
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			s = c = 0;
			dfs(i);
			if(s == 2 * (c - 1)) ans++;
		}
	}
	cout << ans;
	
	return 0;
}