#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
int n, m;
ll k;
vi a;
vvi g1;
vvi g;
vi c;
bool cicle;
vi dp;


void dfs1(int v) {
	c[v] = 0;
	for(int u : g[v]) {
		if(c[u] == -1) {
			dfs1(u);
		} else if(c[u] == 0) {
			cicle = true;
		}
	}
	c[v] = 1;
}

void dfs(int v) {
	if(dp[v] != -1) return;
	for(int u : g[v]) dfs(u);
	dp[v] = 0;
	for(int u : g[v]) {
		dp[v] = max(dp[v], dp[u] + 1);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m >> k;
	a.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	g1.resize(n);
	for(int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		--v;
		--u;
		g1[v].push_back(u);
	}
	int l = 0;
	int r = 1000000001;
	while(r - l > 1) {
		int mid = ((ll)l + r) / 2;
		g.assign(n, {});
		for(int i = 0; i < n; i++) {
			if(a[i] > mid) continue;
			for(const auto& j : g1[i]) {
				if(a[j] > mid) continue;
				g[i].push_back(j);
			}
		}
		cicle = false;
		c.assign(n, -1);
		for(int i = 0; i < n; i++) {
			if(c[i] == -1 && a[i] <= mid) {
				dfs1(i);
			}
		}
		if(cicle) {
			r = mid;
			continue;
		}
		dp.assign(n, -1);
		int ans = -1;
		for(int i = 0; i < n; i++) {
			if(a[i] > mid) continue;
			dfs(i);
			ans = max(ans, dp[i]);
		}
		if(ans >= k - 1) {
			r = mid;
		} else {
			l = mid;
		}
	}
	if(r == 1000000001) {
		cout << -1;
	} else {
		cout << r;
	}
}