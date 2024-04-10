//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll maxm = 5e6;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, n, ans, m, s, a[maxm], b[maxn];
bool vis[maxn];
vector<pll> g[maxn];

void dfs(ll v){
	ll u, w, c;
	vis[v] = 1;
	b[v] = 0;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		w = g[v][i].S;
		if(vis[u]) continue;
		dfs(u);
		s -= b[u] * w;
		while(w){
			a[m++] = (w + 1) / 2 * b[u];
			w >>= 1;
		}
		b[v] += b[u];
	}
	if(v != 1 && g[v].size() == 1) b[v]++;
	return;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> s;
		m = 0;
		for(ll i = 1; i <= n; i++){
			g[i].clear();
			vis[i] = 0;
		}
		for(ll i = 1; i < n; i++){
			ll v, u, w;
			cin >> v >> u >> w;
			g[v].pb(Mp(u, w));
			g[u].pb(Mp(v, w));
		}
		dfs(1);
		sort(a, a + m, greater<ll>());
		ans = inf;
		for(ll i = 0; i < m; i++){
			if(s >= 0) ans = min(ans, i);
			s += a[i];
		}
		cout << ans << '\n';
	}
	
	return 0;
}