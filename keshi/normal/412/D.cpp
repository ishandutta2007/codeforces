//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 3e4 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn];

set<ll> s;

bitset<maxn> c[maxn];

vector<ll> v[maxn];

void solve(ll x, ll f){
	if(v[x].empty()){
		s.insert(x);
		return;
	}
	ll d = 0, k = 0, h = 0, p = 0, l, t;
	a[f] = v[x][0];
	t = *s.begin();
	s.erase(s.begin());
	l = *s.begin();
	s.erase(s.begin());
	for(ll i = 1; i < v[x].size(); i++){
		if(c[v[x][0]][v[x][i]]){
			k++;
		}
		else if(c[v[x][i]][v[x][0]]){
			d++;
		}
		else{
			h++;
		}
	}
	if(d < k){
		ll o = max(k - d, h);
		h -= o;
		d += o;
	}
	if(k < d){
		ll o = max(d - k, h);
		h -= o;
		k += o;
		p += o;
	}
	k += h / 2;
	p += h / 2;
	d += (h + 1) / 2;
	for(ll i = 1; i < v[x].size(); i++){
		if(c[v[x][0]][v[x][i]]){
			v[t].pb(v[x][i]);
		}
		else if(c[v[x][i]][v[x][0]]){
			v[l].pb(v[x][i]);
		}
		else{
			if(p){
				v[t].pb(v[x][i]);
				p--;
			}
			else{
				v[l].pb(v[x][i]);
			}
		}
	}
	a[f + v[t].size()] = v[x][0];
	v[x].clear();
	s.insert(x);
	f += v[t].size();
	solve(t, f - v[t].size());
	solve(l, f + 1);
	return;
}

int main(){
	ll g, u;
	fast_io;

	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		cin >> g >> u;
		c[g][u] = 1;
	}
	for(ll i = 1; i <= n; i++){
		v[0].pb(i);
	}

	for(ll i = 1; i < maxn; i++){
        s.insert(i);
	}

	solve(0, 0);

	for(ll i = 0; i < n; i++){
		cout << a[i] << " ";
	}

	return 0;
}