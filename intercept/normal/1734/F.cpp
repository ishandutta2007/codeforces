#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
ll n,m;
ll dp[69][2][69][2][2];
ll dfs(int st,int up,int l,int o,int t){
	
	if(st==-1)return o!=t;
	if(dp[st][up][l][o][t]!=-1)return dp[st][up][l][o][t];
	int nu=up?(m>>st&1):1;
	int x=n>>st&1;
	ll ans=0;
	for(int i=0;i<=nu;++i){
		ans+=dfs(st-1,up&(i==nu),(x^i)?l+1:0,o^((x^i)?1:(x?(l+1)%2:0)),t^i);
	}
	return dp[st][up][l][o][t]=ans;
}
void work(){
	cin>>n>>m;
	m--;
	memset(dp,-1,sizeof(dp));
	cout<<dfs(60,1,0,0,0)<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
5 10
*/