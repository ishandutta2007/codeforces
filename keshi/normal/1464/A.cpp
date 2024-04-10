//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

ll t, n, m, cnt[maxn], ans;
vector<ll> g[maxn];
bool f, vis[maxn];

void dfs(ll v, ll p){
	vis[v] = 1;
	for(ll u : g[v]){
		if(u == p) continue;
		if(vis[u]) f = 1;
		else dfs(u, v);
	}
	return;
}

int main(){
    fast_io;

	cin >> t;
	while(t--){
		cin >> n >> m;
		for(ll i = 1; i <= n; i++){
			g[i].clear();
			vis[i] = 0;
		}
		ans = 0;
		for(ll i = 0; i < m; i++){
			ll x, y;
			cin >> x >> y;
			if(x == y) continue;
			ans++;
			g[x].pb(y);
			g[y].pb(x);
		}
		for(ll i = 1; i <= n; i++){
			if(!vis[i] && !g[i].empty()){
				f = 0;
				dfs(i, 0);
				if(f) ans++;
			}
		}
		cout << ans << '\n';
	}

    return 0;
}