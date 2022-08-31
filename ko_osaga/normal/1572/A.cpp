#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;

void solve(){
	int n; scanf("%d",&n);
	vector<vector<int>> gph(n + 1);
	vector<vector<int>> rev(n + 1);
	vector<int> indeg(n + 1);
	for(int i = 1; i <= n; i++){
		int v; 
		scanf("%d",&v);
		for(int j = 0; j < v; j++){
			int k; scanf("%d",&k);
			gph[k].push_back(i);
			rev[i].push_back(k);
			indeg[i]++;
		}
	}
	queue<int> que;
	vector<int> dp(n + 1);
	fill(all(dp), 1e9);
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		if(indeg[i] == 0){
			que.push(i);
		}
	}
	vector<int> ord;
	while(sz(que)){
		int x = que.front(); que.pop();
		ord.push_back(x);
		dp[x] = 1;
		for(auto &j : rev[x]){
			dp[x] = max(dp[x], dp[j] + (j > x));
		}
		for(auto &j : gph[x]){
			indeg[j]--;
			if(indeg[j] == 0){
				que.push(j);
			}
		}
	}
	int ans = *max_element(all(dp));
	if(ans > 1e8) ans = -1;
	printf("%d\n", ans);
}

int main(){
	int tc; scanf("%d",&tc);
	for(int i = 1; i <= tc; i++){
		solve();
	}
}