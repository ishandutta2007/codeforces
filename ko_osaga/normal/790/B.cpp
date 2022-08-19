#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

int n, k;
vector<int> gph[200005];
lint dp[200005][6], sz[200005][6], ans;

void dfs(int x, int p){
	sz[x][0] = 1;
	for(auto &i : gph[x]){
		if(i != p){
			dfs(i, x);
			for(int a=0; a<k; a++){
				for(int b=0; b<k; b++){
					ans += dp[i][a] * sz[x][b];
					ans += dp[x][b] * sz[i][a];
					if(a + b >= k) ans += sz[x][b] * sz[i][a];
					ans += sz[x][b] * sz[i][a];
				}
			}
			for(int j=0; j<k; j++){
				if(j + 1 != k){
					sz[x][j+1] += sz[i][j];
					dp[x][j+1] += dp[i][j];
				}
				else{
					sz[x][0] += sz[i][j];
					dp[x][0] += sz[i][j] + dp[i][j];
				}
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=1; i<n; i++){
		int s, e;
		scanf("%d %d",&s,&e);
		gph[s].push_back(e);
		gph[e].push_back(s);
	}
	dfs(1, -1);
	cout << ans;
}