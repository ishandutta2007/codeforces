//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, q[maxn], l, r;

vector<ll> a[maxn], td, adj[maxn];

set<ll> s;

int main(){
	ll v, u;
	
	scanf("%i %i", &n, &m);
	
	for(ll i = 0; i < m; i++){
		scanf("%i %i", &v, &u);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	for(ll i = 1; i <= n; i++){
		sort(adj[i].begin(), adj[i].end());
		s.insert(i);
	}
	
	for(ll i = 1; i <= n; i++){
		if(s.find(i) != s.end()){
			q[l] = i;
			r = l;
			s.erase(i);
			while(l <= r){
				td.clear();
				v = q[l++];
				a[t].pb(v);
				for(set<ll>::iterator it = s.begin(); it != s.end(); it++){
					if(adj[v].empty() || *lower_bound(adj[v].begin(), adj[v].end(), *it) != *it) td.pb(*it);
				}
				for(ll i = 0; i < td.size(); i++){
					q[++r] = td[i];
					s.erase(td[i]);
				}
			}
			t++;
		}
	}
	
	printf("%i \n", t);
	
	for(ll i = 0; i < t; i++){
		printf("%u ", a[i].size());
	    for(ll j = 0; j < a[i].size(); j++){
			printf("%i ", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}