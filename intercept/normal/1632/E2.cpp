#include<bits/stdc++.h>
using namespace std;
const int M=3e5+9;
int n,f[M];
vector<int>g[M];
int dfs(int u,int fa,int dep){
	int a=dep,b=dep;
	for(auto v:g[u]){
		if(v!=fa){
			int c=dfs(v,u,dep+1);
			if(c>=a)b=a,a=c;
			else if(c>b)b=c;
		}
	}
	int x=min(a,b);
	f[x]=max(f[x],a+b-dep-dep);
	return a;
}
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)g[i].clear(),f[i]=0;
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	int ans=dfs(1,0,0),x=1;
	for(int i=n-1;i>=1;--i)f[i]=max(f[i],f[i+1]);
	for(int i=1;i<=n;++i){
		while(x<ans&&(f[x+1]+1>>1)+i>x)x++;
		printf("%d%c",x," \n"[i==n]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}