//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 9;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, sz[maxn], dsu[maxn];

void init(){
	for(ll i = 0; i <= n; i++){
		dsu[i] = i;
		sz[i] = 1;
	}
}

ll root(ll v){
	if(dsu[v] != v) dsu[v] = root(dsu[v]);
	return dsu[v];
}
bool Union(ll v, ll u){
	v = root(v);
	u = root(u);
	if(v == u) return 0;
	if(sz[v] < sz[u]) swap(v, u);
	dsu[u] = v;
	sz[v] += sz[u];
	return 1;
}

int main(){
    fast_io;
    
    cin >> n >> m;
    init();
    ll ans = 0;
    for(ll i = 0; i < m; i++){
    	ll v, u;
    	cin >> v >> u;
    	if(!Union(v, u)){
    		ans = ans * 2 + 1;
    		if(ans >= mod) ans -= mod;
		}
		cout << ans << "\n";
	}
 
    return 0;
}