//In the name of GOD
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

ll n, m, t, d, ans[maxn];

pll a[maxn];

vector<pll> g[maxn];

tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> s;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = -i;
	}
	
	cin >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> t >> d;
		g[t - 1].pb({d - 1, i});
	}
	
	sort(a, a + n, greater<pll>());
	
	for(ll i = 0; i < n; i++){
		s.insert({-a[i].S, a[i].F});
		for(ll j = 0; j < g[i].size(); j++){
			ans[g[i][j].S] = s.find_by_order(g[i][j].F) -> S;
		}
	}
	
	for(ll i = 0; i < m; i++){
		cout << ans[i] << '\n';
	}
	
	return 0;
}