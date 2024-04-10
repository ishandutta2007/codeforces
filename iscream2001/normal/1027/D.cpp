#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long 
using namespace std;
const int inf=1e9;
const int N=2e5+10;
int n,top,mx,ans=0;
int c[N],p[N];
int vis[N],cir[N];
int dfs(int x,int y){
	if(vis[x]) return x;
	vis[x]=y;
	return dfs(p[x],y);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&c[i]);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]);
	int u,v;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			u=dfs(i,i);
			if(vis[u]!=i) continue;
		//	cout<<u<<endl;
			if(cir[u]) continue;
			mx=c[u];v=p[u];cir[u]=1;
			while(v!=u){
				//cout<<v<<endl;
				mx=min(mx,c[v]);
				cir[v]=1;
				v=p[v];
			}
			ans+=mx;
		}
	}
	printf("%d\n",ans);
	return 0;
}