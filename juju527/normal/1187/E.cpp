#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
struct Edge{
	int to,nxt;
}e[2*maxn];
int cnt;
int head[maxn];
int n;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
int f[maxn],siz[maxn];
void dfs1(int x,int fa){
	siz[x]=1;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs1(tmp,x);
		siz[x]+=siz[tmp];
		f[x]+=f[tmp];
	}
	f[x]+=siz[x];
	return ;
}
int g[maxn];
void dfs2(int x,int fa){
	if(x>1)g[x]=g[fa]-siz[x]-f[x]+f[x]-siz[x]+n;
	else g[x]=f[x];
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs2(tmp,x);
	}
	return ;
}
signed main(){
	n=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,g[i]);
	printf("%lld\n",ans);
	return 0;
}