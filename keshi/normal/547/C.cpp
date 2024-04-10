//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, x, v, u, ans, a[maxn], d[maxn], dp[maxn], cnt[maxn];

bool vis[maxn];

vector<ll> g[maxn];

int main(){
	fast_io;
	
	for(ll i = 1; i < maxn; i++){
		if(i == 1) d[i] = 1 - dp[i];
		else d[i] = -dp[i];
		for(ll j = 1; i * j < maxn; j++){
			g[i * j].pb(j);
			dp[i * j] += d[i];
		}
	}
	
	cin >> n >> q;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	while(q--){
		cin >> x;
		v = a[x];
		if(vis[x]){
			for(ll i = 0; i < g[v].size(); i++){
				u = g[v][i];
				cnt[u]--;
				ans -= cnt[u] * d[u];
			}
			vis[x] = 0;
		}
		else{
			for(ll i = 0; i < g[v].size(); i++){
				u = g[v][i];
				ans += cnt[u] * d[u];
				cnt[u]++;
			}
			vis[x] = 1;
		}
		cout << ans << '\n';
	}
	
	return 0;
}