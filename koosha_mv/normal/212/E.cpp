#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
int x,y,n,deg[5009],dp[5002][5002],mark[5002][5002],mark1[5005],t;
vector <int> g[5009],g1[5009];
vector <int> l;
int dfs(int asli,int x){
	int ans=0;
	mark[asli][x]=1;
	f(i,0,g[x].size()){
		if(x==asli && mark[asli][g[x][i]]==0){
			g1[asli].push_back(dfs(asli,g[x][i]));}
		if(x!=asli && mark[asli][g[x][i]]==0){
			ans+=dfs(asli,g[x][i]);}}
	return ans+1;}
int main(){
	cin>>n;
	f(i,1,n){
		cin>>x>>y;deg[x]++;deg[y]++;
		g[x].push_back(y);
		g[y].push_back(x);}
	f(i,1,n+1){
		if(deg[i]>1){
		dfs(i,i);
		f(j,0,g1[i].size()){
			f_(k,n-1,0){
				if(k-g1[i][j]>=0 && (dp[i][k-g1[i][j]]==1 || k-g1[i][j]==0)){
					dp[i][k]=1;
					mark1[k]=1;}}}}
	}
	f(i,1,n-1) {if(mark1[i]==1) t++;}
	cout<<t<<endl;
	f(i,1,n-1){
		if(mark1[i]==1)
		 cout<<i<<" "<<n-1-i<<endl;
	}
}