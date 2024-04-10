//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, ans, a[maxn], b[maxn], c[maxn], h[maxn];
vector<ll> g[maxn];
vector<pll> vec, prs;
bool f[maxn];

void dfs(ll v){
	ll u;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		h[u] = h[v] + 1;
		dfs(u);
		if(c[u] > 0) c[v] += c[u];
		else f[u] = 1;
	}
	c[v] += a[v];
	ans += c[v];
	return;
}
void solve(ll v){
	ll u;
	vec.pb(Mp(h[v], v));
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(f[u]) continue;
		solve(u);
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
		if(b[i] != -1) g[b[i]].pb(i);
	}
	for(ll i = 1; i <= n; i++){
		if(b[i] == -1) dfs(i), f[i] = 1;
	}
	cout << ans << '\n';
	for(ll i = 1; i <= n; i++){
		if(f[i]) prs.pb(Mp(h[i], i));
	}
	sort(prs.begin(), prs.end());
	for(ll i = 0; i < prs.size(); i++){
		vec.clear();
		solve(prs[i].S);
		sort(vec.begin(), vec.end(), greater<pll>());
		for(ll j = 0; j < vec.size(); j++){
			cout << vec[j].S << " ";
		}
	}
	
	return 0;
}