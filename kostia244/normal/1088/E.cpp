#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
//const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vvi g;
vi a;
vi tst;
ll mx = LLONG_MIN, cnt = 0;
ll dfs(int v, int p) {
	ll t = a[v];

	for(auto i : g[v]) {
		if(i == p) continue;
		t += max(0ll, dfs(i, v));
	}
	if(mx==t)cnt++, t = 0;
	return t;
}
ll dfsa(int v, int p) {
	ll t = a[v];
	for(auto i : g[v]) {
		if(i == p) continue;
		t += max(0ll, dfsa(i, v));
	}
	if(mx < t) mx=t;
	return t;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	a.resize(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	g.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfsa(1, 1);
	dfs(1, 1);
	cout << mx*cnt << " " << cnt << "\n";
}