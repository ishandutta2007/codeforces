//In the name of GOD
//Global Round just dont make me blue :)
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

ll n, m;

map<ll, ll> mp[maxn];

map<ll, bool> vis[maxn];

vector<ll> gin[maxn], gout[maxn];

vector<pll> ans;

int main(){
	ll v, u, c, p1, p2;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u >> c;
		gout[v].pb(u);
		gin[u].pb(v);
		mp[v][u] += c;
	}
	
	for(ll i = 1; i <= n; i++){
		p1 = 0;
		p2 = 0;
		while(p1 < gin[i].size() && p2 < gout[i].size()){
			v = gin[i][p1];
			u = gout[i][p2];
			if(mp[v][i] == 0 || v == i){
				mp[v][i] = 0;
				p1++;
				continue;
			}
			if(mp[i][u] == 0 || i == u){
				mp[i][u] = 0;
				p2++;
				continue;
			}
			if(mp[v][i] >= mp[i][u]){
				mp[v][i] -= mp[i][u];
				mp[v][u] += mp[i][u];
				mp[i][u] = 0;
				gout[v].pb(u);
				gin[u].pb(v);
				p2++;
			}
			else{
				mp[i][u] -= mp[v][i];
				mp[v][u] += mp[v][i];
				mp[v][i] = 0;
				gout[v].pb(u);
				gin[u].pb(v);
				p1++;
			}
		}
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < gout[i].size(); j++){
			v = gout[i][j];
			if(!vis[i][v] && mp[i][v] > 0 && i != v){
				ans.pb({i, v});
				vis[i][v] = 1;
			}
		}
	}
	
	cout << ans.size() << '\n';
	
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i].F << " " << ans[i].S << " " << mp[ans[i].F][ans[i].S] << '\n';
	}
	
	return 0;
}