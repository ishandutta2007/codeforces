#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;

int n, d1, d2, ansd1, ansd2, col[N], d[N], f[N];
ll c[3][N], now, ans;
vector<int> G[N];
int get(int u, int v) {
	if(u > v) swap(u, v);
	if(u == 0 && v == 1) return 2;
	if(u == 0 && v == 2) return 1;
	return 0;
}
void dfs(int u, int fa = 0) {
	d[u] = d[fa] + 1; f[u] = fa;
	if(d[u] == 1) col[u] = d1;
	else if(d[u] == 2) col[u] = d2;
	else col[u] = get(col[fa], col[f[fa]]);
	now += c[col[u]][u];
	for(int v : G[u]) if(v != fa) {
		dfs(v, u);
	}
}
void dfs2(int u, int fa = 0) {
	d[u] = d[fa] + 1; f[u] = fa;
	if(d[u] == 1) col[u] = ansd1;
	else if(d[u] == 2) col[u] = ansd2;
	else col[u] = get(col[fa], col[f[fa]]);
	for(int v : G[u]) if(v != fa) dfs2(v, u);
}
int main() {
	ucin();
	cin >> n;
	for(int j = 0; j < 3; j ++)
		for(int i = 1; i <= n; i ++) cin >> c[j][i];
	for(int i = 1, u, v; i < n; i ++) {
		cin >> u >> v; G[u].pb(v); G[v].pb(u);
	}
	int rt = 1;
	for(int i = 1; i <= n; i ++)
		if(G[i].size() >= 3) {
			cout << -1; return 0;
		} else if(G[i].size() == 1) rt = i;
	
	ans = 1e18;
	for(d1 = 0; d1 < 3; d1 ++) {
		for(d2 = 0; d2 < 3; d2 ++) if(d1 ^ d2) {
			now = 0; dfs(rt);
			if(now < ans) {
				ans = now;
				ansd1 = d1; ansd2 = d2;
			}
		}
	}
	dfs2(rt);
	cout << ans << endl;
	for(int i = 1; i <= n; i ++)
		cout << col[i] + 1 << ' ';
	return 0;
}