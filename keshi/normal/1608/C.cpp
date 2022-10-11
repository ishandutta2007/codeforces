//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

ll t, n, vis[maxn], ok[maxn];
pll a[maxn], b[maxn];
vector<ll> g[maxn], gp[maxn];
vector<ll> vec;

void dfs(ll v){
	vis[v] = 1;
	for(ll u : g[v]){
		if(!vis[u]) dfs(u);
	}
	vec.pb(v);
}
void sfd(ll v){
	ok[v] = 1;
	for(ll u : gp[v]){
		if(!ok[u]) sfd(u);
	}
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a[i].F;
			a[i].S = i;
			g[i].clear();
			gp[i].clear();
			vis[i] = 0;
			ok[i] = 0;
		}
		for(ll i = 0; i < n; i++){
			cin >> b[i].F;
			b[i].S = i;
		}
		sort(a, a + n);
		sort(b, b + n);
		for(ll i = 1; i < n; i++){
			g[a[i].S].pb(a[i - 1].S);
			gp[a[i - 1].S].pb(a[i].S);
			g[b[i].S].pb(b[i - 1].S);
			gp[b[i - 1].S].pb(b[i].S);
		}
		vec.clear();
		for(ll i = 0; i < n; i++){
			if(!vis[i]) dfs(i);
		}
		ll v = vec.back();
		sfd(v);
		for(ll i = 0; i < n; i++){
			cout << ok[i];
		}
		cout << "\n";
	}
	
	return 0;
}