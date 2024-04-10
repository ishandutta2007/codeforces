//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 3e5 + 100;
const int mod = 1e9 + 7;
const int inf = 1e9;

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

int n, m, q, h[maxn], f1[maxn], f2[maxn];
vector<pii> g[maxn];
vector<int> vec;
vector<int> v1[maxn], v2[maxn];
bool vis[maxn];

void dfs(int v, int p = -1){
	vis[v] = 1;
	vec.pb(v);
	for(pii u : g[v]){
		if(u.S == p) continue;
		if(vis[u.F]){
			if(h[u.F] > h[v]) continue;
			int l = v, r = v;
			for(int i = h[u.F]; i <= h[v]; i++){
				l = min(l, vec[i]);
				r = max(r, vec[i]);
			}
			v1[l].pb(r);
			v2[r].pb(l);
		}
		else{
			h[u.F] = h[v] + 1;
			dfs(u.F, u.S);
		}
	}
	vec.pop_back();
	return;
}

ll ps[maxn];

int main(){
	fast_io;

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(Mp(u, i));
		g[u].pb(Mp(v, i));
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		dfs(i);
	}
	f2[0] = 0;
	for(int i = 1; i <= n; i++){
		f2[i] = f2[i - 1];
		for(int j : v2[i]){
			f2[i] = max(f2[i], j);
		}
	}
	f1[n + 1] = n + 1;
	for(int i = n; i > 0; i--){
		f1[i] = f1[i + 1];
		for(int j : v1[i]){
			f1[i] = min(f1[i], j);
		}
	}
	for(int i = 1; i <= n; i++){
		ps[i] = ps[i - 1] + i - f2[i];
	}
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		int x = f1[l];
		if(x > r){
			cout << 1ll * (r - l + 1) * (r - l + 2) / 2 << "\n";
			continue;
		}
		cout << ps[r] - ps[x - 1] + 1ll * (x - l) * (x - l + 1) / 2 << "\n";
	}
	
	return 0;
}