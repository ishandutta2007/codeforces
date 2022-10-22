#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e6+9;
int n,m,sz;
int c[M][26],b[M],dp[M],L[M],R[M];
bool vis[M];
void solve(int u,int z){
	if(vis[u])sz++,dp[u]=min(dp[u],z+sz);
	z=min(z,dp[u]-(sz-vis[u]));
	for(int i=0;i<26;++i){
		if(c[u][i]){
			dp[c[u][i]]=dp[u]+1;
			solve(c[u][i],z);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		int p;
		char s[5];
		cin>>p>>s;
		c[p][s[0]-'a']=i;
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>b[i];
		vis[b[i]]=1;
	}
	solve(0,0);
	for(int i=1;i<=m;++i){
		cout<<dp[b[i]]<<" \n"[i==m];
	}
	return 0;
}