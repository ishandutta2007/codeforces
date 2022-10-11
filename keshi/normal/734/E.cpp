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

int n, a[maxn], d[maxn], door;
vector<int> g[maxn];

void dfs(int v, int p = -1){
	if(d[door] < d[v]) door = v;
	for(int u : g[v]){
		if(u == p) continue;
		d[u] = d[v] + (a[v] != a[u]);
		dfs(u, v);
	}
}

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	d[door = 1] = 0;
	dfs(door);
	d[door] = 0;
	dfs(door);
	cout << (d[door] + 1) / 2;
	
	return 0;
}