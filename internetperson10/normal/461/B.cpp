#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 1000000007;

vector<vector<int>> adj;
bool b[200001];
int s[200001];
ll dp[200001][2];

ll modpow(ll n, int e = 1000000005) {
	if(e == 0) return 1;
	if(e == 1) return n;
	ll x = modpow(n, e/2);
	x *= x;
	x %= MOD;
	if(e%2) {
		x *= n;
		x %= MOD;
	}
	return x;
}

ll calc(int x, int p, int t) {
	if(dp[x][t] >= 0) return dp[x][t];
	if(t == 0) {
		if(b[x]) return dp[x][t] = 0;
		ll ans = 1;
		for(int i = 0; i < adj[x].size(); i++) {
			if(adj[x][i] == p) continue;
			ans *= (calc(adj[x][i], x, 1) + calc(adj[x][i], x, 0));
			if(ans >= MOD) ans %= MOD;
		}
		return dp[x][t] = ans;
	}
	else {
		ll ans = 1;
		for(int i = 0; i < adj[x].size(); i++) {
			if(adj[x][i] == p) continue;
			ans *= (calc(adj[x][i], x, 1) + calc(adj[x][i], x, 0));
			if(ans >= MOD) ans %= MOD;
		}
		if(b[x]) return dp[x][t] = ans;
		ll ans2 = 0;
		for(int i = 0; i < adj[x].size(); i++) {
			if(adj[x][i] == p) continue;
			ll k = ans * modpow(calc(adj[x][i], x, 1) + calc(adj[x][i], x, 0));
			k %= MOD;
			k *= calc(adj[x][i], x, 1);
			ans2 += k;
			ans2 %= MOD;
		}
		return dp[x][t] = ans2;
	}
}

int dfs(int x, int p = -1) {
	int ans = 0;
	if(b[x]) ans++;
	for(int i = 0; i < adj[x].size(); i++) {
		if(adj[x][i] == p) continue;
		ans += dfs(adj[x][i], x);
	}
	return s[x] = ans;
}

int main() {
	int n;
	cin >> n;
	adj.resize(n);
	for(int i = 1; i < n; i++) {
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x) b[i] = 1;
		dp[i][0] = dp[i][1] = -1;
	}
	dfs(0);
	cout << calc(0, -1, 1) << '\n';
	// for(int i = 0; i < n; i++) {
	// 	cout << dp[i][0] << ' ' << dp[i][1] << '\n';
	// }
	// for(int i = 0; i < n; i++) cout << s[i] << ' ';
}