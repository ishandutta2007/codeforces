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

ll t, n, a[maxn], d[maxn];
vector<ll> g[maxn];
bool vis[maxn];
pll vec[maxn];

void dfs(ll v){
	vis[v] = 1;
	for(ll u : g[v]){
		if(!vis[u]){
			d[v]++;
			dfs(u);
		}
	}
	return;
}

int main(){
    fast_io;

	cin >> t;
	while(t--){
		cin >> n;
		ll ans = 0;
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
			vis[i] = 0;
			d[i] = 0;
			g[i].clear();
			ans += a[i];
		}
		for(ll i = 1; i < n; i++){
			ll v, u;
			cin >> v >> u;
			g[v].pb(u);
			g[u].pb(v);
		}
		dfs(1);
		d[1]--;
		for(ll i = 1; i <= n; i++){
			vec[i] = Mp(a[i], d[i]);
		}
		sort(vec + 1, vec + n + 1, greater<pll>());
		cout << ans << " ";
		for(ll i = 1; i <= n; i++){
			while(vec[i].S > 0){
				ans += vec[i].F;
				cout << ans << " ";
				vec[i].S--;
			}
		}
		cout << "\n";
	}

    return 0;
}