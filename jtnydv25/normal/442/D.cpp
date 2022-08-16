#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int par[N], dp[N];
pair<int, int> mx1[N], mx2[N];
void upd(int i, int j, int v){
	if(mx1[i].first == j){
		mx1[i] = {j, v};
		return;
	}
	if(v <= mx2[i].second) return;
	if(v < mx1[i].second){
		mx2[i] = {j, v};
		return;
	}
	mx2[i] = mx1[i];
	mx1[i] = {j, v};
}
int ans = 0;
bool upd2(int i, int child){
	int olddp = dp[i];
	int mx = 0, cnt = 0;
	upd(i, child, dp[child]);
	dp[i] = max(mx1[i].second, mx2[i].second + 1);
	if(par[i] == 1){
		ans = max(ans, dp[i]);
	}
	return dp[i] != olddp;
}

void update(int i, int p){
	par[i] = p;
	dp[i] = 1;
	int lst = i;
	i = p;
	if(p == 1) ans = max(ans, 1);
	while(i != 1){
		if(!upd2(i, lst)) break;
		lst = i;
		i = par[i];
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < N; i++) mx1[i] = mx2[i] = {-1, -1};
	for(int i = 1; i <= n; i++){
		int p;
		scanf("%d", &p);
		update(i + 1, p);
		printf("%d ", ans);
	}
}