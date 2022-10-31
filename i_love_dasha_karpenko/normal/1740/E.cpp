#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define div dsfd
typedef long long ll;
const int N = 1e5+7;
vector<int> G[N];
ll dp[N][2];
void dfs(int v){
	for(int to:G[v]){
		dfs(to);
		dp[v][0] += max(dp[to][1],dp[to][0]);
		dp[v][1] = max(dp[v][1],dp[to][1]);
	}
	dp[v][1] += 1;
}
void solve(){
	int n;
	cin>>n;
	for(int i = 2;i<=n;i+=1){
		int par;
		cin>>par;
		G[par].push_back(i);
	}
	dfs(1);
	//cout<<"GDB "<<dp[2][0]<<' '<<dp[2][1]<<endl;
	cout<<max(dp[1][0],dp[1][1])<<endl;
}
signed main(){

	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
//	cin>>t;
	while(t--){
		solve();
	}
}