//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, m, a[maxn], c[maxn], b[4][maxn], d[maxn], e, s, r;

vector<ll> g;

bool f[maxn], vis[maxn], val[maxn];

char ch;

void dfs(ll v, ll h){
	if(vis[v]){
		if(h != d[v]) e = abs(h - d[v]);
		return;
	}
	ll u;
	vis[v] = 1;
	d[v] = h;
	g.pb(v);
	dfs(a[v], h + 1);
	for(ll i = 0; i < c[v]; i++){
		u = b[i][v];
		dfs(u, h - 1);
	}
	return;
}

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n >> m;
		s = r = 0;
		fill(vis, vis + n * m, 0);
		fill(c, c + n * m, 0);
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < m; j++){
				cin >> ch;
				if(ch == '1') f[i * m + j] = 1;
				else f[i * m + j] = 0;
			}
		}
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < m; j++){
				cin >> ch;
				if(ch == 'R') a[i * m + j] = i * m + j + 1, b[c[i * m + j + 1]++][i * m + j + 1] = i * m + j;
				if(ch == 'L') a[i * m + j] = i * m + j - 1, b[c[i * m + j - 1]++][i * m + j - 1] = i * m + j;
				if(ch == 'U') a[i * m + j] = i * m + j - m, b[c[i * m + j - m]++][i * m + j - m] = i * m + j;
				if(ch == 'D') a[i * m + j] = i * m + j + m, b[c[i * m + j + m]++][i * m + j + m] = i * m + j;
			}
		}
		for(ll i = 0; i < n * m; i++){
			if(!vis[i]){
				g.clear();
				dfs(i, 0);
				for(ll j = 0; j < g.size(); j++){
					if(f[g[j]]) continue;
					if(!val[(d[g[j]] % e + e) % e]) r++;
					val[(d[g[j]] % e + e) % e] = 1;
				}
				s += e;
				for(ll j = 0; j < g.size(); j++){
					val[(d[g[j]] % e + e) % e] = 0;
				}
			}
		}
		cout << s << " " << r << '\n';
	}
	
	return 0;
}