#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<19, mod = 1e9 + 7;
int n, m, c[maxn], t[maxn];
vi g[maxn];
vector<pair<int, int>> a;
void paint(int v) {
	for(auto i : g[v]) {
		if(c[i]) t[c[i]] = 1;
	}
	c[v] = 1;
	while(t[c[v]]) c[v]++;
	for(auto i : g[v]) {
		if(c[i]) t[c[i]] = 0;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		a.pb({t, i});
	}
	sort(all(a));
	for(int i = 0; i < n; i++) {
		paint(a[i].second);
		if(c[a[i].second] != a[i].first) return cout << -1, 0;
	}
	for(auto i : a) cout << i.second << " ";
}