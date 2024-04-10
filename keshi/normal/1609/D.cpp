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

ll n, m, sz[maxn], dsu[maxn], ans, s, x;

set<pll> st;

void rem(ll v){
	auto it = st.lower_bound(Mp(-sz[v], v));
	auto it2 = st.lower_bound(Mp(-sz[x], x));
	if(*it2 < *it){
		st.erase(it);
		return;
	}
	s -= -(it -> F);
	st.erase(it);
	it = st.upper_bound(Mp(-sz[x], x));
	s += -(it -> F);
	x = (it -> S);
	return;
}
void add(ll v){
	auto it2 = st.lower_bound(Mp(-sz[x], x));
	if(*it2 < Mp(-sz[v], v)){
		st.insert(Mp(-sz[v], v));
		return;
	}
	s -= -(it2 -> F);
	s += sz[v];
	st.insert(Mp(-sz[v], v));
	it2 = st.lower_bound(Mp(-sz[x], x));
	it2--;
	x = (it2 -> S);
}

void init(){
	for(ll i = 0; i <= n; i++){
		dsu[i] = i;
		sz[i] = 1;
		st.insert(Mp(-1, i));
	}
}
ll root(ll v){
	if(dsu[v] != v) dsu[v] = root(dsu[v]);
	return dsu[v];
}
bool Union(ll v, ll u){
	v = root(v);
	u = root(u);
	if(v == u) return 0;
	if(sz[v] < sz[u]) swap(v, u);
	rem(v);
	dsu[u] = v;
	sz[v] += sz[u];
	add(v);
	rem(u);
	return 1;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	init();
	x = (st.begin() -> S);
	s = sz[x];
	for(ll i = 0; i < m; i++){
		ll v, u;
		cin >> v >> u;
		if(!Union(v, u)){
			auto it = st.upper_bound(Mp(-sz[x], x));
			s += -(it -> F);
			x = (it -> S);
		}
		cout << s - 1 << "\n";
	}
	
	return 0;
}