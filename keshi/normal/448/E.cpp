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

ll n, x, k, t, b, c, a[maxn];
vector<ll> g[maxn];

void solve(ll v, ll h){
	if(h == 0){
		cout << a[v] << " ";
		t++;
		return;
	}
	cout << "1 ";
	t++;
	for(ll i = 0; i < g[v].size(); i++){
		if(t == 100000) return;
		solve(g[v][i], h - 1);
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> x >> k;
	for(ll i = 1; i * i <= x; i++){
		if(x % i == 0){
			c++;
			if(i * i != x) c++;
		}
	}
	b = c;
	for(ll i = 1; i * i <= x; i++){
		if(x % i == 0){
			a[t++] = i;
			a[--b] = x / i;
		}
	}
	for(ll i = 0; i < c; i++){
		for(ll j = 1; j < c; j++){
			if(a[i] % a[j] == 0) g[i].pb(j);
		}
	}
	t = 0;
	solve(c - 1, k);
	
	return 0;
}