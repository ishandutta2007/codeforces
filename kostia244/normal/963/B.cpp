//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
vvi g;
vi sz, d;
void pre(int v) {
	for(auto i : g[v]) {
		pre(i);
		d[v] = max(d[v], 1+d[i]);
		sz[v] += sz[i];
	}
}
void dfs(int v) {
	for(auto i : g[v]) {
		if(sz[i]&1) continue;
		dfs(i);
	}
	cout << v << "\n";
	for(auto i : g[v]) {
		if(sz[i]&1) {
		dfs(i);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if(!(n&1))
		return cout << "NO", 0;
	g.resize(n+1);
	d.resize(n+1, 0);
	sz.resize(n+1, 1);
	int r = 0;
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		if(t) g[t].pb(i);
		else r = i;
	}
	cout << "YES\n";
	pre(r);
	dfs(r);
}