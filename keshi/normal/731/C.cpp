//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
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

int n, m, k, c[maxn], dsu[maxn], sz[maxn], cnt[maxn];

void init(){
	for(int i = 0; i <= n; i++){
		dsu[i] = i;
		sz[i] = 1;
	}
}
int root(int v){
	if(dsu[v] != v) dsu[v] = root(dsu[v]);
	return dsu[v];
}
void Union(int v, int u){
	v = root(v);
	u = root(u);
	if(v == u) return;
	if(sz[v] < sz[u]) swap(v, u);
	dsu[u] = v;
	sz[v] += sz[u];
	return;
}

vector<int> vec[maxn];

int main(){
	fast_io;
	
	cin >> n >> m >> k;
	init();
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	for(int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		Union(v, u);
	}
	for(int i = 1; i <= n; i++){
		vec[root(i)].pb(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(vec[i].empty()) continue;
		int x = 0;
		for(int j : vec[i]){
			cnt[c[j]]++;
			x = max(x, cnt[c[j]]);
		}
		ans += Sz(vec[i]) - x;
		for(int j : vec[i]){
			cnt[c[j]] = 0;
		}
	}
	cout << ans;
	
	return 0;
}