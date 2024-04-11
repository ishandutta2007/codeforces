#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, lint> pi;

int par[18][200005];
lint dep[200005];
int n, a[200005], lev[200005];
vector<int> gph[200005];
int cnt[200005];

void dfs(int x){
	for(auto &i : gph[x]){
		dep[i] += dep[x];
		lev[i] = lev[x] + 1;
		dfs(i);
	}
}

void dfs2(int x){
	for(auto &i : gph[x]){
		dfs2(i);
		cnt[x] += cnt[i];
	}
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=2; i<=n; i++){
		scanf("%d %lld",&par[0][i], &dep[i]);
		gph[par[0][i]].push_back(i);
	}
	for(int i=1; i<18; i++){
		for(int j=1; j<=n; j++){
			par[i][j] = par[i-1][par[i-1][j]];
		}
	}
	dfs(1);
	for(int i=2; i<=n; i++){
		cnt[par[0][i]]++;
		int anc = i;
		for(int j=17; j>=0; j--){
			if(lev[anc] >= (1<<j) && dep[i] - dep[par[j][anc]] <= a[i]){
				anc = par[j][anc];
			}
		}
		cnt[par[0][anc]]--;
	}
	dfs2(1);
	for(int i=1; i<=n; i++){
		printf("%d ", cnt[i]);
	}
}