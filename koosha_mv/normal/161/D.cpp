#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll n,x,y,mark1[50099],mark2[50099],dp[50099][503],k,ans=0;
vector<int>g[50003];
int dp1(int x){
	mark1[x]=1;dp[x][0]=1;
	f(i,0,g[x].size()){
		if(mark1[g[x][i]]==0){
			dp1(g[x][i]);
			f(j,0,k){
				dp[x][j+1]+=dp[g[x][i]][j];}}}
}
int dfs(int x){
	int sum=0;mark2[x]=1;
	f(i,0,k/2+1){
		if(i==k/2 && k%2==0) sum+=((dp[x][i]*(dp[x][k-i]))-dp[x][i])/2+dp[x][i];	
		else sum+=dp[x][i]*dp[x][k-i];
	}
	f(i,0,g[x].size()){
		if(mark2[g[x][i]]==0){
			f(j1,0,k/2){
				if(j1==k/2-1 && k%2==0) sum-=(dp[g[x][i]][j1]*(dp[g[x][i]][j1]-1))/2+dp[g[x][i]][j1];
				else sum-=(dp[g[x][i]][j1]*dp[g[x][i]][k-2-j1]);
			}
		}
	}
	f(i,0,g[x].size()){
	if(mark2[g[x][i]]==0) dfs(g[x][i]);}
	ans+=sum;
}
int main(){
	cin>>n>>k;
	f(i,0,n-1){cin>>x>>y;g[x].push_back(y),g[y].push_back(x);}
	dp1(1);
	dfs(1);
	cout<<ans;
}