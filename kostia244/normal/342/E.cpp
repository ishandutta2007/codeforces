#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 696969569;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, dp[21][100100], h[100100], ans[100100], bl[100100];
vvi g;
void dep(int v, int p) {
	dp[0][v] = p;
	for (int i = 1; i < 17; i++)
		dp[i][v] = dp[i - 1][dp[i - 1][v]];
	for (auto i : g[v]) {
		if (i == p)
			continue;
		h[i] = h[v] + 1;
		dep(i, v);
	}
}
void bfs() {
	queue<int> x;
	for(int i = 1; i <= n; i ++) {
		if(bl[i])
			x.push(i), ans[i]=0;
		else
			ans[i]=n+10;
	}
	while(!x.empty()) {
		int u = x.front();
		x.pop();
		for(auto v : g[u]) {
			if(ans[u]+1<ans[v]) {
				ans[v] = ans[u]+1;
				x.push(v);
			}
		}
	}
}
int dist(int u, int v) {
	if (h[u] < h[v])
		swap(u, v);
	int ans = h[u] - h[v];
	if (h[u] != h[v]) {
		for (int i = 16; i >= 0; i--)
			if (ans&(1<<i))
				u = dp[i][u];
	}
	if (u == v)
		return ans;
	for (int i = 16; i >= 0; i--)
		if (dp[i][u] != dp[i][v])
			ans += (2 << i), u = dp[i][u], v = dp[i][v];
	return ans+2;
}
vi buff;
int get(int y) {
	int x = ans[y];
	for(auto i : buff)
		x = min(x, dist(y, i));
	return x;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	bl[1] = 1;
	for (int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dep(1, 0);
	bfs();
	for (int x, y, i = 0; i < m; i++) {
		cin >> x >> y;
		if (x == 1)
			buff.pb(y);
		else
			cout << get(y) << "\n";
		if (buff.size() == 256) {
			for (auto i : buff)
				bl[i] = 1;
			bfs(), buff.clear();
		}
	}
}