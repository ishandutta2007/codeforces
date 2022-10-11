//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
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

int t, n, q, a[maxn];
bool vis[maxn];
map<int, int> cnt;
vector<int> vec, g[maxn];
map<int, int> ind;
pii b[maxn];

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> q;
		cnt.clear();
		vec.clear();
		ind.clear();
		for(int i = 0; i < n; i++){
			cin >> a[i];
			cnt[a[i]]++;
		}
		int m = 0;
		for(auto i : cnt){
			b[m++] = Mp(i.S, i.F);
		}
		sort(b, b + m);
		for(int i = 0; i < m; i++){
			ind[b[i].S] = i;
			if(i + 1 == m || b[i].F != b[i + 1].F) vec.pb(i);
		}
		for(int i = 0; i < q; i++){
			int v, u;
			cin >> v >> u;
			v = ind[v];
			u = ind[u];
			g[v].pb(u);
			g[u].pb(v);
		}
		ll ans = 0;
		for(int i = 0; i < m; i++){
			for(int u : g[i]){
				vis[u] = 1;
			}
			if(i != 0 && !vis[i - 1]){
				ans = max(ans, 1ll * (b[i].F + b[i - 1].F) * (b[i].S + b[i - 1].S));
			}
			for(int u : g[i]){
				if(u != 0 && u - 1 != i && !vis[u - 1]){
					ans = max(ans, 1ll * (b[i].F + b[u - 1].F) * (b[i].S + b[u - 1].S));
				}
			}
			for(int u : g[i]){
				vis[u] = 0;
			}
		}
		for(int i : vec){
			for(int u : g[i]){
				vis[u] = 1;
			}
			for(int j : vec){
				if(i != j && !vis[j]){
					ans = max(ans, 1ll * (b[i].F + b[j].F) * (b[i].S + b[j].S));
				}
			}
			for(int u : g[i]){
				vis[u] = 0;
			}
		}
		cout << ans << "\n";
		for(int i = 0; i < m; i++){
			g[i].clear();
		}
	}
	
	return 0;
}