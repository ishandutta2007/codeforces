#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 33, mlg = 17, mod = 1e9 + 7;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, m, q;
vector<vi> g, r;
int tin[maxn], tout[maxn], anc[maxn][mlg], ans[maxn][mlg][10], timer = 0;
void calc(int x, int u, int y, int v, int z, int t) {
	int a = 0, b = 0;
	for(int i = 0; i < 10; i++) {
		if(ans[x][u][a]>m&&ans[y][v][b]>m) break;
		if(ans[x][u][a] < ans[y][v][b]) {
			ans[z][t][i] = ans[x][u][a++];
		} else {
			ans[z][t][i] = ans[y][v][b++];
		}
	}
}
void dfs(int v, int p) {
	tin[v] = timer++;
	anc[v][0] = p;
	for(int i = 0; i < r[v].size(); i++) ans[v][0][i] = r[v][i];
	for(int i = 1; i < mlg; i++) {
		anc[v][i] = anc[anc[v][i-1]][i-1];
		calc(v, i-1, anc[v][i-1], i-1, v, i);
	}
	for(auto i : g[v]) {
		if(i==p) continue;
		dfs(i, v);
	}
	tout[v] = timer;
}
bool isAnc(int u, int v) {
	return tin[u] <= tin[v] && tin[v] < tout[u];
}
int lca(int a, int b) {
	if(isAnc(a, b)) return a;
	if(isAnc(b, a)) return b;
	for(int i = mlg; i--;)
		if(anc[a][i]&&!isAnc(anc[a][i], b))
			a = anc[a][i];
	return anc[a][0];
}
void get(int x, int y, int a) {
	int z = lca(x, y);
	int tx = x;
	int cur = 100001, nxt = 100002;
	memset(ans[cur][0], 0x3, sizeof ans[cur][0]);
	for(int i = mlg; i--;)
		if(anc[tx][i]&&isAnc(z, anc[tx][i])) {
//			cout << tx << " - " << i << "\n";
			memset(ans[nxt][0], 0x3, sizeof ans[nxt][0]);
			calc(cur, 0, tx, i, nxt, 0);
			tx = anc[tx][i];
			swap(cur, nxt);
		}
	tx = y;
	for(int i = mlg; i--;)
		if(anc[tx][i]&&isAnc(z, anc[tx][i])) {
//			cout << tx << " - " << i << "\n";
			memset(ans[nxt][0], 0x3, sizeof ans[nxt][0]);
			calc(cur, 0, tx, i, nxt, 0);
			tx = anc[tx][i];
			swap(cur, nxt);
		}
	vi res;
	memset(ans[nxt][0], 0x3, sizeof ans[nxt][0]);
	calc(cur, 0, z, 0, nxt, 0);
	swap(cur, nxt);
	for(int i  = 0; i < a; i++)
		if(ans[cur][0][i] <= m)
			res.pb(ans[cur][0][i]);
		else break;
	cout << res.size() << " ";for(auto i : res) cout << i << " ";cout << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(ans, 0x3, sizeof ans);
	cin >> n >> m >> q;
	g.resize(n+1);
	r.resize(n+1);

	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	for(int c, i= 1; i <= m; i++) {
		cin >> c;
		if(r[c].size()<10)
		r[c].pb(i);
	}
	dfs(1, 0);
	for(int f, t, a, i = 0; i < q; i++) {
		cin >> f >> t >> a;
		get(f, t, a);
	}
}