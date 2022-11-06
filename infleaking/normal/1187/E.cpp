#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll f[N],g[N],size[N],ans;
int w[N*2],ne[N*2],la[N],t,n;
void link(int x,int y){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
}
void dfs1(int x,int fa){
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa)continue;
		dfs1(z,x);
		size[x]+=size[z];
		f[x]+=f[z];
	}f[x]+=++size[x];
}
void dfs2(int x,int fa){
	g[x]=g[fa]+f[fa]-f[x]+(n-size[x])-size[fa];
	if (x==1)g[1]=0;
	ans=max(ans,f[x]+g[x]-size[x]+n);
	for (int y=la[x];y;y=ne[y])
		if (w[y]!=fa)dfs2(w[y],x);
}
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y);
		link(y,x);
	}
	dfs1(1,0);
	dfs2(1,0);
	cout<<ans<<endl;
}