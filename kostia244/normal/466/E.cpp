#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1e5 + 10, mlg = 17, mod = 1e9 + 7;
int n, m, h[maxn], mx[maxn][mlg], p[maxn][mlg];
vi g[maxn];
vector<pair<int, int>> q, b;
void dfs(int v) {
	for(int i = 1; i < mlg; i++) {
		p[v][i] = p[p[v][i-1]][i-1];
		mx[v][i] = max({mx[v][i-1], mx[p[v][i-1]][i-1]});
	}
	for(auto i : g[v]) {
		h[i] = h[v] + 1;
		dfs(i);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int t, x, y, i = 0; i < m; i++) {
		cin >> t;
		if(t==1) {
			cin >> x >> y;
			g[y].pb(x);
			p[x][0] = y;
			mx[x][0] = i;
		}
		if(t==2) {
			cin >> x;
			b.pb({x, i});
		}
		if(t==3) {
			cin >> x >> y;
			q.pb({x, y-1});
		}
	}
	for(int i = 1; i <= n; i++) {
		if(p[i][0]) continue;
		h[i] = 1;
		dfs(i);
	}
	for(auto i : q) {
		int u = i.first, v = b[i.second].first;
		if(h[u]>h[v]) {
			cout << "NO\n";
			continue;
		}
		int d = h[v]-h[u], l = -1;
//		cout << b[i.second].first << " " << b[i.second].second << " " << d << "\n";
		for(int i = mlg; i--;)
			if(d&(1<<i)) {
				l = max(l, mx[v][i]);
				v = p[v][i];
//				cout << i << " " << mx[v][i] << " " << p[v][i] << " " << l << "\n";
			}
//		cout << v << " " << u << " " << l << "\n";
		if(v!=u||l>b[i.second].second) {
			cout << "NO\n";
		} else
			cout << "YES\n";
	}
	return 0;
}