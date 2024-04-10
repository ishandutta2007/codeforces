#include <bits/stdc++.h>

#define int long long
#define ld long double
#define fs first
#define sc second
#define vc vector
#define pr pair
#define mp make_pair
#define pb push_back
#define len(v) (int)v.size()
#define all(v) v.begin(), v.end()

#pragma GCC optimize("Ofast")

using namespace std;

const int MAXN = 2e5 + 10;
int dp[MAXN][2];
unordered_set<int> bring[MAXN][2];
bool used[MAXN];
vc<int> g[MAXN];
vc<int> g1[MAXN];
int c[MAXN];

void dfs(int v){
	used[v] = 1;
	for (auto to : g[v]){
		if (!used[to]){
			g1[v].pb(to);
			dfs(to);
		}
	}
	if (len(g1[v]) == 0){
		dp[v][0] = 0;
		dp[v][1] = c[v];
		return;
	}
	bring[v][0].insert(-1);
	bring[v][1].insert(-1);
	int sum = 0;
	for (auto to : g1[v]){
		sum += dp[to][1];
	}
	dp[v][0] = sum;
	dp[v][1] = sum;
	for (auto to : g1[v]){
		int x = sum - dp[to][1] + dp[to][0];
		if (x < dp[v][0]){
			bring[v][0].clear();
			dp[v][0] = x;
		}
		if (x == dp[v][0]){
			bring[v][0].insert(to);
		}
		if (x + c[v] < dp[v][1]){
			bring[v][1].clear();
			dp[v][1] = x + c[v];
		}
		if (x + c[v] == dp[v][1]){
			bring[v][1].insert(to);
		}
	}
}

set<int> ans;

bool used1[MAXN][2];

void rebuild(int v, int m){
	if (used1[v][m]){
		return;
	}
	used1[v][m] = 1;
	if (len(g1[v]) == 0){
		if (m == 1){
			ans.insert(v + 1);
		}
		return;
	}
	for (auto to : g1[v]){
		if (bring[v][m].find(to) != bring[v][m].end()){
			if (m){
				ans.insert(v + 1);
			}
			rebuild(to, 0);
			if (len(bring[v][m]) == 1){
				continue;
			}
		}
		rebuild(to, 1);
	}
}

signed main(){
	#ifdef __linux__
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> c[i];
	}
	for (int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0);
	rebuild(0, 1);
	cout << dp[0][1] << ' ' << len(ans) << '\n';
	for (auto v : ans){
		cout << v << ' ';
	}
}