#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

int n, m, w, cst[1005], val[1005];
int dp[1005];
int vis[1005];
vector<int> gph[1005], v;

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	v.push_back(x);
	for(auto &i : gph[x]) dfs(i);
}

int main(){
	cin >> n >> m >> w;
	for(int i=1; i<=n; i++) cin >> cst[i];
	for(int i=1; i<=n; i++) cin >> val[i];
	for(int i=1; i<=m; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			v.clear();
			dfs(i);
			vector<pi> lis;
			int t1 = 0, t2 = 0;
			for(auto &j : v){
				lis.push_back(pi(cst[j], val[j]));
				t1 += cst[j];
				t2 += val[j];
			}
			lis.push_back(pi(t1, t2));
			int ndp[1005] = {};
			for(int j=0; j<=w; j++){
				ndp[j] = dp[j];
				for(auto &k : lis){
					if(k.first <= j){
						ndp[j] = max(ndp[j], dp[j-k.first] + k.second);
					}
				}
			}
			for(int j=0; j<=w; j++) dp[j] = ndp[j];
		}
	}
	cout << dp[w];
}