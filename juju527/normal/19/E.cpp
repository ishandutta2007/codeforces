#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+5,maxm=1e+5;
struct Edge{int to,nxt;}e[2*maxm];
int cnt;
int head[maxn];
bool ban[2*maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v){
	e[cnt]=(Edge){v,head[u]};
	head[u]=cnt++;
	return ;
}
int dep[maxn],f[maxn],s[maxn],t[maxn],ed[maxn];
bool vis[maxn];
void dfs(int x,int fa){
	vis[x]=1;
	dep[x]=dep[fa]+1;f[x]=fa;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(vis[tmp])continue;
		ban[i]=ban[i^1]=1;ed[tmp]=i;
		dfs(tmp,x);
	}
	return ;
}
void dfs1(int x,int fa){
	vis[x]=1;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(vis[tmp])continue;
		dfs1(tmp,x);
		s[x]+=s[tmp],t[x]+=t[tmp];
	}
	return ;
}
bool isrt[maxn];
int res[maxm];
int main(){
    int n,m;
	n=read();m=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();v=read();
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
	int num=0,id;
	for(int i=0;i<cnt;i+=2){
		if(ban[i])continue;
		int u=e[i].to,v=e[i^1].to;
		if(dep[u]<dep[v])swap(u,v);
		if((dep[u]-dep[v])&1)s[u]++,s[v]--;
		else t[u]++,t[v]--,num++,id=(i>>1)+1;
	}
	if(num==0){
		printf("%d\n",m);
		for(int i=1;i<=m;i++)printf("%d ",i);
		puts("");
		return 0;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)if(!vis[i])dfs1(i,0),isrt[i]=1;
	int len=0;if(num==1)res[++len]=id;
	for(int i=1;i<=n;i++)if(!isrt[i]&&t[i]==num&&s[i]==0)res[++len]=(ed[i]>>1)+1;
	sort(res+1,res+len+1);
	printf("%d\n",len);
	for(int i=1;i<=len;i++)printf("%d ",res[i]);
    return 0;
}