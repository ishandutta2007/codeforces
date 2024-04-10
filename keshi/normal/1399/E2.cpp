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

ll t, n, ans, m1, m2, s, a[maxm], b[maxn], d[maxm], ps[maxm];
bool vis[maxn];
vector<pair<ll, pll> > g[maxn];

void dfs(ll v){
	ll u, w, c;
	vis[v] = 1;
	b[v] = 0;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		w = g[v][i].S.F;
		c = g[v][i].S.S;
		if(vis[u]) continue;
		dfs(u);
		s -= b[u] * w;
		while(w){
			if(c == 1) a[m1++] = (w + 1) / 2 * b[u];
			if(c == 2) d[m2++] = (w + 1) / 2 * b[u];
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
		m1 = m2 = 0;
		for(ll i = 1; i <= n; i++){
			g[i].clear();
			vis[i] = 0;
		}
		for(ll i = 1; i < n; i++){
			ll v, u, w, c;
			cin >> v >> u >> w >> c;
			g[v].pb(Mp(u, Mp(w, c)));
			g[u].pb(Mp(v, Mp(w, c)));
		}
		dfs(1);
		sort(a, a + m1, greater<ll>());
		sort(d, d + m2, greater<ll>());
		ps[0] = 0;
		for(ll i = 0; i < m1; i++){
			ps[i + 1] = ps[i] + a[i];
		}
		ans = inf;
		for(ll i = 0; i <= m2; i++){
			if(s + ps[m1] >= 0) ans = min(ans, i * 2 + ll(lower_bound(ps, ps + m1 + 1, -s) - ps));
			s += d[i];
		}
		cout << ans << '\n';
	}
	
	return 0;
}