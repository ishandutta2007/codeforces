//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, ans[maxn], t;

vector<pll> g[maxn];

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n - 1; i++){
		cin >> v >> u;
		g[v].pb({u, i});
		g[u].pb({v, i});
	}
	
	for(ll i = 1; i <= n; i++){
		if(g[i].size() > 2){
			for(ll j = 0; j < 3; j++){
				ans[g[i][j].S] = ++t;
			}
			break;
		}
	}
	
	for(ll i = 0; i < n - 1; i++){
		if(ans[i] == 0) ans[i] = ++t;
		cout << ans[i] - 1 << '\n';
	}
	
	return 0;
}