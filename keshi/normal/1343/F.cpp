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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, m[maxn], c[maxn], b[maxn], x, mx, mn;
vector<ll> a[maxn], g[maxn], vec;
bool vis[maxn], f;

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> n;
		for(ll i = 0; i <= n; i++){
			g[i].clear();
			a[i].clear();
		}
		for(ll i = 0; i < n - 1; i++){
			cin >> m[i];
			for(ll j = 0; j < m[i]; j++){
				cin >> x;
				a[i].pb(x);
				g[x].pb(i);
			}
		}
		for(ll i = 1; i <= n; i++){
			vec.clear();
			vec.pb(i);
			x = i;
			fill(vis, vis + n + 1, 0);
			for(ll j = 0; j < n - 1; j++){
				c[j] = m[j];
			}
			for(ll j = 1; j < n; j++){
				vis[x] = 1;
				for(ll k = 0; k < g[x].size(); k++){
					c[g[x][k]]--;
				}
				x = -1;
				for(ll k = 0; k < n; k++){
					if(c[k] == 1) x = k;
				}
				if(x == -1) break;
				for(ll k = 0; k < a[x].size(); k++){
					if(!vis[a[x][k]]){
						x = a[x][k];
						vec.pb(x);
						break;
					}
				}
			}
			if(x == -1) continue;
			for(ll j = 0; j < n; j++){
				b[vec[j]] = j;
			}
			f = 0;
			for(ll j = 0; j < n - 1; j++){
				mn = inf;
				mx = -1;
				for(ll k = 0; k < a[j].size(); k++){
					mx = max(mx, b[a[j][k]]);
					mn = min(mn, b[a[j][k]]);
				}
				if(mx - mn + 1 != a[j].size()) f = 1;
			}
			if(f) continue;
			for(ll j = 0; j < n; j++){
				cout << vec[j] << " ";
			}
			cout << '\n';
			break;
		}
	}
	
	return 0;
}