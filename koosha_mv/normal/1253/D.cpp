#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
int ans,n,m,x,y,mxd=0,mark[300009];
vector<int> g[200009];
int dfs(int x){
	mark[x]=1;
	mxd=max(mxd,x);
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==0){
			dfs(g[x][i]);
		}
	}
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);}
	f(i,1,n+1){
		if(!(mark[i])){
			if(i<mxd)ans++;
			dfs(i);
		}
	}
	cout<<ans;
}