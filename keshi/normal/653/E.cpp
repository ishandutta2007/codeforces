//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, d[maxn], t;

bool f;

map<ll, bool> mp[maxn];

set<ll> s;

void dfs(ll v){
	ll u;
	if(!mp[1][v]) f = 1;
	s.erase(v);
	set<ll>::iterator it = s.begin();
	while(it != s.end()){
		u = *it;
		if(!mp[v][u]){
			dfs(u);
		}
		it = s.upper_bound(u);
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m >> k;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		mp[v][u] = 1;
		mp[u][v] = 1;
		d[v]++;
		d[u]++;
	}
	
	for(ll i = 2; i <= n; i++){
		s.insert(i);
	}
	
	for(ll i = 2; i <= n; i++){
		if(s.find(i) != s.end()){
			t++;
			f = 0;
			dfs(i);
			if(!f){
				cout << "impossible";
				return 0;
			}
		}
	}
	
	if(t > k || n - 1 - d[1] < k) cout << "impossible";
	else cout << "possible";
	
	return 0;
}