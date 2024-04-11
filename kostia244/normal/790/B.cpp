#pragma GCC optimize("trapv")
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 2e5 + 55;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using pi = pair<ll, ll>;
ll n, k;
vector<vi> g;
pi dp[maxn][5];
pi cnt[maxn][5];
ll ans = 0;
void dfs(int v, int p) {
	for(int i = 0; i < 5; i++) cnt[v][i] = {0, 0};
	dp[v][0].first = 1;
	for(auto i : g[v]) {
		if(i==p) continue;
		dfs(i, v);
		for(int q = 0; q < k; q++) {
			for(int j = 0; j < k; j++) {
				cnt[v][(q+j+1)%k].first += dp[v][q].first*dp[i][j].first;
				if(dp[v][q].first*dp[i][j].first) {
				cnt[v][(q+j+1)%k].second += dp[v][q].first*dp[i][j].first + dp[v][q].first*dp[i][j].second + dp[v][q].second*dp[i][j].first;
//					cout << v << " " << q << " " << i << " " << j << " " << dp[v][q].first << " " << dp[v][q].second << " " << dp[i][j].first << " " << dp[i][j].second << "\n";
				}
			}
		}

		for(int j = 0; j < k; j++) {
			dp[v][(j+1)%k].first += dp[i][j].first;
			dp[v][(j+1)%k].second += dp[i][j].second + dp[i][j].first;
		}
	}
//	ans = 0;
//	cout << v << "\n";
//	cout << v << " " << ans << "\n";
	for(int i = 0; i < k; i++) {
//		cout << cnt[v][i].first <<  " " << cnt[v][i].second << "q\n";
		if(i) {
			ans += cnt[v][i].first + (cnt[v][i].second - i*cnt[v][i].first)/k;
		} else {
			ans += cnt[v][i].second/k;
		}
	}
//	cout << v << " " << ans << "v\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	g.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs(1, 1);
	cout << ans;
}