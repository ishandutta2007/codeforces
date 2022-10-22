#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=2e5+9;
int n,k,ans=0;
int dp[M];
vector<int>g[M];
void dfs(int u,int fa,int x){
	dp[u]=1;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u,x);
			dp[u]=max(dp[u],dp[v]+1);
		}
	}
	if(dp[u]==x&&u!=1&&fa!=1)ans++,dp[u]=0;
}
bool check(int x){
	ans=0;
	dfs(1,0,x);
	return ans<=k;
}
void work(){
	cin>>n>>k;
	for(int i=1;i<=n;++i)g[i].clear();
	for(int i=2;i<=n;++i){
		int u,v;
		cin>>u;
		v=i;
		g[u].eb(v);
		g[v].eb(u);
	}
	int l=1,r=n-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
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
5 2
1 1 2 2



1000000000
0010000000
0010000000
0000001000
0001000000
0100000000
0000010000
0000000010
*/