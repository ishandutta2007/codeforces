#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
int ans,mx2,am2,u,v,mx,am,n,m,d,damage[100009],x,y,dist[100009],mark[100009],mark2[100009];
vector<int> g[100009];
int dfs(int x,int dis){
	mark[x]=1;dist[x]=dis;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0)
			dfs(g[x][i],dis+1);	}
}
int dfs2(int x,int dis){
	mark2[x]=1;
	if(max(dis,dist[x])<=d+1)
		ans++;
	f(i,0,g[x].size()){
		if(mark2[g[x][i]]==0)
			dfs2(g[x][i],dis+1);
	}
}
int main(){
	cin>>n>>m>>d;
	f(i,1,m+1){
		cin>>x;damage[x]=1;}
	f(i,0,n-1){
		cin>>x>>y;g[x].pb(y);g[y].pb(x);}
	dfs(1,1);
	f(i,1,n+1){
		if(dist[i]>mx && damage[i]==1){
			mx=dist[i];
			am=i;}}
	f(i,0,n+2) mark[i]=0;
	dfs(am,1);
	cout<<endl;
	f(i,1,n+1){
		if(dist[i]>mx2 && damage[i]==1){
			mx2=dist[i];
			am2=i;}}
	dfs2(am2,1);
	cout<<ans;
}