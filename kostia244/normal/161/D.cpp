#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define mod 1000000007ll
using namespace std;

ll ans = 0, n, l, r, k,dp[50005][505];
__V<vi> g;

void dfs(int v, int p = -1) {
	dp[v][0] = 1;
	for(auto& i : g[v]) {
		if(i == p) continue;
		dfs(i, v);
		for(int j = 1; j <= k; j++) {
			dp[v][j] += dp[i][j-1];
		}
	}
	for(auto& i : g[v]) {
		if(i == p) continue;
		for(int j = 0; k-j-1 >= 0; j++) {
			ans += (dp[v][j]-dp[i][j-1])*dp[i][k-j-1];
		}
	}
	ans += dp[v][k];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	g.resize(n + 1);
	for(int i = 1; i < n; i++)
		cin >> l >> r, g[l].pb(r), g[r].pb(l);
	dfs(1);
	cout << fixed << (ans>>1);
}