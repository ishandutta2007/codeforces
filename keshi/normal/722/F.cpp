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

ll n, m, k, a, r, x, c[maxn], d[maxn];

vector<pair<pll, ll> > g[maxn];

bool f;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> k;
		for(ll j = 0; j < k; j++){
			cin >> a;
			g[a].pb(make_pair(make_pair(k, j), i));
		}
	}
	
	for(ll i = 1; i <= m; i++){
		fill(d, d + 50, 0);
		r = x = 0;
		for(ll j = 0; j < g[i].size(); j++){
			f = 1;
			while(f){
				if(r >= g[i].size() || (r > 0 && g[i][r].S - g[i][max(r - 1, j)].S > 1)) break;
				for(ll t = 1; t <= 40; t++){
					if(d[t] > 0 && (g[i][r].F.S - c[t]) % __gcd(g[i][r].F.F, t)) f = 0;
				}
				if(f) c[g[i][r].F.F] = g[i][r].F.S, d[g[i][r].F.F]++, r++;
			}
			x = max(x, r - j);
			d[g[i][j].F.F]--;
		}
		cout << x << '\n';
	}
	
	return 0;
}