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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, c[maxn], l[maxn], r[maxn], t, st, ans[maxn];
bool vis[maxn];
map<ll, ll> mp, e[maxn];
vector<ll> vec;
set<pll> g[maxn];

void tur(ll v){
	ll u = -1;
	set<pll>::iterator it = g[v].lower_bound(Mp(u, -1ll));
	while(it != g[v].end()){
		u = it -> F;
		g[u].erase(Mp(v, it -> S));
		g[v].erase(it);
		tur(u);
		it = g[v].lower_bound(Mp(u, -1ll));
	};
	vec.pb(v);
}

int main(){
	ll x;
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		r[i]++;
		vec.pb(l[i]);
		vec.pb(r[i]);
	}
	sort(vec.begin(), vec.end());
	for(ll i = 0; i < vec.size(); i++){
		if(i == 0 || vec[i] != vec[i - 1]) mp[vec[i]] = t++;
	}
	for(ll i = 0; i < n; i++){
		l[i] = mp[l[i]];
		r[i] = mp[r[i]];
		e[l[i]][r[i]] = st;
		e[r[i]][l[i]] = st++;
		g[l[i]].insert(Mp(r[i], i));
		g[r[i]].insert(Mp(l[i], i));
	}
	x = -1;
	for(ll i = 0; i < t; i++){
		if(g[i].size() % 2){
			if(x != -1) g[x].insert(Mp(i, n + 10)), g[i].insert(Mp(x, n + 10)), e[i][x] = n, e[x][i] = n, x = -1;
			else x = i;
		}
	}
	for(ll i = 0; i < n; i++){
		e[l[i]][r[i]] = i;
		e[r[i]][l[i]] = i;
	}
	for(ll j = 0; j < t; j++){
		vec.clear();
		tur(j);
		if(vec.size() > 1) vec.pb(vec[0]);
		for(ll i = 0; i + 1 < vec.size(); i++){
			if(vec[i] > vec[i + 1]) ans[e[vec[i]][vec[i + 1]]] = 1;
		}
	}
	
	for(ll i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}