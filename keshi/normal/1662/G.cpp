//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

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

int n, par[maxn], sz[maxn], ss[maxn], d[maxn], cnt[maxn], cen;
vector<int> g[maxn];
ll ans;

void dfs(int v){
	sz[v] = 1;
	ss[v] = -1;
	for(int u : g[v]){
		dfs(u);
		ss[v] = max(ss[v], sz[u]);
		sz[v] += sz[u];
	}
	ss[v] = max(ss[v], n - sz[v]);
	return;
}

void dfs2(int v, int p = -1){
	sz[v] = 1;
	ans += d[v];
	for(int u : g[v]){
		if(u == p) continue;
		d[u] = d[v] + 1;
		dfs2(u, v);
		sz[v] += sz[u];
	}
	if(par[v] && par[v] != p){
		int u = par[v];
		d[u] = d[v] + 1;
		dfs2(u, v);
		sz[v] += sz[u];
	}
	if(p == cen) cnt[sz[v]]++;
	return;
}
bitset<maxn> b;

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 2; i <= n; i++){
		cin >> par[i];
		g[par[i]].pb(i);
	}
	dfs(1);
	cen = 1;
	for(int i = 1; i <= n; i++){
		if(ss[cen] > ss[i]) cen = i;
	}
	dfs2(cen);
	b[0] = 1;
	for(int i = 1; i < maxn; i++){
		if(cnt[i] > 2){
			int x = (cnt[i] - 1) / 2;
			cnt[i << 1] += x;
			cnt[i] -= x * 2;
		}
		if(cnt[i] == 0) continue;
		b |= (b << i);
		if(b[i] == 2) b |= (b << i);
	}
	ll mx = 0;
	for(int i = 0; i < maxn; i++){
		if(b[i]) mx = max(mx, ans + 1ll * (i + 1) * (n - i));
	}
	cout << mx;
	
	return 0;
}