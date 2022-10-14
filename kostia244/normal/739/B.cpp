#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<18, mlg = 18, rt = 1<<10, mod = 1e9 + 7;
ll n, a[maxn], p[maxn][mlg], w[maxn][mlg], x[maxn], ans[maxn];
vi g[maxn];
int dfs(int v = 1) {
	int cs = 0;
	for(auto i : g[v]) {
		cs += dfs(i);
	}
	ans[v] = cs;
	return cs + x[v];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	p[1][0] = 1, w[1][0] = 1;
	for(int i = 2; i <= n; i++) cin >> p[i][0] >> w[i][0], g[p[i][0]].pb(i);
	for(int z = 1; z < mlg; z++) {
		for(int i = 1; i <= n; i++) {
			p[i][z] = p[p[i][z-1]][z-1];
			w[i][z] = w[i][z-1] + w[p[i][z-1]][z-1];
		}
	}
	for(int i = 1; i <= n; i++) {
		int v = i, t = a[i];
		for(int z = mlg; z--;) if(w[v][z] <= t) {
			t -= w[v][z];
			v = p[v][z];
		}
		x[v]--;
		x[i]++;
	}
	dfs();
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';cout << '\n';
}