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

ll q, n, m, a, b, c, d, dsu[maxn], sz[maxn];

bool f[maxn], h[maxn];

vector<ll> g[maxn];

void init(){
	for(ll i = 1; i <= n; i++){
		dsu[i] = i;
		sz[i] = 1;
		f[i] = 0;
		h[i] = 0;
		g[i].clear();
	}
}

ll root(ll v){
	if(dsu[v] == v) return v;
	return root(dsu[v]);
}

bool Union(ll v, ll u){
	ll x = root(v), y = root(u);
	if(x == y) return 1;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	f[x] = f[x] || f[y];
	h[x] = h[x] || h[y];
	dsu[y] = x;
	return 0;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> q;
	
	while(q--){
		c = d = 0;
		cin >> n >> m >> a >> b;
		init();
		for(ll i = 0; i < m; i++){
			cin >> v >> u;
			if((v == a && u == b) || (u == a && v == b)) continue;
			if(v == a){
				f[root(u)] = 1;
			}
			else if(v == b){
				h[root(u)] = 1;
			}
			else if(u == a){
				f[root(v)] = 1;
			}
			else if(u == b){
				h[root(v)] = 1;
			}
			else{
				Union(v, u);
			}
		}
		for(ll i = 1; i <= n; i++){
			if(i == root(i)){
				if(f[i] ^ h[i]){
					if(f[i]){
						c += sz[i];
					}
					else{
						d += sz[i];
					}
				}
			}
		}
		cout << c * d << '\n';
	}
	
	return 0;
}