#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;
ll m, k;
vector<vector<int>> adj;
ll dp[100001][11][3];
int g = 0;

ll calc(int x, int v, int s, int p = -1) {
	// for(int i = 0; i < g; i++) cout << "  ";
	// cout << "Now at " << x << ' ' << v << ' ' << s << "\n";
	if(dp[x][v][s] >= 0) return dp[x][v][s];
	bool sad = true;
	ll arr[11], arr2[11];
	if(s == 0) { // vault < k
		if(k == 1) {
			return dp[x][v][s] = 0;
		}
		for(int i = 0; i <= v; i++) arr[i] = 0;
		arr[0] = k-1;
		for(int i = 0; i < adj[x].size(); i++) {
			if(adj[x][i] == p) continue;
			for(int j = 0; j <= v; j++) {
				sad = false;
				arr2[j] = 0;
				for(int l = 0; l <= j; l++) {
					arr2[j] += (arr[l] * (calc(adj[x][i], j-l, 0, x) + calc(adj[x][i], j-l, 1, x) + calc(adj[x][i], j-l, 2, x))%MOD);
					arr2[j] %= MOD;
				}
			}
			for(int j = 0; j <= v; j++) arr[j] = arr2[j];
		}
	}
	else if(s == 1) { // vault = k
		if(v == 0) {
			return dp[x][v][s] = 0;
		}
		for(int i = 0; i <= v; i++) arr[i] = 0;
		arr[1] = 1;
		for(int i = 0; i < adj[x].size(); i++) {
			if(adj[x][i] == p) continue;
			for(int j = 0; j <= v; j++) {
				sad = false;
				arr2[j] = 0;
				for(int l = 0; l <= j; l++) {
					calc(adj[x][i], j-l, 0, x);
					arr2[j] += arr[l] * calc(adj[x][i], j-l, 0, x);
					arr2[j] %= MOD;
				}
			}
			for(int j = 0; j <= v; j++) arr[j] = arr2[j];
		}
	}
	else { // vault > k
		if(k == m) {
			return dp[x][v][s] = 0;
		}
		for(int i = 0; i <= v; i++) arr[i] = 0;
		arr[0] = m - k;
		for(int i = 0; i < adj[x].size(); i++) {
			if(adj[x][i] == p) continue;
			for(int j = 0; j <= v; j++) {
				sad = false;
				arr2[j] = 0;
				for(int l = 0; l <= j; l++) {
					calc(adj[x][i], j-l, 0, x);
					calc(adj[x][i], j-l, 2, x);
					arr2[j] += arr[l] * (calc(adj[x][i], j-l, 0, x) + calc(adj[x][i], j-l, 2, x))%MOD;
					arr2[j] %= MOD;
				}
			}
			for(int j = 0; j <= v; j++) arr[j] = arr2[j];
		}
	}
	ll ans = arr[v];
	if(sad && (v - (s%2) > 0)) {
		ans = 0;
	}
	// cout << "Returned " << x << ' ' << v << ' ' << s << ' ' << ans << '\n';
	return dp[x][v][s] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> m;
	adj.resize(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 11; j++) {
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
		}
	}
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int x;
	cin >> k >> x;
	ll ans = 0;
	for(int i = 0; i <= x; i++) {
		for(int j = 0; j < 3; j++) {
			ans += calc(0, i, j);
			ans %= MOD;
		}
	}
	cout << ans << '\n';
	return 0;
}