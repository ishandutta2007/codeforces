#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 404040, mod = 1e9 + 7, i2 = (mod+1)/2;
int n, can[maxn];
vector<int> g[maxn], cc;
int sizes(int v, int p) {
	int sz = 1, mx = 0;
	for(auto i : g[v]) if(i != p) {
		int t = sizes(i, v);
		mx = max(mx, t);
		sz += t;
	}
	if(max(mx, n-sz) <= n/2) cc.pb(v);
	return sz;
}
int C1[maxn], C2[maxn], SZ[maxn];
int build(int v, int p) {
	int &sz = SZ[v], &c1 = C1[v], &c2 = C2[v];
	sz = 1; c1 = c2 = 0;
	for(auto i : g[v]) if(i != p) {
		int t = build(i, v);
		if(t > c1) c2 = c1, c1 = t;
		else if(t > c2) c2 = t;
		sz += t;
	}
	//cout << v << " st " << sz << " " << c1 << " " << c2 << '\n';
	return sz;
}
void check(int v, int p, int t = -1) {
	int &sz = SZ[v], &c1 = C1[v], &c2 = C2[v];
	//cout << v << " " << t << " " << sz << " " << c1 << " " << c2 << '\n';
	if(n-sz-t <= n/2) can[v] = 1;
	for(auto i : g[v]) if(i != p) {
		if(t != -1) check(i, v, t);
		else check(i, v, SZ[i] == c1 ? c2 : c1);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	sizes(1, 1);
	for(auto i : cc) {
		can[i] = 1;
		build(i, i);
		check(i, i);
	}
	for(int i = 1; i <= n; i++) cout << can[i] << " ";cout << '\n';
	return 0;
}