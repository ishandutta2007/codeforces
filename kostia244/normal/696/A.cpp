#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<12, mod = 1e9 + 7 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll q, u, v;
map<ll, ll> cst;
ll lca(ll a, ll b) {
	if(a<b) swap(a, b);
	for(int i = 0; i < 60; i++)
		for(int j = 0;j <= i; j++)
			if((a>>i) == (b>>j)) return a>>i;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> q;
	ll c, t;
	while(q--) {
		cin >> t;
		if(t == 2) {
			cin >> u >> v;
			t = lca(u, v);
			ll ans = 0;
			while(u != t) ans += cst[u], u/=2;
			while(v != t) ans += cst[v], v/=2;
			cout << ans << '\n';
		} else {
			cin >> u >> v>> c;
			t = lca(u, v);
			while(u != t) cst[u] += c, u/=2;
			while(v != t) cst[v] += c, v/=2;
		}
	}
	return 0;
}