//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
const ll tof = 300;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, q, no, a[maxn], d[maxn];
bool isbig[maxn], o[maxn];
unordered_map<ll, bool> g[maxn], gb[maxn];
vector<pair<char, pll> > vec;


int main(){
	fast_io;
	
	cin >> n >> m >> q >> no;
	for(ll i = 0; i < no; i++){
		ll v;
		cin >> v;
		vec.pb(Mp('O', Mp(v, 0)));
	}
	for(ll i = 0; i < m; i++){
		ll v, u;
		cin >> v >> u;
		vec.pb(Mp('A', Mp(v, u)));
	}
	for(ll i = 0; i < q; i++){
		char ch;
		ll v, u;
		cin >> ch >> v;
		if(ch == 'A' || ch == 'D'){
			cin >> u;
			d[v]++;
			d[u]++;
		}
		vec.pb(Mp(ch, Mp(v, u)));
	}
	for(ll i = 1; i <= n; i++){
		isbig[i] = (d[i] > tof);
	}
	for(ll i = 0; i < vec.size(); i++){
		char ch = vec[i].F;
		ll v = vec[i].S.F, u = vec[i].S.S;
		if(ch == 'O'){
			o[v] = 1;
			if(!isbig[v]){
				for(unordered_map<ll, bool>::iterator it = g[v].begin(); it != g[v].end(); it++){
					a[it -> F]++;
				}
			}
		}
		if(ch == 'F'){
			o[v] = 0;
			if(!isbig[v]){
				for(unordered_map<ll, bool>::iterator it = g[v].begin(); it != g[v].end(); it++){
					a[it -> F]--;
				}
			}
		}
		if(ch == 'A'){
			g[v][u] = 1;
			g[u][v] = 1;
			if(isbig[v]) gb[u][v] = 1;
			else if(o[v]) a[u]++;
			if(isbig[u]) gb[v][u] = 1;
			else if(o[u]) a[v]++;
		}
		if(ch == 'D'){
			g[v].erase(u);
			g[u].erase(v);
			if(isbig[v]) gb[u].erase(v);
			else if(o[v]) a[u]--;
			if(isbig[u]) gb[v].erase(u);
			else if(o[u]) a[v]--;
		}
		if(ch == 'C'){
			ll x = a[v];
			for(unordered_map<ll, bool>::iterator it = gb[v].begin(); it != gb[v].end(); it++){
				if(o[it -> F]) x++;
			}
			cout << x << '\n';
		}
	}
	
	return 0;
}