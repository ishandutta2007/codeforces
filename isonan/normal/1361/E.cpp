#include <cstdio>
#include <random>
#include <cassert>
#include <ctime>
#include <set>

int t;
int head[100001],nxt[200001],b[200001],k,n,m;
bool instack[100001],vis[100001];
std::mt19937 rnd(time(0));
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int fa[100001];
bool dfs1(int x){
	instack[x]=vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(!vis[b[i]]){
			fa[b[i]]=x;
			if(!dfs1(b[i]))return 0;
		}
		else if(!instack[b[i]])return 0;
	instack[x]=0;
	return 1;
}
bool ans[100001];
int dfn[100001],mx[100001],now,edg[100001][2];
void add(int x,int y){
	// printf("add %d %d\n",x,y);
	if(!y)return;
	if(!edg[x][0]||dfn[edg[x][0]]>dfn[y])edg[x][1]=edg[x][0],edg[x][0]=y;
	else if(!edg[x][1]||dfn[edg[x][1]]>dfn[y])edg[x][1]=y;
}
void dfs2(int x){
	dfn[x]=++now;
	edg[x][0]=edg[x][1]=0;
	for(int i=head[x];i;i=nxt[i])
		if(fa[b[i]]==x){
			dfs2(b[i]);
			add(x,edg[b[i]][0]);
			add(x,edg[b[i]][1]);
		}
		else add(x,b[i]);
	mx[x]=now;
}
void dfs3(int x){
	int y=edg[x][0];
	if(edg[x][1]&&dfn[edg[x][1]]<dfn[x])y=0;
	// printf("%d %d %d %d %d %d\n",x,y,edg[x][0],edg[x][1],dfn[edg[x][0]],dfn[edg[x][1]]);
	if(!fa[x]||ans[y])ans[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(fa[b[i]]==x)dfs3(b[i]);
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)head[i]=ans[i]=0;
		k=0;
		for(int i=1,u,v;i<=m;++i)scanf("%d%d",&u,&v),push(u,v);
		for(int i=1;i<=200;++i){
			unsigned x=rnd();
			int y=x%n+1;
			for(int i=1;i<=n;++i)vis[i]=instack[i]=fa[i]=0;
			if(dfs1(y)){
				now=0;
				dfs2(y);
				dfs3(y);
				// printf("%d\n",y);
				break;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;++i)cnt+=(ans[i]!=0);
		if(cnt*5<n)puts("-1");
		else{
			for(int i=1;i<=n;++i)if(ans[i])printf("%d ",i);putchar('\n');
		}
	}
}