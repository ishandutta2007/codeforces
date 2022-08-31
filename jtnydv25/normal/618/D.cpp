#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 100;
vector<int> con[N];
int dp1[N], dp[N];

void dfs(int s, int p){
	int cnt = 0;
	int x = 0;
	for(int v : con[s]) if(v != p){
		dfs(v, s);
		x += dp[v];
		cnt++;
	}
	
	if(!cnt){
		dp1[s] = dp[s] = 1;
		return;
	}
	dp1[s] = x + 1;
	for(int v : con[s]){
		if(v != p){
			dp1[s] = min(dp1[s], x + dp1[v] - dp[v]);
		}
	}
	dp[s] = dp1[s];
	int mn1 = N, mn2 = N;
	for(int v : con[s]){
		if(v != p){
			if(dp1[v] - dp[v] <= mn1){
				mn2 = mn1;
				mn1 = dp1[v] - dp[v];
			}
			else if(dp1[v] - dp[v] < mn2){
				mn2 = dp1[v] - dp[v];
			}
		}
	}
	dp[s] = min(dp[s], x + mn1 + mn2 - 1);
}
int main(){
	int n, a, b, x, y;
	scanf("%d %d %d", &n, &x, &y);
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		con[a].push_back(b);
		con[b].push_back(a);
	}
	if(x >= y){
		for(int i = 1; i <= n; i++){
			if(con[i].size() == n - 1){
				printf("%lld", x + (n - 2) * 1ll * y);
				return 0;
			}
		}
		printf("%lld\n", (n - 1) * 1ll * y);
	}	
	else{
		dfs(1, 0);
		int num = n - dp[1];
		printf("%lld", num * 1ll * x + (n - 1 - num) * 1ll * y);
	}
}