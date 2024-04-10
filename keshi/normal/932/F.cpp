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


struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

ll n, a[maxn], b[maxn], dp[maxn], id[maxn];
vector<ll> g[maxn];
vector<pll> vec[maxn];
bool vis[maxn];
LineContainer s[maxn];

void dfs(ll v){
	vis[v] = 1;
	for(ll u : g[v]){
		if(vis[u]) continue;
		dfs(u);
		if(vec[id[v]].size() < vec[id[u]].size()){
			swap(id[v], id[u]);
		}
		for(pll x : vec[id[u]]){
			s[id[v]].add(x.F, x.S);
			vec[id[v]].pb(x);
		}
	}
	if(!vec[id[v]].empty()){
		dp[v] = -s[id[v]].query(a[v]);
	}
	vec[id[v]].pb(Mp(-b[v], -dp[v]));
	s[id[v]].add(-b[v], -dp[v]);
	return;
}

int main(){
    fast_io;


	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		id[i] = i;
	}
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(ll i = 1; i < n; i++){
		ll v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	for(ll i = 1; i <= n; i++){
		cout << dp[i] << " ";
	}

    return 0;
}