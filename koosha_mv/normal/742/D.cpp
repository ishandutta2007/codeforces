#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll W[1009],B[1009],n,m,w1,w[1009],b[1009],dp[1009],x,y,j,sumw,sumb,mark[1009];
vector<int> g[1009];
int dfs(int x){
	W[j]=w[x];B[j]=b[x];j++;sumw+=w[x];sumb+=b[x],mark[x]=1;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0)
			dfs(g[x][i]);
}}
int main(){
	cin>>n>>m>>w1;
	f(i,1,n+1) cin>>w[i];
	f(i,1,n+1) cin>>b[i];
	f(i,0,m) cin>>x>>y,g[x].pb(y),g[y].pb(x);
	f(i,1,n+1){
		if(mark[i]==0){
			j=0,sumw=0,sumb=0;
			dfs(i);
			B[j]=sumb,W[j]=sumw,j++;
			f_(k,w1,1){
				f(l,0,j){
					if(k-W[l]>=0){
						dp[k]=max(dp[k],dp[k-W[l]]+B[l]);
	}}}}}
	cout<<dp[w1];
}