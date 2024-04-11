#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll n,x,y,dg1,verd[200009],mark2[200009],mark1[200009],mark3[200009],deg[200009],dis=0,mxd=0;
vector<ll> g[200009];
void dfs(ll x,ll y){
	mark1[x]=1;
	dis+=y;
	f(i,0,g[x].size()){
		if(mark1[g[x][i]]!=1)
			dfs(g[x][i],y+1);
	}
}
ll dp(ll x){
	mark2[x]=1;
	f(i,0,g[x].size()){
		if(mark2[g[x][i]]!=1)
			verd[x]+=dp(g[x][i]);
	}
	verd[x]++;
	return verd[x];
}
ll dfs2(ll x,ll d){
	mxd=max(mxd,d);
	mark3[x]=1;
	f(i,0,g[x].size()){
		if(mark3[g[x][i]]==0)
			dfs2(g[x][i],d+n-(verd[g[x][i]]*2));
	}
}
int main(){
	cin>>n;
	f(i,0,n-1){
		cin>>x>>y;
		deg[x]++,deg[y]++;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	f(i,1,n+1){
		if(deg[i]==1){
			dg1=i;
			break;
		}
	}
	dfs(dg1,0);
	dp(dg1);
	dfs2(dg1,dis);
	cout<<mxd+n;
}