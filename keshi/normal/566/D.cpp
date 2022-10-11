#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;

#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dsu[maxn], sz[maxn], q, t, m[maxn], l;

bool s[maxn];

ll par(ll v){
	if(v == dsu[v]) return v;
	dsu[v] = par(dsu[v]);
	return dsu[v];
}

void Union(ll v, ll u){
	ll x, y;
	x = par(v);
	y = par(u);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x, y);
	dsu[y] = x;
	sz[x] += sz[y];
	return;
}

int main(){
	ll v, u;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	//naive
	
	cin >> n >> q;
	
	for(ll i = 1; i <= n; i++){
		dsu[i] = i;
		m[i] = i;
		sz[i] = 1;
	}
	
	while(q--){
		cin >> t >> v >> u;
		if(t == 1){
			Union(v, u);
		}
		else if(t == 2){
			for(ll i = v; i < u; i++){
				if(s[i]){
				    l = m[i];
				    m[i] = max(m[i], u);
				    i = l;
				}
				if(i >= u) continue;
				s[i] = 1;
				Union(i, u);
				m[i] = max(m[i], m[u]);
			}
		}
		else{
			if(par(v) == par(u)) cout << "YES";
			else cout << "NO";
			cout << '\n';
		}
	}
	
	return 0;
}