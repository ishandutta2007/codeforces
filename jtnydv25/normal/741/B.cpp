#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1005;
int dp[N], olddp[N], vis[N], W[N], B[N], sm = 0;
vector<int> con[N];

inline void go(int w, int b){
	for(int i = 0; i < N; i++){
		if(i + w < N){
			dp[i + w] = max(dp[i + w], olddp[i] + b);
		}
	}
}
int smW, smB;
void dfs(int s){
	smW += W[s];
	smB += B[s];
	vis[s] = 1;
	go(W[s], B[s]);
	for(int v : con[s])
		if(!vis[v]) dfs(v);
}
int main(){
	int n, m, w, u, v;
	scanf("%d %d %d", &n, &m, &w);
	for(int i = 1; i <= n; i++) scanf("%d", &W[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &B[i]);
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &u, &v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			memcpy(olddp, dp, sizeof dp);
			// memset(dp, 0, sizeof dp);
			smW = smB = 0;
			dfs(i);
			go(smW, smB);
		}
	}

	printf("%d\n", dp[w]);
}