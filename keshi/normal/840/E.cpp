//In the name of God
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 1e5 + 100;
const int maxm = 1e7;
const int mod = 1e9 + 7;
const int inf = 1e9;
const int tof = 256;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
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

int n, q, a[maxn], h[maxn], ha[maxn], t, g[maxm][2], pp[maxn], p[maxn];
vector<int> gg[maxn];
int prep[maxn][tof];

void dfs(int v){
	ha[h[v]] = v;
	for(int u : gg[v]){
		if(u == p[v]) continue;
		p[u] = v;
		h[u] = h[v] + 1;
		dfs(u);
	}
	if(h[v] >= tof){
		pp[v] = ha[h[v] - tof];
	}
	else pp[v] = 0;
	for(int i = 0; i < tof; i++){
		if(i > h[v]) break;
		int u = ha[h[v] - i];
		int x = i ^ a[u];
		prep[v][(x >> 8) ^ (tof - 1)] = max(prep[v][(x >> 8) ^ (tof - 1)], x | (255 << 8));
	}
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < tof; j++){
			prep[v][j] = max(prep[v][j], prep[v][j ^ (1 << i)] - (1 << (i + 8)));
		}
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		gg[v].pb(u);
		gg[u].pb(v);
	}
	t = n + 5;
	h[0] = -1;
	p[1] = 0;
	dfs(1);
	while(q--){
		int v, u;
		cin >> v >> u;
		int x = 0, ans = 0;
		while(h[u] - h[v] > tof){
			ans = max(ans, prep[u][x]);
			x++;
			u = pp[u];
		}
		x *= 256;
		while(h[u] >= h[v]){
			ans = max(ans, x ^ a[u]);
			x++;
			u = p[u];
		}
		cout << ans << "\n";
	}
	
	return 0;
}