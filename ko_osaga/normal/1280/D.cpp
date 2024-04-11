#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, lint>;
const int MAXN = 3005;
const int mod = 1e9 + 7;

int n, m, a[MAXN], sz[MAXN];
vector<int> gph[MAXN], dfn;

void dfs(int x){
	dfn.push_back(x);
	for(auto &i : gph[x]){
		gph[i].erase(find(all(gph[i]), x));
		dfs(i);
	}
}

pi dp[MAXN][MAXN];
pi aux[MAXN];

void solve_dp(){
	for(auto &i : dfn){
		sz[i] = 0;
		dp[i][0] = pi(0, 0);
		for(auto &j : gph[i]){
			fill(aux, aux + sz[i] + sz[j] + 1, pi(-1e9, -1e9));
			for(int x = 0; x <= sz[i]; x++){
				for(int y = 0; y <= sz[j]; y++){
					pi ans = pi(dp[i][x].first + dp[j][y].first, dp[i][x].second + dp[j][y].second);
					aux[x + y] = max(aux[x + y], ans);
				}
			}
			sz[i] += sz[j];
			for(int x=0; x<=sz[i]; x++) dp[i][x] = aux[x];
		}
		for(int j=0; j<=sz[i]; j++) dp[i][j].second += a[i];
		dp[i][sz[i] + 1] = pi(-1e9, -1e9);
		sz[i]++;
		for(int j=sz[i]; j; j--){
			if(i == 1) dp[i][j] = pi(-1e9, -1e9);
			if(dp[i][j-1].second > 0){
				dp[i][j] = max(dp[i][j], pi(1 + dp[i][j-1].first, 0));
			}
			dp[i][j] = max(dp[i][j], pi(dp[i][j-1].first, 0));
		}
	}
}

void solve(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		a[i] -= x;
	}
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		a[i] += x;
	}
	for(int i=1; i<n; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1);
	reverse(all(dfn));
	solve_dp();
	printf("%d\n", dp[1][m].first);
}

int main(){
	int tc = 0;
	scanf("%d",&tc);
	while(tc--){
		solve();
		for(int i=1; i<=n; i++) gph[i].clear(), a[i] = 0;
		dfn.clear();
	}
}