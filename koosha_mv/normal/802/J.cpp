#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i<b;i+=2)
int n,x,y,z,mark[1090];
vector <int> g[109];
int dfs(int v){
	mark[v]=1;
	int mx=0;
	f_(i,0,g[v].size()){
		if(mark[g[v][i]]==0)
			mx=max(mx,dfs(g[v][i])+g[v][i+1]);
	}
	return mx;
}
int main(){
	cin>>n;
	f(i,0,n-1){
		cin>>x>>y>>z;
		g[x].push_back(y);
		g[y].push_back(x);
		g[x].push_back(z);
		g[y].push_back(z);
	}
	cout<<dfs(0);
}